#include <bits/stdc++.h>

using namespace std;

long n,a[100007],d[400007];

/*void build(long id, long l, long r)
{
    if (l==r)
    {
        d[id]=a[l];
        return;
    }
    long mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    d[id]=d[id*2]+d[id*2+1];
}

long get(long id,long l, long r, long u, long v)
{
    if (v<l || r<u) return 0;
    if (u<=l && r<=v) return d[id];
    long mid=(l+r)/2;
    long x1=get(id*2,l,mid,u,v);
    long x2=get(id*2+1,mid+1,r,u,v);
    return x1+x2;
}

void update(long id, long l, long r, long x)
{
    if (l>x || r<x) return;
    if (l==r)
    {
        d[id]=a[x];
        return;
    }
    long mid=(l+r)/2;
    update(id*2,l,mid,x);
    update(id*2+1,mid+1,r,x);
    d[id]=d[id*2]+d[id*2+1];
}*/

void build(long id, long l, long r)
{
    if (l==r)
    {
        d[id]=a[l];
        return;
    }
    long mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    d[id]=max(d[id*2],d[id*2+1]);
}

void update(long id, long l, long r, long x)
{
    if (l>x || r<x) return ;
    if (l==r)
    {
        d[id]=a[x];
        return;
    }
    long mid=(l+r)/2;
    update(id*2,l,mid,x);
    update(id*2+1,mid+1,r,x);
    d[id]=max(d[id*2],d[id*2+1]);
}

long get(long id, long l, long r, long u, long v)
{
    if (v<l || r<u) return -1;
    if (u<=l && r<=v) return d[id];
    long mid=(l+r)/2;
    long x1=get(id*2,l,mid,u,v);
    long x2=get(id*2+1,mid+1,r,u,v);
    d[id]=max(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("test04.inp","r",stdin);
    freopen("test04.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    build(1,1,n);
    a[2]=0;
    //update(1,1,n,2);
    cout << get(1,1,n,1,5);
}
