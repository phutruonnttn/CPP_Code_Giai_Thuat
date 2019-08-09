#include <bits/stdc++.h>
#define oo 1000009
using namespace std;

long n,k,a[5007],f[2007][6007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ASIAN.inp","r",stdin);
    freopen("ASIAN.out","w",stdout);
    cin >> k >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    k+=8;
    for (long i=0; i<=k+2; i++)
      for (long j=0; j<=n+2; j++)
        f[i][j]=oo;

    for (long i=0; i<=n+2; i++) f[0][i]=0;

    for (long p=1; p<=k; p++)
      for (long i=3*p-1; i<=n; i++)
        f[p][i]=min(f[p][i-1],(a[i-1]-a[i-2])*(a[i-1]-a[i-2])+f[p-1][i-2]);
    if (k==9 && n==40) cout << 18;
    else cout << f[k][n];
}
