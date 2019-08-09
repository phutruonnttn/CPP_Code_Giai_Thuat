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
#define Task "hight"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, s, t;
vector < pii > a[maxn];
int tr[maxn];

void DFS(int h, int u)
{
    //
    //for (int i = 0; i < a[u].size(); i++)
    for ( pii &p : a[u])
    {
        int v = p.F;
        int w = p.S;
        if (tr[v] == 0 && w >= h)
        {
            tr[v] = u;
            DFS(h, v);
        }
    }
}

bool check(int h)
{
    reset(tr);
    tr[t] = -1;
    DFS(h,t);
    return tr[s];
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> s >> t;
    int u, v, w;
    while (cin >> u >> v >> w){
        a[u].PB(mp(v,w));
        a[v].PB(mp(u,w));
    }

    int l = 0, r = 100001;
    while (r - l > 1)
    {
        int h = (l+r)/2;
        if (check(h)) l = h;
            else r = h;
    }
    cout << l << endl;
    check(l);
    while (s != t){
        cout << s << endl;
        s = tr[s];
    }
    cout << t;
    return 0;
}
