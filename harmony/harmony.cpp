#include <bits/stdc++.h>
#define nmax 500007

using namespace std;

long long n,a[nmax],ans=0,dd[30000007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("HARMONY.inp","r",stdin);
    freopen("HARMONY.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];

    dd[a[1]+a[1]+500007]++;
    for (long i=2; i<=n; i++)
    {
        for (long k=1; k<=i-1; k++)
          if (dd[a[i]-a[k]+500007]>0)
            {
                ans++;
                break;
            }
        for (long j=1; j<=i; j++) dd[a[j]+a[i]+500007]++;
    }
    cout << ans;
}
