#include <bits/stdc++.h>

using namespace std;

long long n,a[1000007],f[1000007],ans=-10000000000,l,r;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("daycon.inp","r",stdin);
    freopen("daycon.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i]; f[i]=f[i-1]+a[i];}
    for (long i=1; i<=n-1; i++)
      for (long j=i+1; j<=n; j++)
         if (ans<f[j]-f[i-1])
          {
             ans=f[j]-f[i-1];
             l=i; r=j;
          }
    cout << l-1 << " " << r-1 << endl;
    cout << ans;
}
