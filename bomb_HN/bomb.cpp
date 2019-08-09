#include <bits/stdc++.h>
#define nmax 37

using namespace std;

long long m,n,a[nmax][nmax],pt[nmax*nmax][nmax*nmax+1],nho[nmax][nmax],k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bomb.inp","r",stdin);
    freopen("bomb.out","w",stdout);
    cin >> m >> n;
    long dem=0;
    for (long i=1; i<=m; i++)
      for (long j=1;j<=n; j++)
        {
            cin >> a[i][j];
            nho[i][j]=++dem;
        }
    long dpt=0;
    for (long i=1; i<=m; i++)
       for (long j=1; j<=n; j++)
           if (a[i][j]!=-1)
           {
              long id=nho[i][j];
              dpt++;
              pt[dpt][dem+1]=a[i][j];
              if (nho[i-1][j]!=0) pt[dpt][nho[i-1][j]]=1;
              if (nho[i+1][j]!=0) pt[dpt][nho[i+1][j]]=1;
              if (nho[i][j-1]!=0) pt[dpt][nho[i][j-1]]=1;
              if (nho[i][j+1]!=0) pt[dpt][nho[i][j+1]]=1;
           }
    k=m*n-dpt;

}
