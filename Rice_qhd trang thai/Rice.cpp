#include <bits/stdc++.h>
#define vc 999999999999

using namespace std;

long long n,m[27],f[1<<22],cr[27],ctong[1<<22],cdem[1<<22];

long getbit(long k, long x)
{
    return ((x>>k)&1);
}

void batbit(long k, long &x)
{
    x=x|(1<<k);
}

void tatbit(long k, long &x)
{
    x=x&~(1<<k);
}

long long cp(long p, long u)
{
       long long dem=cdem[u],tong=ctong[u],ct=0,cd=0;
       if (tong%dem==0) ct=cd=tong/dem;
       else
       {
           ct=tong/dem+1;
           cd=tong/dem;
       }
       if (m[p]<=cd) return cd-m[p];
       return m[p]-ct;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Rice.inp","r",stdin);
    freopen("Rice.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> m[i];

    for (long i=0; i<=(1<<21); i++) f[i]=vc;
    for (long i=0; i<=n; i++) f[1<<i]=0;
    for (long i=1; i<=n; i++)
    {
        ctong[1<<i]=m[i]; cdem[1<<i]=1;
        ctong[(1<<i)+1]=m[i]; cdem[(1<<i)+1]=1;
    }

    long ans=1<<(n+1);
    for (long x=4; x<=ans-1; x++)
    {
       long i;
       for (i=1; i<=n; i++)
        if (getbit(i,x)==1) break;
       long u=x;
       tatbit(i,u);
       ctong[x]=ctong[u]+m[i]; cdem[x]=cdem[u]+1;
    }

    for (long x=1; x<=ans-1; x++)
       for (long p=1; p<=n; p++)
         if (getbit(p,x)==0)
         {
             long u=x;
             batbit(p,u);
             f[u]=min(f[u],f[x]+cp(p,u));
         }
    cout << f[ans-1];
}
