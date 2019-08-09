#include <bits/stdc++.h>

using namespace std;

long m,n,k,h[100007],par[100007][20],in[100007],out[100007],ans=0;
bool dd[100007];
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

long DFS_2(long u)
{
    long num = in[u] - out[u];
    dd[u]=true;
    for (long i = 0; i < adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (!dd[v]) num+=DFS_2(v);
    }
    ans += (u != 1) && (num == 0);
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("tram.inp","r",stdin);
    freopen("tram.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n-1; i++ )
     {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
    dfs(1);
    cin >> m;
    memset(dd,false,sizeof(dd));
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        long p=LCAs(u,v);
        in[p]+=2;
        out[u]+=1;
        out[v]+=1;
    }
    long k=DFS_2(1);
    cout << ans;
}
