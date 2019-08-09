#include <bits/stdc++.h>
#define nmax 5007
#define vc 9999999999
#define nmod 1000000007
#define gi(x) if(x>=nmod) x = x - nmod

using namespace std;
typedef pair <long, long> ii;

long long n,m,u[nmax],v[nmax],dem[nmax][nmax],d[nmax],to[nmax],from[nmax];
vector <ii> a[nmax];

void dijkstra(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,vc);
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
    freopen("PATHS.inp","r",stdin);
    freopen("PATHS.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long w;
        cin >> u[i] >> v[i] >> w;
        a[u[i]].push_back(ii(v[i],w));
    }
    for (long i=1; i<=n; i++) dijkstra(i);
    for (long i=1; i<=m; i++) cout << dem[u[i]][v[i]] << '\n';
}
