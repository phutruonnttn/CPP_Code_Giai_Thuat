long t[nmax];

long get(long x)
{
    long ans=0;
    while (x>0)
    {
        ans+=t[x];
        x-=(x&-x);
    }
    return ans;
}

void update(long x, long d)
{
    while (x<=nmax)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}
