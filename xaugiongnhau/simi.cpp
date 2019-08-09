#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;
const long long b=313, m=1000000000+7,m2=m*m;

string x;
long long t[nmax],n,ans,h[nmax],s[nmax];

long long get(long l, long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

bool check(long long vt, long long dd)
{
    if (get(0,dd-1)==get(vt,vt+dd-1)) return true;
    return false;
}

long long kt(long long h)
{
    long long l=0,r=n-h,res;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (check(h,mid))
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("simi.inp","r",stdin);
    freopen("simi.out","w",stdout);
    cin >> x;
    n=x.size();
    h[0]=1; h[1]=b;
    for (long i=2; i<=n; i++)
        h[i]=(h[i-1]*b) % m;
    s[0]=(x[0]) % m;
    for (long i=1;i<=n-1; i++)
        s[i]=((s[i-1]*b)+x[i]) % m;
    ans+=n;
    for (long i=1; i<n; i++)
      ans+=kt(i);
    cout << ans;
}
