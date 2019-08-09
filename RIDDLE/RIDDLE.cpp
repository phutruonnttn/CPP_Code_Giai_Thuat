#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long t,n,k,a[nmax],b[nmax];

bool ktra(long m)
{
    for (long i=1; i<=m; i++) b[i]=a[i];
    sort(b+1,b+m+1);
    long sum=0;
    for (long i=1; i<=m; i++)
    {
        if (b[i]>sum+1) return false;
        sum=sum+b[i];
        if (sum>=k) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RIDDLE.inp","r",stdin);
    freopen("RIDDLE.out","w",stdout);
    cin >> t;
    for (long q=1; q<=t; q++)
    {
        cin >> n >> k;
        for (long i=1; i<=n; i++) cin >> a[i];
        long l=1,r=n,ans=-1;
        while (l<=r)
        {
            long mid=(l+r)/2;
            if (ktra(mid))
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        cout << ans << endl;
    }
}
