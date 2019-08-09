#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

long long n,m,q,c[nmax][nmax],f[nmax][nmax][5];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STMERGE.inp","r",stdin);
    freopen("STMERGE.out","w",stdout);
    cin >> q;
    while (q--)
    {
        cin >> m >> n;
        for (long i=1; i<=m; i++)
          for (long j=1; j<=n; j++)
             cin >> c[i][j];
        f[1][1][0]=c[1][1];
        f[1][1][1]=c[1][1];
        for (long i=2; i<=m; i++)
        {
            f[i][1][0]=min(f[i-1][1][0],f[i-1][1][1]+c[i][1]);
            f[i][1][1]=c[i][1];
        }
        for (long i=2; i<=n; i++)
        {
            f[1][i][1]=min(f[1][i-1][1],f[1][i-1][0]+c[1][i]);
            f[1][i][0]=c[1][i];
        }
        for (long i=2; i<=m; i++)
          for (long j=2; j<=n; j++)
            for (long k=0; k<=1; k++)
              if (k==0) f[i][j][k]=min(f[i-1][j][0],f[i-1][j][1]+c[i][j]);
            else f[i][j][k]=min(f[i][j-1][1],f[i][j-1][0]+c[i][j]);
        cout << min(f[m][n][0],f[m][n][1]) << endl;
    }
}
