#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long long m,n,a[nmax][nmax],f[nmax][nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NETPATH.inp","r",stdin);
    freopen("NETPATH.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
        cin >> a[i][j];

    for (long i=1; i<=m; i++) f[i][1]=1;

    for (long i=2; i<=m; i++)
      for (long j=1; j<=i-1; j++)
        if (__gcd(a[j][1],a[i][1])>1) f[i][1]+=f[j][1];

    for(long i=1; i<=m; i++)
     for (long j=2; j<=n; j++)
      for (long u=1; u<=i; u++)
        for (long v=1; v<=j; v++)
          if (i+j!=u+v && v!=n && __gcd(a[u][v],a[i][j])>1)
            f[i][j]+=f[u][v];
    long long ans=0;
    for (long i=1; i<=m; i++) ans+=f[i][n];
    cout << ans;
}
