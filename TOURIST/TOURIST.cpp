#include <bits/stdc++.h>

using namespace std;
typedef pair <long long,long long> ii;

long long n,m,nv[100007],d[100007],tr[100007],ans=-1,kq[100007],skq;
bool dd[100007];
vector <ii> a[100007];

void dijkstra(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e18);
    memset(dd,true,sizeof(dd));
    d[uu]=0;
    pq.push(ii(0,uu));

    long long u,du,bac[100007];bac[uu]=1;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        if(bac[u]<4)
        for (long i=0;i<a[u].size();i++)
        {
            long long v=a[u][i].first;
            if (dd[v]==true)
            {
                dd[v]=false;
                long long wv=a[u][i].second;
                if (d[v]>d[u]+wv)
                   {
                      d[v]=d[u]+wv;
                      tr[v]=u;
                      bac[v]=bac[u]+1;
                      pq.push(ii(-d[v],v));
                   }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TOURIST.inp","r",stdin);
    freopen("TOURIST.out","w",stdout);
    cin >> n >>m;
    for (long i=1; i<=n; i++) cin >> nv[i];
    for (long i=1; i<=m;i++)
    {
        long long u,v;
        cin >> u >> v;
        a[u].push_back(ii(v,-nv[v]));
        a[v].push_back(ii(u,-nv[u]));
    }

    for (long i=1; i<=n; i++)
    {
        dijkstra(i);
        for (long j=1; j<=n; j++)
          if (d[j]!=1e18 && i!=j)
           {
              if (-d[j]+nv[i]>ans)
              {
                  ans=-d[j]+nv[i];
                  long kk=j,dem=0;
                  while (kk!=i)
                  {
                      kq[++dem]=kk;
                      kk=tr[kk];
                  }
                  kq[++dem]=i;
                  skq=dem;
                  /*cout << ans << ":  ";
                  for (long i=skq; i>=1; i--) cout << kq[i] << " "; cout << endl;*/
              }
           }
    }

    cout << skq << endl;
    for (long i=skq; i>=1; i--) cout << kq[i] << " ";
}
