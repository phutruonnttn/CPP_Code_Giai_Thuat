#include <bits/stdc++.h>
#define nmax 307
#define vc 999999999999

using namespace std;
typedef pair <long,long> ii;

long long n,m,k,d[nmax],dd[nmax];
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
        if (dd[u]==0) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (dd[v]==1)
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
    freopen("DWLABYR.inp","r",stdin);
    freopen("DWLABYR.out","w",stdout);
    cin >> n >> m >> k;
    for (long i=1; i<=m; i++)
     {
         long long u,v,w;
         cin >> u >> v >> w;
         a[u].push_back(ii(v,w));
     }
    for (long i=1; i<=k; i++)
    {
        char s;
        long u,v;
        cin >> s >> u;
        if (s=='X') dd[u]=1;
        else
        {
            cin >> v;
            if (dd[u]==0 || dd[v]==0) cout << -1 << '\n';
            else
            {
                dijkstra(u);
                if (d[v]==vc) cout << -1 << '\n';
                else cout << d[v] << '\n';
            }
        }
    }
}
