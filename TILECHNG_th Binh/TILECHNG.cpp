#include <bits/stdc++.h>
#define nmax 17
#define mmax 10007
#define vc 9999999999

using namespace std;

long long m,n,a[nmax],f[nmax][mmax],minn=vc,vt;

bool kt(long k)
{
    long i=sqrt(k);
    if (i*i==k) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TILECHNG.inp","r",stdin);
    freopen("TILECHNG.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) cin >> a[i];

    for (long i=1; i<=n; i++)
      for (long j=1; j<=m; j++)
        f[i][j]=vc;

    for (long i=1; i<=sqrt(m); i++) f[1][i*i]=(a[1]-i)*(a[1]-i);

    for (long i=2; i<=n; i++)
      for (long j=1; j<=m; j++)
        for (long k=1; k<sqrt(j); k++)
              {
                  long long tt=f[i-1][j-k*k]+(a[i]-k)*(a[i]-k);
                  f[i][j]=min(f[i][j],tt);
              }
    if (f[n][m]==vc) cout <<-1;
    else cout << f[n][m];
}
