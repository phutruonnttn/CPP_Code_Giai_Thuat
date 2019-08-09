//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "FRIENDS"
#define maxn 2000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

string A, B;
int n, m;

const int Base = 101;
const long long MM = 1ll * MOD * MOD;

long long H[maxn], S[maxn];

long long Get_hash(int L, int R)
{
    return (S[R] + MM - S[L-1] * H[R-L+1]) % MOD;
}

string Calc(int L, int R, int p, int q)
{
    long long Sb = Get_hash(L,R);
    for (int i = p; i <= q; i++){
        long long dau = Get_hash(p, i-1);
        long long cuoi = Get_hash(i+1, q);
        long long Sa = (dau * H[q-i] + cuoi) % MOD;
        if (Sa == Sb) return A.substr(L, R-L+1);
    }
    return "NOT POSSIBLE";
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> A;
    n = A.length(); A = " " + A;

    H[0] = 1;
    for (int i = 1; i <= n; i++) H[i] = (H[i-1] * Base) % MOD;
    S[0] = 0;
    for (int i = 1; i <= n; i++) S[i] = (S[i-1] * Base + A[i]) % MOD;
    string res = "NOT POSSIBLE";
    m = n/2;
    if (n % 2){
        string res1 = Calc(1, n/2, n/2+1, n);
        string res2 = Calc(n/2+2, n, 1, n/2+1);
        if (res1 != res || res2 != res)
        {
            if (res1 != res && res2 != res && res1 != res2) res = "NOT UNIQUE";
                else res = (res1 == res) ? res2 : res1;
        }
    }
    cout << res;
    return 0;
}

