#include <bits/stdc++.h>

using namespace std;
long m,n,k,h[100007],par[10007][20];
vector <long> adj[100007];

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
    freopen("HBTLCA.inp","r",stdin);
    freopen("HBTLCA.out","w",stdout);
    while (1<2)
    {
    cin >> n; if (n==0) break;
    for (long i=1; i<=n-1; i++ )
     {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
    dfs(1);
    cin >> m;
    for (long ll=1; ll<=m; ll++)
    {
        char s; cin >> s;
        if (s=='?')
        {
            long u,v;
            cin >> u >> v;
            cout << LCAs(u,v) << endl;
        }
        else
        {
            cin >> k;
            for (long i=0;i<=n; i++) h[i]=0;
            for (long i=0;i<=n; i++)
               for (long j=0; j<=18; j++)
                 par[i][j]=0;
            dfs(k);
        }
    }
    }
}
