#include <bits/stdc++.h>
#define nmax 100002
#define mp make_pair
#define F first
#define S second

using namespace std;

int n, m, pos[nmax];
pair < long long, long long > f[4*nmax];
char t;
int u, v;
long long mod = 1ll*1e9 + 7, a[nmax], tree[4*nmax], w;

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void chuanbi(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        pos[l] = node;
        f[node] = mp(1, 0);
        return;
    }
    int g = (r+l)/2;
    f[node] = mp(1, 0);
    chuanbi(2*node, l, g);
    chuanbi(2*node+1, g+1, r);
}

void update(int node, int l, int r, int u, int v)
{
    if (v < l || u > r) return ;
    if (u <= l && r <= v)
    {
        if (t == '+') f[node].S = (f[node].S + w) % mod;
        if (t == '*')
        {
            f[node].F = (w * f[node].F) % mod;
            f[node].S = (w * f[node].S) % mod;
        }
        return;
    }
    f[2*node].F = (f[2*node].F * f[node].F) % mod;
    f[2*node+1].F = (f[2*node+1].F * f[node].F) % mod;
    f[2*node].S = (((f[2*node].S * f[node].F) % mod) + f[node].S) % mod;
    f[2*node+1].S = (((f[2*node+1].S * f[node].F) % mod) + f[node].S) % mod;
    f[node] = mp(1, 0);
    int g = (r+l)/2;
    update(2*node, l, g, u, v);
    update(2*node+1, g+1, r, u, v);
}

long long getval(int u)
{
    long long res = a[u];
    int x = pos[u];
    while (x)
    {
        res = ((res*f[x].F) % mod + f[x].S) % mod;
        x /= 2;
    }
    return res % mod;
}

void xl()
{
    chuanbi(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        if (t == '+' || t == '*')
        {
            cin >> u >> v >> w;
            update(1, 1, n, u, v);
        }
        if (t == '?')
        {
            cin >> u;
            cout << getval(u) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ARITHMETIC.INP", "r", stdin);
    freopen("ARITHMETIC.OUT", "w", stdout);
    nhap();
    xl();
    return 0;
}
