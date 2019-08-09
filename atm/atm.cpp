#include <bits/stdc++.h>

using namespace std;
long long n,r,l,m,f[100007],bac[100007],q[100007],a[100007],s,p;
long long dt[100007];
vector <long> adj[100007];
int main()
{
    freopen("atm.inp","r",stdin);
    freopen("atm.out","w",stdout);
    memset(bac,0,sizeof(bac));
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        bac[v]++;
    }
    for (long i=1; i<=n; i++) cin >> a[i];

    cin >> s >> p;
    for (long i=1; i<=p; i++) cin >> dt[i];

  r=0;
  q[++r]=s;
  for (long i=1; i<=n; i++)
  {
    f[i]=0;
    if (bac[i]==0)
    {
        q[++r]=i;
    }
  }
  f[s]=a[s];
  long l=1;
  while (l<=r)
  {
        long u=q[l++];
        for (long i=0;i<adj[u].size();i++)
        {
            long v=adj[u][i];
            f[v]=max(f[v],f[u]+a[v]);
            --bac[v];
            if ((bac[v]==0) || (bac[v]==-1)) q[++r]=v;
        }
  }

    long long kq=0;
    for (long i=1; i<=p; i++)
        kq=max(kq,f[dt[i]]);
    cout << kq;
}
