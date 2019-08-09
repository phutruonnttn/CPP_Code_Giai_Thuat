#include <bits/stdc++.h>
#define nmax 1007
#define oo 999999999

using namespace std;

long long m,n,a,b,c,d,h[nmax][nmax],f[nmax][nmax],room[nmax][nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("PYRAMID.inp","r",stdin);
    freopen("PYRAMID.out","w",stdout);
    cin >> m >> n >> a >> b >> c >> d;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=m; j++) cin >> h[i][j];
    for (long i=1; i<=n; i++)
       for (long j=1; j<=m; j++)
         f[i][j]=f[i-1][j]+f[i][j-1]+h[i][j]-f[i-1][j-1];

    for (long i=1; i<=n; i++)
      for (long j=1; j<=m; j++)
        room[i][j]=oo;

    /*for (long i=1; i<=n*m; i++) room[i].s=oo;
    long long dem=0;
    for (long i=1; i<=n-d+1; i++)
       for (long j=1; j<=m-c+1; j++)
       {
           room[++dem].x=i;
           room[dem].y=j;
           room[dem].s=f[i+d-1][j+c-1]-f[i-1][j+c-1]-f[i+d-1][j-1]+f[i-1][j-1];
       }
    cout << dem;*/
    for (long i=1; i<=n-d+1; i++)
      for (long j=1; j<=m-c+1; j++)
        room[i][j]=f[i+d-1][j+c-1]-f[i-1][j+c-1]-f[i+d-1][j-1]+f[i-1][j-1];
    cout << room[1][8];
}
