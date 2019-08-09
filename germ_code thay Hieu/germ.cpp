//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "germ"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

long long a[20][12][12];
int b[21];

void Init()
{
    memset(a, 0, sizeof(a));
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            a[2][i][j] = (i != j);
    for (int k = 3; k <= 18; k++)
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 9; j++)
                if (i!=j)
                    for (int p = 0; p <= 9; p++)
                        if (p != i)
                            a[k][i][j] += a[k-1][j][p];
}

long long Calc(long long x)
{
    if (x < 10) return x + 1;
    long long res = 10;
    int k = 0;
    while(x){
        b[++k] = x % 10;
        x /= 10;
    }
    b[k+1] = -1;
    for (int p = 2; p < k; p++)
        for (int i = 1; i <= 9; i++)
            for (int j = 0; j <= 9; j++) res += a[p][i][j];
    res += a[k][1][2] * 9 * (b[k]-1);// b[k] - 1 gia tri < b[k] dau tien
    for (; k > 1; k--){
        int cur = b[k];
        int next = b[k-1];
        for (int i = 0; i < next; i++)
            if (i != b[k+1]) res += a[k][cur][i];
        if (cur == next || next == b[k+1]) return res;
    }
    return res + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    Init();
    long long aa, bb;
    cin >> aa >> bb;
    cout << Calc(bb) - Calc(aa-1);
/*    long long x = 0;
    for (int i = 1; i <= 2000000000; i++) x += i;
    cout << x;*/
    return 0;
}
