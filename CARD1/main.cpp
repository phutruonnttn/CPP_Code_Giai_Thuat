#include <bits/stdc++.h>

using namespace std;

long long n,a[200],f[105][105];

int main()
{
    freopen("CARD.inp","r",stdin);
    freopen("CARD.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    memset(f,-1,sizeof(f));
    for (long i=1; i<=n-2; i++)
       f[i][i+2]=a[i]*a[i+1]*a[i+2];

    for (long i=1; i<=n-1; i++)                                     //sai ca bai
       f[i][i+1]=0;

    for (long l=1; l<=n-1; l++)
        for (long r=l+1; r<=n; r++)
         {
             if (f[l][r]==-1) f[l][r]=10000000000;
             for (long k=l+1; k<=r-1; k++)
                f[l][r]=min(f[l][r],f[l][k]+f[k][r]+a[l]*a[r]*a[k]);

         }
    cout << f[1][n];
}
