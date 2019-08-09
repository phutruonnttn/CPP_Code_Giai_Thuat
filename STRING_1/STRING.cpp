#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;
typedef pair <long long,long long> ii;

long long n,ks,d[2007],sl[2007];
vector <ii> a[2007];
string s[2007];

void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e10);
    d[1]=0;
    pq.push(ii(0,1));

    long long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (d[v]==d[u]+wv) sl[v]=(sl[v]+sl[u]) % nmod;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                sl[v]=sl[u];
                pq.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STRING.inp","r",stdin);
    freopen("STRING.out","w",stdout);
    cin >> n >> ks;
    for (long i=1; i<=n+2; i++)
        cin >> s[i];
ks=s[1].size();
    if (s[1]==s[2])
    {
        cout << 0 << " " << 1;
        return 0;
    }

    for (long i=1; i<=n+1; i++)
      for (long j=i+1; j<=n+2; j++)
        {
           long dem=0;
           for (long k=0; k<ks; k++)
             if (s[i][k]!=s[j][k]) dem++;
           if (dem==1)
           {
               a[i].push_back(ii(j,1));
               a[j].push_back(ii(i,1));
           }
        }
    memset(sl,0,sizeof(sl));
    sl[1]=1;
    n=n+2;
    dijkstra();
    if (d[2]==10000000000) cout << -1 << " " << -1;
    else cout << d[2] << " " << sl[2];
}
