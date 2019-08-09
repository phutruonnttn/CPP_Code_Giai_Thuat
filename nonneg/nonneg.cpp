#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

vector <ii> a[25007];
long n,m,p,s,d[25007];

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
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
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
    freopen("nonneg.inp","r",stdin);
    freopen("nonneg.out","w",stdout);
    cin >> n >> m >> p >> s;
    for (long i=1; i<=m; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    for (long i=1; i<=p; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
    }
    dijkstra(s);
    for (long i=1; i<=n; i++)
    {
        if (d[i]==1e9) cout << "NO PATH" << '\n';
        else cout << d[i] << '\n';
    }
}
