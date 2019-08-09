#include <bits/stdc++.h>

using namespace std;

long t,n,a[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TAMGIAC.inp","r",stdin);
    freopen("TAMGIAC.out","w",stdout);
    cin >> t;
    for (long q=1; q<=t ; q++)
    {
        cin >> n;
        long long ans=0;
        for (long i=1; i<=n; i++) cin >> a[i];
        sort(a+1,a+n+1);

        //cout << upper_bound(a+3,a+n+1,5)-a-1-(2+1) << endl;

        for (long i=1; i<=n-2; i++)
          for (long j=i+1; j<=n-1; j++)
          {
             long k=upper_bound(a+j+1,a+n+1,a[i]+a[j])-a-1-j;
             ans+=k;
          }
        cout << ans << endl;
    }
}
