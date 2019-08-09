#include <bits/stdc++.h>

using namespace std;

long long m,n,a[507][507],f[507][507],maxf[507][507][507],ans=-111111111111111111;

long long tong(long h1, long c1, long h2, long c2)
{
    return f[h2][c2]-f[h2][c1-1]-f[h1-1][c2]+f[h1-1][c1-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
       for (long j=1; j<=n; j++)
        {
           cin >> a[i][j];
           f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
        }

    for (long h1=1; h1<=m; h1++)
     for (long h2=h1; h2<=m; h2++)
      for (long c=n; c>=1; c--)
         maxf[h1][h2][c]=max(maxf[h1][h2][c+1],tong(h1,1,h2,c));

    for (long h1=1; h1<=m; h1++)
      for (long h2=1; h2<=m; h2++)
        for (long c1=1; c1<=n; c1++)
          ans=max(ans,maxf[h1][h2][c1]-tong(h1,1,h2,c1-1));
    cout << ans;
}
