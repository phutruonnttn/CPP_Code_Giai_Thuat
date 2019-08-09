#include <bits/stdc++.h>

using namespace std;
typedef pair <long, long> ii;

vector <ii> adj[1007];
long n,a[1007],d[5007],dd[1007][1007];

void dijkstra(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[uu]=0;
    pq.push(ii(0,uu));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<adj[u].size();i++)
        {
            long v=adj[u][i].first;
            long wv=adj[u][i].second;
               if (d[v]>d[u]+wv)
                {
                  d[v]=d[u]+wv;
                  pq.push(ii(-d[v],v));
                }
            }
        }
    }

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKJUMP.inp","r",stdin);
    freopen("NKJUMP.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);

    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        for (long k=1; k<=n; k++)
          if (i!=j && j!=k && a[i]+a[j]==a[k])
             {
                 adj[i].push_back(ii(k,-1));
                 adj[j].push_back(ii(k,-1));
             }
    long ans=100;
    for (long i=1; i<=n; i++)
    {
       dijkstra(1);
       for (long j=1; j<=n; j++) ans=min(ans,d[j]);
    }
    cout << -ans+1;
}
