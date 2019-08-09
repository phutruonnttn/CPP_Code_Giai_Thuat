#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long long t,m,n,a[nmax],b[nmax],c[nmax],d[nmax],ans;

bool kt1(long long h)
{
    long long sd=0,ma1=-1;
    for (long i=1; i<=n; i++)
    {
        if (a[i]>=h) continue;
        sd+=((h-a[i])/b[i]);
        ma1=max(ma1,a[i]+b[i]*((h-a[i])/b[i]));
    }
    long long lamduoc=0,ma2=-1;
    for (long i=1; i<=m; i++)
    {
        if (c[i]>=t-h) continue;
        lamduoc+=((t-h-c[i])/d[i]);
        ma2=max(ma2,c[i]+d[i]*((t-h-c[i])/d[i]));
    }
    /*cout << ma1 << " " << ma2 << endl;
    cout << sd << " " << lamduoc;*/
    if (sd>=lamduoc-20 && ma1+ma2==t) return true;
    return false;
}

bool kt(long long h)
{
    long long sd=0;
    for (long i=1; i<=n; i++)
    {
        if (a[i]>=h) continue;
        sd+=((h-a[i])/b[i]);
    }
    long long lamduoc=0;
    for (long i=1; i<=m; i++)
    {
        if (c[i]>=t-h) continue;
        lamduoc+=((t-h-c[i])/d[i]);
    }
    //cout << sd << " " << lamduoc;
    if (lamduoc>=sd) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("Monkeys.inp","r",stdin);
    freopen("Monkeys.out","w",stdout);
    cin >> t >> n;
    for (long i=1; i<=n; i++) cin >> a[i] >> b[i];
    cin >> m;
    for (long i=1; i<=m; i++) cin >> c[i] >> d[i];
    long long l=0, r=t;
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
    //cout << ans;
    long long ll=0;
    for (long i=max(ll,ans-10000); i<=min(t,ans+10000);i++)
      if (kt1(i))
       {
          cout << i;
          return 0;
       }
    cout << ans;
}
