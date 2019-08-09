#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long m,n,a,b,pos[nmax],ans;

long long cp(long long x, long long u, long long v)
{
    return (abs(v-u)+1)*b+(abs(v-u)+min(abs(x-u),abs(x-v)))*a;
}

bool kt(long long t)
{
    long long cm=1;
    for (long i=1; i<=m; i++)
    {
        long long p=cm;
        while (cp(pos[i],cm,p)<=t) p++;
        cm=p;
    }
    if (cm>n) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("HOLES.inp","r",stdin);
    freopen("HOLES.out","w",stdout);
    cin >> n >> m;
    cin >> a >> b;
    for (long i=1; i<=m; i++) cin >> pos[i];
    sort(pos+1,pos+m+1);
    long long l=0,r=cp(pos[1],1,n);
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
}
