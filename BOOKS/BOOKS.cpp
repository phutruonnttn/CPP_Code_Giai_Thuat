#include <bits/stdc++.h>

using namespace std;

long long n,a[5007][5007];
bool dd[5007][5007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BOOKS.inp","r",stdin);
    freopen("BOOKS.out","w",stdout);
    cin >> n;

    for (long i=1; i<=n; i++)
       for (long j=1; j<=n; j++)
         cin >> a[i][j];

    for (long i=1; i<=n; i++)
        for (long j=1; j<=n; j++)
          dd[i][j]=false;

    for (long i=1; i<=n; i++)
    {
        dd[1][i]=true;
        dd[i][1]=true;
        dd[n][i]=true;
        dd[i][n]=true;
    }
           long chay;
             for (long i=1; i<=n; i++)
              {
                  chay=a[i][1];
                  for (long j=1; j<=n-1; j++)
                     {

                          if (chay<a[i][j+1])
                          {
                              dd[i][j+1]=true;
                              chay=a[i][j+1];
                          }
                     }
              };

              for (long i=1; i<=n; i++)
              {
                  chay=a[1][i];
                for (long j=1;j<=n-1; j++)
                 {
                   //chay=a[j][i];
                   if (chay<a[j+1][i]) {dd[j+1][i]=true; chay=a[j+1][i];}
                 }
              };

              for (long i=1; i<=n; i++)
                {
                    chay=a[i][n];
                    for (long j=1; j<=n-1; j++)
                 {
                    //chay=a[i][n-j+1] ;
                   if (chay<a[i][n-j]) {dd[i][n-j]=true; chay=a[i][n-j];}
                 }
                };
              for (long i=1; i<=n; i++)
                {
                    chay=a[n][i];
                    for (long j=1; j<=n-1; j++)
                 {
                     //chay=a[n-j+1][i];
                    if (chay<a[n-j][i]) {dd[n-j][i]=true; chay=a[n-j][i];}
                 }
                };

      for (long i=1; i<=n; i++)
        for (long j=1; j<=n; j++)
         if (a[i][j]==0) dd[i][j]=false;

        /* for (long i=1; i<=n; i++)
         {
             for (long j=1; j<=n; j++)
                cout << dd[i][j];
             cout << endl;
         }*/


      long long ans=0;
      for (long i=1; i<=n; i++)
         for (long j=1; j<=n; j++)
           if (dd[i][j]==true) ans++;
      cout << ans;

}
