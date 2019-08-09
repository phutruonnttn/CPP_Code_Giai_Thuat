#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,k,x[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("orange.inp","r",stdin);
    freopen("orange.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> x[i];
    cin >> k;
    x[n+1]=9999999999;
    sort(x+1,x+n+1);
    long long ans=-1;
    for (long long i=1; i<=n; i++) ans=max(ans,upper_bound(x+1,x+n+1,x[i]+k)-x-i);
    cout << ans;
}
