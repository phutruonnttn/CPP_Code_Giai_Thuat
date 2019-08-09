#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 300005
#define maxm 1000007
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

struct data
{
    int u, v, w, id;
};

int n, m;
long long ans,ans1,ck[maxn],nck;
data a[maxm],b[maxm];
int root[maxn];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].id=i;
    }
}

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
    ans = 0; nck=0;
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        ans += a[i].w;
        ck[++nck]=a[i].id;
    }
}

void Kruskal1()
{
    //sort(b+1, b+m+1, comp);
    memset(root, 0, sizeof(root));
    ans1 = 0;
    for (int i = 1; i <= m; i++)
    {
        if (b[i].w==1000000000) continue;
        int p = Get_root(b[i].u);
        int q = Get_root(b[i].v);
        if (p == q) continue;
        root[p] = q;
        ans1 += b[i].w;
    }
    if (ans1<ans) ans1=1000000000;
}

int main()
{
    freopen("olymnet.inp","r",stdin);
    freopen("olymnet.out","w",stdout);
    nhap();
    Kruskal();
    cout << ans << " ";
    long long minn=1000000000;
    for (int i = 1; i <=nck; i++)
    {
        for (long j=1; j<=m; j++)
           b[j]=a[j];
        for (long j=1; j<=m; j++)
           if (b[j].id==ck[i])
           {
               b[j].w=1000000000;
               break;
           }
        Kruskal1();
        if (nck==n-1) minn=min(minn,ans1);
    }
    cout << minn;
}
