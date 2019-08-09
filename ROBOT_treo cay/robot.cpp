#include <bits/stdc++.h>
#define nmax 300007
#define vc 9999999999

using namespace std;
typedef pair <long long,long long> ii;

vector <ii> a[nmax];
long long n,m,x,h[nmax],d[nmax],dd[nmax],ans=vc;

/*void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n+1,vc);
    d[1]=0;
    pq.push(ii(0,1));

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
}*/

void dfs(long u,long cur,long long time)
{
    //dd[u]=1;
    if (u==n) ans=min(ans,time);
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i].first;
        long wv=a[u][i].second;
        if (dd[v]==0)
        {
            long nhay=cur-wv;
            if (nhay>=0 && nhay<=h[v])
            {
                dd[v]=1;
                dfs(v,nhay,time+wv);
                dd[v]=0;
            }
            else
            if (nhay<0 && cur+abs(nhay)<=h[u])
            {
                dd[v]=1;
                dfs(v,0,time+wv+abs(nhay));
                dd[v]=0;
            }
            else if (nhay>h[v] && cur-(nhay-h[v])>=0)
            {
                dd[v]=1;
                dfs(v,h[v],time+wv+(nhay-h[v]));
                dd[v]=0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    cin >> n >> m >> x;
    for (long i=1; i<=n; i++) cin >> h[i];
    for (long i=1; i<=m; i++)
    {
        long long u,v,w;
        cin>> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    //dijkstra();
    dd[1]=1;
    dfs(1,x,0);
    if (ans==vc) cout << -1;
    else cout << ans;
}
