#include <bits/stdc++.h>

using namespace std;
long n,m,r,bac[100007],f[100007],q[100007];
vector <long> adj[100007],w[100007];
int main()
{
  freopen("maxpdag.inp","r",stdin);
  freopen("maxpdag.out","w",stdout);
  memset(bac,0,sizeof(bac));
  cin >> n >> m;
  for (long i=1; i<=m; i++)
  {
      long u,v,c;
      cin >> u >> v >> c;
      adj[u].push_back(v);
      w[u].push_back(c);
      bac[v]++;
  }
  r=0;

  for (long i=1; i<=n; i++)
  {
    f[i]=0;
    if (bac[i]==0)
    {
        q[++r]=i;
        f[i]=0;
    }
  }

  long l=1;
  while (l<=r)
  {
    long u=q[l++];
        for (long i=0;i<adj[u].size();i++)
        {
            long v=adj[u][i];
            long c=w[u][i];
            f[v]=max(f[v],f[u]+c);
            if (--bac[v]==0) q[++r]=v;
        }
  }
  long kq=0;
  for (long i=1; i<=n; i++)
    kq=max(kq,f[i]);
  cout << kq;
}
