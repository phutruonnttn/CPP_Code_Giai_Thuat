#include <bits/stdc++.h>

using namespace std;

long n ,a[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sum_xor.inp","r",stdin);
    freopen("sum_xor.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];

    long long ans=-1;
    for (long i=1; i<=n-1; i++)
    {
        long long sum=a[i];
        for (long j=i+1; j<=n; j++)
          {
             sum=(sum^a[j]);
             ans=max(ans,sum);
          }
    }
    cout << ans;
}
