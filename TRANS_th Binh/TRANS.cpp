#include <bits/stdc++.h>
#define nmax 10007
#define nmod 1000000007

using namespace std;

long long n,m,f[nmax][nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TRANS.inp","r",stdin);
    freopen("TRANS.out","w",stdout);
    cin >> n >> m;
    for (long i=0; i<=n; i++) f[i][0]=1;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=m; j++) f[i][j]=((f[i-1][j]+f[i][j-1])%nmod+(nmod-f[i-1][j-i])%nmod) % nmod;
    cout << f[n][m];
}
