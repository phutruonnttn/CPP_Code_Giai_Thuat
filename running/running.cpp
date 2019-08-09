#include <bits/stdc++.h>

using namespace std;

long n,a[1007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("running.inp","r",stdin);
    freopen("running.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    long long ans=0;
    /*for (long i=1; i<=n-2; i++)
      for (long j=i+1; j<=n-1; j++)
        ans+=(lower_bound(a+j+1,a+n+1,3*a[j]-2*a[i]+1)-a-1)-(lower_bound(a+j+1,a+n+1,2*a[j]-a[i])-a)+1;
    cout << ans;*/
    for (long x=1; x<=n-2; x++)
    {
        long z1=x+2,z2=x+2;
        for (long y=x+1; y<=n-1; y++)
        {
          while (a[z1]<2*a[y]-a[x] && z1<=n) z1++;
          while (a[z2]<=3*a[y]-2*a[x] && z2<=n) z2++;
          ans+=z2-z1;
        }
    }
    cout << ans;
}
