#include <bits/stdc++.h>
#define nmax 100007
using namespace std;

long n,m,h[nmax],par[nmax][20];
vector <long> adj[nmax];

void dfs(long u)
{
  for (long i = 0; i < adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (v!=par[u][0])
        {
            par[v][0]=u; h[v]=h[u]+1;
            for (long j=1; j<=17; j++)
                par[v][j]=par[par[v][j-1]][j-1];
            dfs(v);
        }
    }
}

long LCAs(long u, long v)
{
    if (h[u]<h[v]) swap(u,v);
    long del=h[u]-h[v];
    for (long i=0; i<=17; i++)
        if ((del >> i )& 1) u=par[u][i];
    if (u==v) return u;

    for (long i=17; i>=0 ; i--)
        if (par[u][i]!=par[v][i])
    {
        u=par[u][i];
        v=par[v][i];
    }
    return par[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PEACE.inp","r",stdin);
    freopen("PEACE.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n-1; i++)
     {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
    for (long i=1; i<=m; i++)
    {
        long aa,bb,cc;
        cin >> aa >> bb >> cc;
        memset(h,0,sizeof(h));
        memset(par,0,sizeof(par));
        dfs(cc);
        cout << LCAs(bb,aa) << endl;
    }
}
