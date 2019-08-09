#include <bits/stdc++.h>

using namespace std;

long long n,a[10000][10000];
long long f[1000000];

int main()
{
    freopen("queue.inp","r",stdin);
    freopen("queue.out","w",stdout);
    cin >>n;
    for (long i=0; i<=n-1; i++)
        for (long j=1; j<=n; j++)
          cin >> a[i][j];
    f[0]=0;
    for (long x=0; x<=(1<<n)-1 ; x++)
    {
        long long t=__builtin_popcount(x);
        for (long i=0; i<=n-1; i++)
            if (((x>>i) & 1)==0)
            {
                long long y=x +(1<<i);
                f[y]=max(f[y],f[x]+a[i][t+1]);
            }
    }
    cout << f[(1<<n) -1 ];
}
