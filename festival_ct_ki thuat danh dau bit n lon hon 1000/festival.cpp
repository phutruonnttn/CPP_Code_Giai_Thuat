#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

long long n,m,f[nmax][nmax],noi[nmax][nmax],ans=0;

void batbit(long k,long long &x)
{
    x=x|(1<<k);
}

long demb1(long long x)
{
    return __builtin_popcount(x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FESTIVAL.inp","r",stdin);
    freopen("FESTIVAL.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        batbit(v%20,noi[u][v/20]);
    }
    for (long i=1; i<=n-1; i++)
      for (long j=i+1; j<=n; j++)
        {
            long long dem=0;
            for (long l=0; l<=n/20; l++)
                dem+=demb1(noi[i][l]&noi[j][l]);
            if (dem>=2) ans+=((dem)*(dem-1))/2;
        }
    cout << ans;
}
