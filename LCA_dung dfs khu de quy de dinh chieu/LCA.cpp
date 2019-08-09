#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
long m,n,k,h[100007],par[100007][20],h0,cl[nmax],cur[nmax],dd[nmax],s[nmax];
vector <long> adj[100007];

/*void dfs(long u)
{
  //tinh h(chieu cao) cua tung nut, va par[u][i] la nut cha 2^i cua u
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
}*/

void dfs(int xp)
{
    for (long i=1; i<=n; i++) dd[i]=cur[i]=0;
    long sn=0,id=0;
    dd[xp]=1;
    s[++sn]=xp;
    h[xp]=0;
    par[xp][0]=0;
    while (sn)
    {
        long u=s[sn];
        if (cur[u]<adj[u].size())
        {
            long v=adj[u][cur[u]++];
            if (dd[v]==0)
            {
                dd[v]=1;
                s[++sn]=v;
                h[v]=h[u]+1;
                par[v][0]=u;
            }
        }
        else sn--;
    }
    for (long k=1; k<=17; k++)
      for (long u=1; u<=n; u++)
        par[u][k]=par[par[u][k-1]][k-1];
}

long LCAs(long u, long v)
{
    //nhay 2 nut ve cun do cao
    if (h[u]<h[v]) swap(u,v);
    long del=h[u]-h[v];
    for (long i=0; i<=17; i++)
        if ((del >> i )& 1) u=par[u][i];
    if (u==v) return u;

    //nhay len dan,neu gap 2 nut cung nhau thi ko nhay, khac nhau moi nhay
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
    freopen("LCA.inp","r",stdin);
    freopen("LCA.out","w",stdout);
    cin >> n >> k >> m;
    //h0=log2(n);
    for (long i=1; i<=n-1; i++ )
     {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
    dfs(k);
    for (long l=1; l<=m; l++)
    {
        long u,v;
        cin >> u >> v;
        cout << LCAs(u,v) << endl;
    }
}
