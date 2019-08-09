//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "fibo"
#define maxn 3
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

struct matrix
{
    int val[maxn][maxn];
    matrix()
    {
        memset(val, 0, sizeof(val));
    }

    matrix operator * ( const matrix & x)
    {
        matrix res;
        for (int u = 1; u <= 2; u++)
            for (int v = 1; v <= 2; v++)
                for (int i = 1; i <= 2; i++)
                    res.val[u][v] = ((ll)val[u][i] * x.val[i][v] + res.val[u][v] ) % MOD;
        return res;
    }
};

matrix A;
int n;

matrix POWW(matrix A, int b)
{
    matrix C;
    C.val[1][1] = C.val[2][2] = 1;
    for ( ; b; b /= 2, A = A * A)
        if (b % 2) C = C * A;
    return C;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    A.val[1][1] = A.val[1][2] = A.val[2][1] = 1;
    A.val[2][2] = 0;
    matrix B = POWW(A, n-1);
    cout << B.val[1][1];
    return 0;
}

// 0 1 1 2 3 5 8
