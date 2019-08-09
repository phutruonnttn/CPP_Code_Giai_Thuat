#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long a[nmax],n,tmp[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("REMAIN.inp","r",stdin);
    freopen("REMAIN.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    a[n+1]=a[1];
    for (long i=1; i<=n; i++)
      tmp[i]=abs(a[i]-a[i+1]);
    long long ans=__gcd(tmp[1],tmp[2]);
    for (long i=3; i<=n; i++)
        ans=__gcd(ans,tmp[i]);
    cout << ans;
}
