#include <bits/stdc++.h>

using namespace std;

long n,q,a[50007],dmin[200007],dmax[200007];

void build_min(long id,long l, long r)
{
    if (l==r)
    {
        dmin[id]=a[l];
        return;
    }
    long mid=(l+r) /2;
    build_min(id*2,l,mid);
    build_min(id*2+1,mid+1,r);
    dmin[id]=min(dmin[id*2],dmin[id*2+1]);
}

void build_max(long id,long l, long r)
{
    if (l==r)
    {
        dmax[id]=a[l];
        return;
    }
    long mid=(l+r) /2;
    build_max(id*2,l,mid);
    build_max(id*2+1,mid+1,r);
    dmax[id]=max(dmax[id*2],dmax[id*2+1]);
}

long long getmin(long id, long l, long r, long u, long v)
{
    if (u<=l && r<=v) return dmin[id];
    if (v<l || r<u) return 10000000;
    long mid=(l+r)/2;
    long long x1=getmin(id*2,l,mid,u,v);
    long long x2=getmin(id*2+1,mid+1,r,u,v);
    return min(x1,x2);
}

long long getmax(long id, long l, long r, long u, long v)
{
    if (u<=l && r<=v) return dmax[id];
    if (v<l || r<u) return -1;
    long mid=(l+r)/2;
    long long x1=getmax(id*2,l,mid,u,v);
    long long x2=getmax(id*2+1,mid+1,r,u,v);
    return max(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKLINEUP.inp","r",stdin);
    freopen("NKLINEUP.out","w",stdout);
    cin >> n >> q;
    for (long i=1; i<=n; i++) cin >> a[i];
    build_min(1,1,n); build_max(1,1,n);
    for (long i=1; i<=q; i++)
    {
        long u,v; cin >> u >> v;
        cout << getmax(1,1,n,u,v) - getmin(1,1,n,u,v) << endl;
    }
}
