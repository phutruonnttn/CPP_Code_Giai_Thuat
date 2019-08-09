//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "caribe"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

pii a[1<<21];
int n, s, w[41], v[41];
int res = 0;
int smax[1<<21];

int main()
{
	ios_base::sync_with_stdio(0);
    freopen("caribe.inp", "r", stdin);
    freopen("caribe.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    int m = n/2;
    int sl = 1 << m;
    for (int i = 0; i < sl; i++)
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1) a[i].F += w[j], a[i].S += v[j];
    a[sl] = mp(-1e9, -1e9);
    sort(a, a+sl+1);
    a[sl+1] = mp(1e9, 1e9);
    smax[0] = a[0].S;
    for (int i = 1; i <= sl; i++) smax[i] = max(smax[i-1], a[i].S);
    for (int i = 0; i < (1<<(n-m)); i++)
    {
        int SW = 0, SV = 0;
        for (int j = 0; j < n-m; j++)
            if ((i >> j) & 1) SW += w[j+m], SV += v[j+m];
        int pos = upper_bound(a, a+sl+1, mp(s-SW,1000000000)) - a;
        res = max(res, smax[pos-1] + SV);
    }
    cout << res;
    return 0;
}
