#include <bits/stdc++.h>
#define nmax 500007

using namespace std;

long long n,m,a[nmax],b[nmax],t[2*nmax];

long long get(long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&-x);
    }
    return res;
}

void update(long x, long d)
{
    while (x<2*nmax)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CANDIES.inp","r",stdin);
    freopen("CANDIES.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    for (long i=1; i<=m; i++) cin >> b[i];
    sort(a+1,a+n+1);
    for (long i=1; i<=m; i++)
    {
        long long x=b[i];
        long long l=1, r=n, ans=-1;
        while (l<=r)
        {
            long long mid=(l+r)/2;
            long long y=get(mid);
            if (a[mid]-y>=x)
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        if (ans==-1) cout << 0 << '\n';
        else
        {
            cout << n-ans+1 << '\n';
            update(ans,1);
        }
    }
}
