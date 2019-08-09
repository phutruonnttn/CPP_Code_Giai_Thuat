#include <bits/stdc++.h>
#define nmax 5007
#define vc 9999999999

using namespace std;

long long t,n,k,a[nmax],f[nmax][nmax];

long long mu2(long long x)
{
    return x*x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CSTICKS.inp","r",stdin);
    freopen("CSTICKS.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> k >> n;
        k+=8;
        for (long i=1; i<=n; i++)
           cin >> a[i];
        for (long i=1; i<=n; i++)
          for (long j=1; j<=k; j++)
             f[i][j]=vc;
        f[n-2][1]=mu2(a[n-2]-a[n-1]);
        for (long i=n-3; i>=1; i--)
           f[i][1]=min(f[i+1][1],mu2(a[i]-a[i+1]));
        for (long j=2; j<=k; j++)
           for (long i=n; i>=1; i--)
             if (n-i+1<j*3) continue;
             else f[i][j]=min(f[i+1][j],mu2(a[i]-a[i+1])+f[i+2][j-1]);
        cout << f[1][k] << '\n';
    }
}
