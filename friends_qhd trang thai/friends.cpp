#include <bits/stdc++.h>
#define nmax 27
#define vc 999999999999

using namespace std;

long long s,r,n,m,tg[nmax][nmax],f[1<<21];

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

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("friends.inp","r",stdin);
    freopen("friends.out","w",stdout);
    cin >> s >> r >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long long x,y,w;
        cin >> x >> y >> w;
        tg[x][y]+=w;
        tg[y][x]+=w;
    }
    long ans=1<<n;

    for (long i=0; i<ans; i++) f[i]=vc;
    for (long i=0;i<n; i++) f[(1<<i)]=0;
    f[0]=0;
    for (long x=3; x<ans; x++)
    {
         long i;
         for (i=n-1; i>=0; i--)
          if (getbit(i,x)==1) break;
         long long them=0;
         for (long j=0; j<i; j++)
           if (getbit(j,x)==1) them+=tg[i+1][j+1];
         long u=x;
         tatbit(i,u);
         f[x]=min(f[x],f[u]+them);
    }
    for (long x=0; x<ans; x++) f[x]*=r;

    for (long x=0; x<ans; x++)
    {
        long u,v;
        for (u=0; u<n; u++)
          if (getbit(u,x)==0)
             for (v=0; v<n; v++)
                if (getbit(v,x)==0 && v!=u)
                {
                    long y=x;
                    long long them=0;
                    for (long i=0; i<n; i++)
                       if (getbit(i,x)==1)
                        {
                           them+=tg[u+1][i+1]*r;
                           them+=tg[v+1][i+1]*r;
                        }
                    batbit(u,y); batbit(v,y);
                    f[y]=min(f[y],f[x]+s*tg[u+1][v+1]+them);
                }
    }
    cout << f[ans-1];
}

