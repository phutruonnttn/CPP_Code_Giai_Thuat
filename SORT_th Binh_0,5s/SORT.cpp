#include <bits/stdc++.h>
#define nmax 1000007
#define kmax 27

using namespace std;

long long n,k,g[kmax][kmax],a[nmax],dem[kmax],f[1<<21][kmax];

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
    freopen("SORT.inp","r",stdin);
    freopen("SORT.out","w",stdout);
    while (1<2)
    {
        cin >> n >> k;
        if (n==0 && k==0) break;
        for (long i=1; i<=k; i++)
          for (long j=1; j<=k; j++)
            g[i][j]=0;
        for (long i=1; i<=k; i++)
           dem[i]=0;
        for (long i=1; i<=n; i++)
        {
            cin >> a[i];
            for (long j=1; j<=k; j++)
               if (j!=a[i]) g[j][a[i]]+=dem[j];
            dem[a[i]]++;
        }
        for (long mask=0; mask<(1<<k); mask++)
          for (long i=0; i<=k; i++)
           {
               long mask1=tatbit()
           }
    }
}
