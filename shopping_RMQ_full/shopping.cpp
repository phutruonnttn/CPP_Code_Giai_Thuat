#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

long long n,m,p[nmax],f[nmax][22];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("shopping.inp","r",stdin);
    freopen("shopping.out","w",stdout);
    cin >> n >> m;
    for (long long i=1; i<=n; i++) cin >> p[i];
    for (long i=1; i<=n; i++) f[i][0]=p[i];
    for (long i=1; i<=17; i++)
       for (long u=1; u<=n+1-(1<<i); u++)
         f[u][i]=min(f[u][i-1],f[u+(1<<(i-1))][i-1]);

    for (long long i=1; i<=m; i++)
    {
        long long t,l,r;
        cin >> t >> l >> r;
        t%=p[l];
        while (l<=r)
        {
            for (long j=17; j>=0; j--)
              if (f[l][j]>t) {l+=(1<<j); break;}
            if (l<=r) t%=p[l];
        }
        cout << t << '\n';
    }
}
