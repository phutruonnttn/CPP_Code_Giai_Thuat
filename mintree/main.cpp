#include <bits/stdc++.h>
#define nmax 100007
using namespace std;
long n,m,d[nmax];
vector <long> adj[nmax];
vector <long long> w[nmax];
bool fr[nmax];

int main()
{
    freopen("mintree.inp","r",stdin);
    freopen("mintree.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m;i++)
    {
        long u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u].push_back(c);
        w[v].push_back(c);
    }
    memset(fr,true,sizeof(fr));
    memset(d,60,sizeof(d));
    d[1]=0;
    priority_queue < pair<int, int> > q;
    q.push(make_pair(0,1));
    while (!q.empty())
    {
        long u=q.top().second;
        if (d[u]<q.top().first) continue;
        fr[u]=false;
        for (int i = 0; i < adj[u].size(); i++)
        {
            long v=adj[u][i];
             if (free[v])
                if (d[v]>w[u][i])
                {
                    d[v]=w[u][i];
                    q.push(make_pair(-d[v],v));
                }
        }
    }
    long res=accumulate(d,d+n,0);
    cout << res;
}
