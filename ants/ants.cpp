#include <bits/stdc++.h>

using namespace std;
long long n,t,h[100007],d[100007],par[100007][18],lca;
vector <long> adj[100007];
vector <long> w[100007];

void dfs(long long u)
{
  for (long i = 0; i < adj[u].size(); i++)
    {
        long long v=adj[u][i];
        if (v!=par[u][0])
        {
            par[v][0]=u; h[v]=h[u]+1; d[v]=d[u]+w[u][i];
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
    cin.tie(0);
    cout.tie(0);
    freopen("ants.inp","r",stdin);
    freopen("ants.out","w",stdout);
    while (1<2)
    {
        n=0;
       cin >> n;
       if (n==0) break;
       for (long i=0;i<=n;i++) adj[i].clear();
       for (long i=0;i<=n;i++) w[i].clear();
       memset(d,0,sizeof(d));
           memset(h,0,sizeof(h));
           memset(par,0,sizeof(par));
       for (long i=1;i<=n-1;i++)
       {
           long u,c;
           cin >> u >> c;
           adj[i].push_back(u);
           w[i].push_back(c);
           adj[u].push_back(i);
           w[u].push_back(c);
       }
       dfs(0);
       t=0;
       cin >> t;
       if (t==0) break;
       for (long l=1; l<=t; l++)
       {
           long u,v;
           cin >> u >> v;
           lca=LCAs(u,v);
           //cout<<lca<<" "<<d[v]<<" " << d[u];
           //cout << lca << endl;
           //for (long i=1; i<=n-1;i++)
           long long res=d[u]+d[v];
           res=res-2*d[lca];
           cout << res << " ";
       }
       cout << endl;
    }
}
