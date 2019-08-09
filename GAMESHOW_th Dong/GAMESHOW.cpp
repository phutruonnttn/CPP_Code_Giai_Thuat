#include<bits/stdc++.h>
#define maxn 5505
using namespace std;

long long n,t,a[maxn],d[maxn][maxn],dd[maxn][maxn];

int main()
{
    freopen("GAMESHOW.inp","r",stdin);
    freopen("GAMESHOW.out","w",stdout);
    cin >> n >> t;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i];
        dd[i][0] = 0;
    }
    dd[0][0] = 1;
    for (long i = 1 ; i <= n ; i++)
      for (long j = 1; j<=i ; j++)
        {
            dd[i][j] = 0;
            if( i!=n && dd[i-1][j] && d[i-1][j] - t >= 0)
            {
                d[i][j] = d[i-1][j] - t;
                dd[i][j] = 1;
            }
            if( dd[i-1][j-1] && d[i-1][j-1] + a[i] >= 0)
            {
                d[i][j] = max( d[i][j], d[i-1][j-1] + a[i]);
                dd[i][j] = 1;
            }
        }
    long cmin=-1;
    for (long i=n; i>=1; i--)
    {
        if( dd[n][i] ) cmin = i;
        //cout << i << " " << dd[n][i] << endl;
    }
    cout << cmin;
}
