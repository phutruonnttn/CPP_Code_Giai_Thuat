#include <bits/stdc++.h>

using namespace std;

long n,c[20][20],f[70000][20];


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Lem3.inp","r",stdin);
    freopen("Lem3.out","w",stdout);
    cin >>n;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        cin >> c[i][j];

    for (long i=0;i<=(1<<n)-1;i++)
      for (long j=1; j<=n; j++)
       f[i][j]=1000000000;

    //f[1][1]=0;
    for (long i=0; i<=n-1;i++)
        f[1<<i][i+1]=0;

    for (long i=0; i<=(1<<n)-1; i++)
        for (long j=1; j<=n; j++)
          if (f[i][j]>=0)
             {
                 for (long k=1; k<=n; k++)
                    if (k!=j)
                     {
                        long x=(i | (1<<(k-1)));
                        if (((i>>(k-1)) & 1)==0) f[x][k]=min(f[x][k],c[j][k]+f[i][j]);
                     }
             }
      long ans=1000000000;
      for (long i=1; i<=n; i++)
        if ( ans>f[(1<<n)-1][i] && f[(1<<n)-1][i]>=0 ) ans=f[(1<<n)-1][i];
      cout << ans;
}
