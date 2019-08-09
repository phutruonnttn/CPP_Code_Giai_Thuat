#include <bits/stdc++.h>
#define nmax 100007
using namespace std;
typedef pair <long, long> ii;

long n,m,d[nmax],tr[nmax];
vector <ii> adj[nmax];

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
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PEACE.inp","r",stdin);
    freopen("PEACE.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n-1; i++)
     {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(ii(v,1));
        adj[v].push_back(ii(u,1));
     }
    for (long i=1; i<=m; i++)
    {
        long a,b,c;
        cin >> a >> b >> c;
        dijkstra(b);
        long tv=c,truyvet[nmax],dtv=0;
        while (tv!=b)
        {
            truyvet[++dtv]=tv;
            tv=tr[tv];
        }
        truyvet[++dtv]=b;

        dijkstra(a);
        long long ans=10000000000,vt;
        for (long j=1; j<=dtv; j++)
          if (ans>d[truyvet[j]])
            {
               ans=d[truyvet[j]];
               vt=truyvet[j];
            }
        cout << vt << endl;
    }
}
