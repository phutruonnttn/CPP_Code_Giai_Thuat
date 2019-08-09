#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,k,a[nmax];

bool kt(long long u)
{
    long long dem=0;
    for (long i=1; i<=n; i++)
       dem+=(a[i]/u);
    if (dem>=k) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("part.inp","r",stdin);
    freopen("part.out","w",stdout);
    //cin >> n >> k;
    scanf("%lld%lld",&n,&k);
    for (long i=1; i<=n; i++) scanf("%lld",&a[i]);//cin >> a[i];
    long long l=1, r=1000000000, ans=0;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%lld",ans);
}
