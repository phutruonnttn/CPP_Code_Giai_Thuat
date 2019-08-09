#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "mintree"
#define maxn 30005
#define maxm 100002
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
using namespace std;

struct data
{
    int u, v, w;
};

long n,w,m,d,x;
bool fr[maxm];
long long ans;
data a[maxm];
int root[maxn];
vector <data> kq;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal()
{
    sort(a+1, a+n+1, comp);
    memset(root, 0, sizeof(root));
    ans = 0; x = 0;
    for (int i = 1; i <= n; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        a[++x]=a[i];
        ans += a[i].w;
        kq.PB(a[i]);
        x++;
    }
}

int main()
{
    freopen("CD.inp","r",stdin);
    freopen("CD.out","w",stdout);
    cin >> n >> w;
    m=0;
    for (long i=1; i<=w ; i++)
    {
       cin >> a[i].u >> a[i].v >> a[i].w;
       m++;
       Kruskal();
       if (x<n-1) cout << -1 << endl;
       else cout << ans<< endl;
       //else cout << -1 << endl;
    }
}
