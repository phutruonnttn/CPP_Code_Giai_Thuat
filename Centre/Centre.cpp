#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

long long n,m,d1[30007],d2[30007],sl1[30007],sl2[30007],ans=0,kq[30007];
vector <ii> adj[30007];

void dijkstra1()
{
    priority_queue <ii> pq;
    fill(d1,d1+n+1,1e10);
    d1[1]=0;
    pq.push(ii(0,1));
    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d1[u]) continue;
        for (long i=0; i<adj[u].size(); i++)
        {
            long v=adj[u][i].first;
            long wv=adj[u][i].second;
            if (d1[v]==d1[u]+wv) sl1[v]+=sl1[u];
            if (d1[v]>d1[u]+wv)
            {
                d1[v]=d1[u]+wv;
                sl1[v]=sl1[u];
                pq.push(ii(-d1[v],v));
            }
        }
    }
}

void dijkstra2()
{
    priority_queue <ii> p1q;
    fill(d2,d2+n+1,1e10);
    d2[n]=0;
    p1q.push(ii(0,n));
    long u,du;
    while (!p1q.empty())
    {
        u=p1q.top().second;
        du=-p1q.top().first;
        p1q.pop();
        if (du!=d2[u]) continue;
        for (long i=0; i<adj[u].size(); i++)
        {
            long v=adj[u][i].first;
            long wv=adj[u][i].second;
            if (d2[v]==d2[u]+wv) sl2[v]+=sl2[u];
            if (d2[v]>d2[u]+wv)
            {
                d2[v]=d2[u]+wv;
                sl2[v]=sl2[u];
                p1q.push(ii(-d2[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CENTRE28.inp","r",stdin);
    freopen("CENTRE28.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(ii(v,w));
        adj[v].push_back(ii(u,w));
    }
    memset(sl1,0,sizeof(sl1));
    memset(sl1,0,sizeof(sl1));
    sl1[1]=1; sl2[n]=1;
    dijkstra1(); dijkstra2();

    for (long i=1; i<=n; i++)
    {
        if (d1[i]+d2[i]!=d1[n] || sl1[i]*sl2[i]!=sl1[n]) kq[++ans]=i;
    }
    cout << ans << endl;
    for (long i=1; i<=ans; i++) cout << kq[i] << endl;
}
