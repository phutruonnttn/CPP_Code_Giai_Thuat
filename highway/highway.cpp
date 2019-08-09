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
    int u, v;
    float w;
};

int n, m,l,d;
long x[maxm],y[maxm];
float ans;
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
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        ans += a[i].w;
        kq.PB(a[i]);
    }
}

void Ghikq()
{
    cout <<fixed<<setprecision(2) <<ans << endl;
    cout << n-1 << endl;
    for (int i = 0; i < n-1; i++)
        cout << kq[i].u << " " << kq[i].v << endl;
}

int main()
{
    freopen("highway.inp","r",stdin);
    freopen("highway.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> x[i] >> y[i];
    }
    m=0;
    for (long i=1; i<=n-1 ; i++)
      for (long j=i+1; j<=n ; j++)
    {
        m=m+1;
        a[m].u=i; a[m].v=j;
        a[m].w=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
    cin >> l;
    Kruskal();
    Ghikq();

}
