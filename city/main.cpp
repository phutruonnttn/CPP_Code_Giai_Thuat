#include <bits/stdc++.h>

using namespace std;

long n,m,k;
bool dd[1007];
vector <long> adj[1007];

void dfs(long u)
{
    dd[u]=false;
    for (long i=0; i< adj[u].size();i++)
    {
        long v=adj[u][i];
        if (dd[v]) dfs(v);
    }
}

int main()
{
    freopen("city.inp","r",stdin);
    freopen("city.out","w",stdout);
    cin >> n >> m >> k;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dd,true,sizeof(dd));
    dfs(k); long kq=0;
    for (long i=1; i<=n; i++)
      if (!dd[i]) kq++;
     cout << kq-1;
}
