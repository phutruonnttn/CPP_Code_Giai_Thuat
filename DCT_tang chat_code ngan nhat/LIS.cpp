#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long n,a[nmax],b[nmax],d[nmax],ans=-1;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("lis.inp","r",stdin);
    freopen("lis.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i]; b[i]=1000000007;}
    for (long i=1; i<=n; i++)
    {
        d[i]=lower_bound(b+1,b+n+1,a[i])-b;
        b[d[i]]=a[i];
        ans=max(ans,d[i]);
    }
    cout << ans;
}
