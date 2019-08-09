#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxn 155
#define maxc 1000000007
#define PB push_back

using namespace std;

int n, m, s, t, cmin;
int gt[maxn*maxn], f[maxn];
bool kt[maxn];
double w, kq;

struct data
{
    int vv, cc, dd;
    data (int _vv = 0, int _cc = 0, int _dd = 0) {
        vv = _vv;
        cc = _cc;
        dd = _dd;
    }
};

vector <data> ke[maxn];

void nhap()
{
    cin >> n >> m >> s >> t >> w;
    for (int i = 1; i <= m ;i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        ke[u].PB(data(v, c, d));
        ke[v].PB(data(u, c, d));
        gt[i] = c;
    }
}

void chuanbi()
{
    sort(gt+1, gt+m+1);
    gt[0] = maxc;
    kq = maxc;
}

void dijktra()
{
    for (int i = 0; i <= n; i++)
        f[i] = maxc;
    f[s] = 0;
    priority_queue <pair <int, int>> q;
    q.push(MP(-f[s], s));
    while(!q.empty())
    {
        int u = q.top().S;
        int l = q.top().F;
        q.pop();
        if (l > f[u]) continue;
        for (int i = 0; i < ke[u].size(); i++)
        {
            int v = ke[u][i].vv;
            int g = ke[u][i].cc;
            int d = ke[u][i].dd;
            if (g < cmin) continue;
            if (f[v] > f[u] + d)
                {
                    f[v] = f[u] + d;
                    q.push(MP(-f[v], v));
                }
        }
    }
}

void tinh(int x)
{
    cmin = x;
    dijktra();
    double cur = w/cmin + f[t];
    kq = min(kq, cur);
}

void xuli()
{
    for (int i = 1; i <= m; i++)
        tinh(gt[i]);
}

int main()
{
    freopen("comm.inp", "r", stdin);
    freopen("comm.out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    printf("%0.2f", kq);
    return 0;
}
