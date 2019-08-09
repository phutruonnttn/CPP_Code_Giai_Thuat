#include <bits/stdc++.h>
#define maxn 10002

using namespace std;

long long n, t, f[maxn][256], res = -100000000000000, a[maxn][10], b[10][maxn];

bool checkstate(int x)
{
  for (int i = 0; i <= 6; i++)
    if (((x >> i) & 1)==1 && ((x >> (i+1)) & 1)==1) return 0;
  return 1;
}

bool khop(int x, int z)
{
  return (x & z);
}


int main()
{
    freopen("QBGame.inp","r",stdin);
    freopen("QBGame.out","w",stdout);
    cin >> n;

    bool ok=false;

    for (int i = 0; i <= 7; i++)
      for (int j = 1; j <= n; j++) {cin >> b[i][j]; if (b[i][j]>=0) ok=true;}

    if (!ok)
    {
        long long maxx=-10000000000;
        for (int i=0; i<=7;i++)
           for (int j=1; j<=n; j++)
             maxx=max(maxx,b[i][j]);
        cout << maxx;
    }
    else
    {
    for (int i=1; i<=n; i++)
        for (int j=0; j<=7; j++)
               a[i][j]=b[j][i];
    for (int i = 1; i <= n; i++)
      for (int x = 0; x <= 255; x++)
        if (checkstate(x))
        {
          t = 0;
          for (int j = 0; j <= 7; j++)
            if ((x >> j) & 1) t += a[i][j];
          for (int z = 0; z <= 255; z++)
            if (!khop(x, z)) f[i][x] = max(f[i][x], f[i-1][z] + t);
        }
    for (int i = 0; i <= 255; i++) res = max(res, f[n][i]);
    cout <<res;
    return 0;
    }
}
