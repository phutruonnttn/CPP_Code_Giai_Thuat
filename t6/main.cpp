

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
    d[id]=d[id*2]+d[id*2+1];
}

long get(long id, long l, long r, long u, long v)
{
    if (u<=l && v>=r) return d[id];
    if (u>r || v<l) return 0;
    long mid=(l+r)/2;
    long x1=get(id*2,l,mid,u,v);
    long x2=get(id*2+1,mid+1,r,u,v);
    return x1+x2;
}
