//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "roads"
#define maxn 100002
#define maxm 200002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

struct data
{
    int u, v, type;
};

int root[maxn];
data a[maxm];
int n, m, k, num = 0;

void nhap()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].type;
}

int get_root(int u)
{
    return root[u] ? root[u] = get_root(root[u]) : u;
}

void Kruskal(int type, int mark, int ceil)
{
    for (int i = 1; i <= m; i++)
        if (a[i].type == type)
        {
            int p = get_root(a[i].u);
            int q = get_root(a[i].v);
            if (p == q) continue;
            root[p] = q;
            a[i].type = mark;
            if (++num == ceil) return;
        }
}

bool check()
{
    memset(root, 0, sizeof(root));
    Kruskal(0,0,n-1); // Ghep toi da duong khong thu phi
    if (num < n-1-k) return 0; // Can qua nhieu hon k duong thu phi de tao cay
    Kruskal(1,2,n-1);
    if (num < n-1) return 0; // khong tao thanh cay khung

    memset(root, 0, sizeof(root));
    num = 0;
    Kruskal(2,2,n-1);
    if (num < k) Kruskal(1,2,k);
    if (num != k) return 0; // khong du k duong
    Kruskal(0,2,n-1);
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    nhap();
	if (!check()) cout << - 1;
	else
    for (int i = 1; i <= m; i++)
        if (a[i].type == 2) cout << i << " ";
    return 0;
}
