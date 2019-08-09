#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
#define maxn 100007

using namespace std;
typedef pair <long long,long long> ii;

struct data
{
    long long u, v, w, cs;
};

long long dmin[maxn],h[maxn],n,m,par[maxn][20],dx,minx[maxn][20];
data a[maxn],xet[maxn],b[maxn];
bool dd[maxn];
long long root[maxn];
vector <ii> adj[100007];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        {
            cin >> a[i].u >> a[i].v >> a[i].w;
            a[i].cs=i;
            b[i]=a[i];
        }
}

bool comp(data p, data q)
{
    return p.w > q.w;
}

int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void dfs(long long u)
{
  for (long long i = 0; i < adj[u].size(); i++)
    {
        long long v=adj[u][i].F;
        if (v!=par[u][0])
        {
            par[v][0]=u;
            minx[v][0]=adj[u][i].S;
            h[v]=h[u]+1;
            for (long long j=1; j<=17; j++)
            {
                par[v][j]=par[par[v][j-1]][j-1];
                minx[v][j]= min(minx[v][j-1],minx[par[v][j-1]][j-1]);
            }
            dfs(v);
        }
    }
}

void Kruskal()
{
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        dd[a[i].cs]=true;
        adj[a[i].u].PB(ii(a[i].v,a[i].w));
        adj[a[i].v].PB(ii(a[i].u,a[i].w));
    }
}

long LCAs(long u, long v)
{
    if (h[u]<h[v]) swap(u,v);
    long long _min=10000007;
    long del=h[u]-h[v];
    for (long i=0; i<=17; i++)
        if ((del >> i )& 1) { _min=min(_min,minx[u][i]); u=par[u][i];}
    if (u==v) return _min;

    for (long i=17; i>=0 ; i--)
        if (par[u][i]!=par[v][i])
         {
            _min=min(_min,minx[u][i]);
            _min=min(_min,minx[v][i]);
            u=par[u][i];
            v=par[v][i];
         }
    _min=min(_min,min(minx[u][0],minx[v][0]));
    return _min;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen("upgranet.inp", "r", stdin);
    freopen("upgranet.out", "w", stdout);
    nhap();
    for (long long i=1; i<=m; i++) dd[i]=false;
    Kruskal();
    dx=0;
    for (long long i=1; i<=m; i++)
       if (!dd[i]) xet[++dx]=b[i];
    dfs(1);
    long long ans=0;
    for (long long i=1; i<=dx; i++)
    {
        ans+=LCAs(xet[i].u,xet[i].v) -xet[i].w;
    }
    cout << ans;
}
