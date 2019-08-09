#include<bits/stdc++.h>
#define nmax 55
#define Task "gard"
#define mod 1000000000

using namespace std;

int n, k, sz, x[nmax];
long long c[nmax][nmax], f[nmax][nmax], ans;

void Init()
{
    c[0][0] = 1;
    for (int i = 1; i <= 51; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
}

int main()
{
     freopen(Task".inp", "r", stdin);
     freopen(Task".out", "w", stdout);

     cin >> n >> k;

     Init();

     f[0][0] = 1;
     for (int j = 1; j <= n; j++)
         for (int i = 1; i <= n; i++)
            for (int t = 1; t <= min(i, k); t++)
             {
                // cout <<i<<" "<<t<<" "<< c[t][i] << endl;
                 f[i][j] += f[i-t][j-1]*c[i][t];
                 f[i][j] %= mod;
             }

    ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + f[n][i]) % mod;
    cout << ans;
}
