#include <bits/stdc++.h>

using namespace std;

long long m,n,a[507][507];
long long aa[507][507];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MATRIX.inp","r",stdin);
    freopen("MATRIX.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
       for (long j=1; j<=n; j++)
          cin >>a[i][j];
    memset(aa,0,sizeof(aa));
    for (long i=1; i<=m; i++)
      for(long j=1; j<=n; j++)
       {
          long sumhang=0, sumcot=0;
          for (long ii=1; ii<=i; ii++) sumcot+=a[ii][j];
          for (long ii=1; ii<=j; ii++) sumhang+=a[i][ii];
          aa[i][j]=aa[i-1][j-1]+sumhang+sumcot-a[i][j];
       }


    /*for (long i=1; i<=m; i++)
    {
       for (long j=1; j<=n; j++)
          cout << aa[i][j] << " ";
        cout << endl;
    }*/

    long long ans=-10000000000;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
       {
          for (long ii=i;ii<=m; ii++)
            for (long jj=j; jj<=n; jj++)
                ans=max(ans,aa[ii][jj]-aa[ii][j-1]-aa[i-1][jj]+aa[i-1][j-1]);
       }
    cout << ans;
}
