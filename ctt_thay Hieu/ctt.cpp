#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 1004

using namespace std;

int m, n;
int d1[maxn], d2[maxn], c[maxn];

vector <pair <int, int>> ke[maxn];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        ke[x].PB(MP(y, l));
        ke[y].PB(MP(x, l));
    }
}

void IJK(int x, int*mang)
{
    for ( int i = 0; i <= n;i++) mang[i] = 1000000007;
    mang[x] = 0;
    priority_queue <pair <int, int> > q;
    q.push(MP(-mang[x], x));
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (l > mang[u]) continue;
        for (int i = 0; i < ke[u].size(); i++)
            {
                int v = ke[u][i].F;
                if (mang[v] > l + ke[u][i].S)
                {
                    mang[v] = l + ke[u][i].S;
                    q.push(MP(-mang[v], v));
                }
            }
    }
}

void xuli()
{
    IJK(1,d1);
    IJK(2,d2);
    for (int i = 1; i <= n; i++)
        c[i] = d2[i] - d1[i];
    sort(c+1, c+n+1);
    cout << accumulate(d1+1, d1+n+1, 0ll) + accumulate(c+1, c+n/2+1, 0ll);
}

int main()
{
    freopen("ctt.inp", "r", stdin);
    freopen("ctt.out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
