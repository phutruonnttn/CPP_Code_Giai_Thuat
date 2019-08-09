#include <bits/stdc++.h>

using namespace std;
long long n,r,l,m,f[100007],bac[100007],q[100007];
vector <long> adj[100007];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cpdag.inp","r",stdin);
    freopen("cpdag.out","w",stdout);
    memset(bac,0,sizeof(bac));
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        bac[v]++;
    }
    r=0;
    for (long i=1; i<=n; i++)
  {
    f[i]=0;
    if (bac[i]==0)
    {
        q[++r]=i;
    }
  }
  long long l=1;
  while (l<=r)
  {
        long u=q[l++];
        for (long j=0;j<adj[u].size();j++)
    {
        long v=adj[u][j];
        f[v]=((f[v]+f[u]+1) % 1000000007);
        if (--bac[v]==0) q[++r]=v;
    }
  }
    long long kq=0;
    for (long i=1; i<=n; i++)
        kq=((kq+f[i]) % 1000000007);
    cout << kq;
}
