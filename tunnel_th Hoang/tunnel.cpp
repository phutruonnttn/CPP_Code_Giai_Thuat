#include <bits/stdc++.h>
#define nmax 5*100007
#define vc 9999999999999999

using namespace std;
typedef pair <long long,long long> ii;
typedef pair <ii, long long> ii1;

long long n,m,x,y,tr[nmax];
long long d[nmax],rb;
bool dd[nmax];
vector <ii1> a[nmax];

void dijkstra(long long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,vc);
    d[uu]=0;
    pq.push(ii(0,uu));

    long long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        dd[u]=false;
        for (long i=0;i<a[u].size();i++)
        {
            long long v=a[u][i].first.first;
            long long wv=a[u][i].second;
            long long hv=a[u][i].first.second;
            if (d[v]>d[u]+wv && hv>=rb)
            {
                d[v]=d[u]+wv;
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

bool kt(long long g)
{
    rb=g;
    memset(dd,true,sizeof(dd));
    dijkstra(x);
    if (d[y]!=vc) return true;
    return false;
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
        a[u].push_back(ii1(ii(v,uu),vv));
        a[v].push_back(ii1(ii(u,uu),vv));
    }

    long long l=1, r=1000000001, tve=0;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            tve=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    kt(tve);
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
