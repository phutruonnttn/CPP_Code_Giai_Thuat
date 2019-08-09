#include <bits/stdc++.h>

using namespace std;
typedef pair <long, double> ii;
typedef pair <double, long> ii1;
long n,m,x,y,tr[500007];
long long d[500007];
bool dd[500007];
vector <ii> a[100007];

void dijkstra(long uu)
{
    priority_queue <ii1> pq;
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
        dd[u]=false;
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (dd[v])
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
    freopen("TUNNEL.inp","r",stdin);
    freopen("TUNNEL.out","w",stdout);
    cin >> n >> m >> x >> y;
    for (long i=1; i<=m; i++)
    {
        long u,v,uu,vv;
        cin >> u >> v >> uu >> vv;
        double ts=uu-vv;
        a[u].push_back(ii(v,ts));
        a[v].push_back(ii(u,ts));
    }
    memset(dd,true,sizeof(dd));
    dijkstra(x);
    long long ans=0,kq[100007];
    while (y!=x)
    {
        kq[++ans]=y;
        y=tr[y];
    }
    kq[++ans]=x;
    cout << ans << endl;
    for (long i=ans; i>=1; i--)
        cout << kq[i] << " ";
}
