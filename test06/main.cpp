#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long , long> ii;

long n,m,d[nmax],tr[nmax],sl[nmax];
vector <ii> a[nmax];

void dijkstra(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[uu]=0;
    pq.push(ii(0,uu));
    memset(sl,0,sizeof(sl));
    sl[uu]=1;
    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0; i<a[u].size(); i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (d[v]==d[u]+wv) sl[v]+=sl[u];
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                tr[v]=u;
                sl[v]=sl[u];
                pq.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("test06.inp","r",stdin);
    freopen("test06.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    dijkstra(1);
    cout << d[n];
}
