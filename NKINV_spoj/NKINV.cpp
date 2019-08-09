#include <bits/stdc++.h>

using namespace std;

long long n,a[60007],d[2400007];

long long get(long id ,long l ,long r ,long u, long v)
{
   if (v<l || r<u) return 0;
   if (u<=l && r<=v) return d[id];
   long mid=(l+r)/2;
   return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}

void update(long id, long l, long r, long x)
{
    if (l>x || r<x) return ;
    if (l==r && l==x)
    {
        d[id]++;
        return;
    }
    long mid=(l+r)/2;
    update(id*2,l,mid,x);
    update(id*2+1,mid+1,r,x);
    d[id]=d[id*2]+d[id*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKINV.inp","r",stdin);
    freopen("NKINV.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    long long ans=0;
    for (long i=n; i>=1; i--)
    {
        ans+=get(1,1,n,1,a[i]-1);
        update(1,1,n,a[i]);
    }
    cout << ans;
}
