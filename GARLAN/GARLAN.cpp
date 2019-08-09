#include <bits/stdc++.h>
#define maxn 17

using namespace std;

string a[maxn];
int n, m;
long long f[1 << 17][maxn], cp[16][16], res = 100000000000;

void prepare()
{
  for (int i = 1; i <= m; i++)
  {
    cin >> a[i];
    f[1 << (i-1)][i] = 0;
    for (int j = 0; j < n; j++)
      f[1 << (i-1)][i] += a[i][j] - 48;
  }
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k < n; k++)
        cp[i][j] += (a[i][k] != a[j][k]);
}
int main()
{
  freopen("GARLAN.INP", "r", stdin);
  freopen("GARLAN.OUT", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < (1 << m); i++)
    for (int j = 0; j < m; j++)
      f[i][j+1] = 100000000000;
  f[0][0] = 0;
  prepare();
  for (int i = 1; i < (1 << m); i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (((i >> j) & 1) == 0)
      {
        int y = i + (1 << j);
        for (int x = 0; x < m; x++)
          if (((i >> x) & 1) == 1)
            f[y][j+1] = min(f[y][j+1], f[i][x+1] + cp[x+1][j+1]);
      }
    }
  }
  for (int i = 1; i <= m; i++)
    res = min(res, f[(1 << m) - 1][i]);
  cout <<res;
}
