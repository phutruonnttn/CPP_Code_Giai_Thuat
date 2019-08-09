#include <bits/stdc++.h>
#define nmax 5*100007
#define vc 9999999999

using namespace std;
typedef pair <int,int> ii;

vector <ii> a[nmax];
long long n,m,d[nmax],u[nmax],v[nmax];

void dijkstra()
{
    priority_queue <ii> pq;
    //fill(d,d+n+1,vc);
    d[1]=0;
    pq.push(ii(0,1));

    long u,du;
    while (!pq.empty())
    {
        if (d[n]!=vc) return;
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
                if (v==n) return;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

bool kt(long pp)
{
    for (long i=1; i<=n; i++)
      {a[i].clear(); d[i]=vc;}
    for (long i=1; i<=pp; i++) a[u[i]].push_back(ii(v[i],1));
    dijkstra();
    if (d[n]!=vc) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("comnet.inp","r",stdin);
    freopen("comnet.out","w",stdout);
    //cin >> n >> m;
    scanf("%lld%lld",&n,&m);
    for (long i=1; i<=m; i++) scanf("%lld%lld",&u[i],&v[i]);
    long long l=0,r=m,ans=-1;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    /*dd[1]=1;
    dfs(1,-1);*/
    //cout << l << " " << r;
    printf("%lld",ans);
}
