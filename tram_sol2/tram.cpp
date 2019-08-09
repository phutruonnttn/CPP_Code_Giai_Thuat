#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

long m,n,k,h[100007],par[100007][20],root[100007],dem[100007],ans=0;
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

long get_root(long u)
{
    return (root[u]) ? root[u] = get_root(root[u]) : u;
}

void danhdau(long u, long p)
{
    long r = get_root(p); //cout << "r:" << r << endl;
    u = get_root(u); //cout << "get root u :" << u << endl;
    while (h[u] > h[r])
     {
        root[u] = r; //cout << "root["<<u<<"]=" <<r << endl;
        //cout << "par[u][0]=" << par[u][0] << endl;
        u = get_root(par[u][0]); //cout << u<<endl;
     }
    //cout << endl;
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
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        long p=LCAs(u,v);
        //cout << p;
        danhdau(u,p);
        danhdau(v,p);
    }
    for (long i=1; i<=n; i++) if (root[i]==0) ans++; //cout << i << " ";
    cout << ans-1;
}
