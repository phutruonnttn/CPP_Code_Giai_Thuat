#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

long n;
long long a[100007],d[500007],ans=0,b[100007];

void buid(long id, long l, long r,long long a[100007])
{
    if (l==r)
    {
        d[id]=a[l];
        return;
    }
    long mid=(l+r) /2;
    buid(id*2,l,mid,a);
    buid(id*2+1,mid+1,r,a);
    d[id]=__gcd(d[id*2],d[id*2+1]);
}

long long get(long id, long l, long r, long u, long v)
{
    if (u<=l && r<=v) return d[id];
    if (v<l || r<u) return 0;
    long mid=(l+r)/2;
    long long x1=get(id*2,l,mid,u,v);
    long long x2=get(id*2+1,mid+1,r,u,v);
    return __gcd(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VOGCDSUM.inp","r",stdin);
    freopen("VOGCDSUM.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        {cin >> a[i]; ans+=a[i];}
    buid(1,1,n,a);

    while (n!=1)
    {
        long d=0;
        for (long i=1; i<=n-1; i++)
           {b[++d]=get(1,1,n,i,i+1); ans+=b[d];}
        n--;
        buid(1,1,n,b);
    }

    cout << ans % nmod;
}
