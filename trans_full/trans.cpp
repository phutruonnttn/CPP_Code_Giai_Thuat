#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e3 + 5;
const int K = (int) 1e4 + 5;
const int MOD = (int) 1e9 + 7;

int n, k;
int dp[N][K], g[N][K];

int main()
{
    freopen("TRANS.inp", "r", stdin);
    freopen("TRANS.out", "w", stdout);
    scanf("%d %d", &n, &k);
    dp[0][0] = 1;
    for (int i = 0; i <= k; i++) g[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = g[i - 1][j];
            if (j >= i) dp[i][j] = (g[i - 1][j] - g[i - 1][j - i] + MOD) % MOD;
        }
        for (int j = 0; j <= k; j++)
        {
            g[i][j] = dp[i][j];
            if (j > 0) g[i][j] = (g[i][j - 1] + dp[i][j]) % MOD;
        }
    }
    printf("%d\n", dp[n][k]);
    return 0;
}

