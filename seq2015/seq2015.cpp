#include<bits/stdc++.h>
#define nmax 2005
#define Task "seq2015"
#define M 30103

using namespace std;

int n, a[nmax], f[nmax][nmax], s[2*nmax][nmax];

void Init()
{
    ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void Procc()
{
    for (int i = 1; i < n; ++i)
         for (int j = i + 1; j <= n; ++j)
    {
        f[i][j] = 1;
        int x = a[i] + a[j];
        for (int y = x + 1; y <= 2000; y++)
               f[i][j] = (f[i][j] + s[y][j + 1]) % M;
        for (int t = 1; t <= j; t++)
               s[x][t] += f[i][j];
    }

    long long ans = 0;
    for (int i = 1;  i < n; i++)
        for (int j = i + 1; j <= n; ++j)
           ans = (ans + f[i][j]) % M;

    ans = (ans - n*(n-1)/2 + 2*M) % M;
    cout << ans;
}

int main()
{
    Init();

    Procc();

    return 0;
}

