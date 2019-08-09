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
    long u, v, w;
};

long n,m;
long long ans;
data a[maxm];
int root[maxn];
vector <data> kq;
vector <long> adj[10007];
bool dd[10000];

long bacra[10007],bacvao[10007],nv[10007];

/*void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
       {cin >> a[i].u >> a[i].v; a[i].w=1;}
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

void dfs(long u)
{
    dd[u]=false;
    for (long i=0; i<adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (dd[v]==true) dfs(v);
    }

}

void Ghikq()
{
    cout << ans << endl;
    for (int i = 0; i < n-1; i++)
        cout << kq[i].u << " " << kq[i].v << endl;
}*/

void dfs(long u,long k)
{
    dd[u]=false;
    for (long i=0; i<adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (dd[v]==true) { nv[k]++;dfs(v,k);}
    }

}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen("MAXBOSS.inp", "r", stdin);
    freopen("MAXBOSS.out", "w", stdout);
    cin >> n >>m ;
    /*nhap();
    Kruskal();
    Ghikq();
    return 0;*/
    memset(bacra,0,sizeof(bacra));
    memset(bacvao,0,sizeof(bacvao));
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u>> v;
        bacra[u]++;
        bacvao[v]++;
        adj[u].push_back(v);
    }

    /*for (long i=1; i<=n; i++)
    {
        cout << bacra[i] << " " <<bacvao[i];
        cout << endl;
    }*/

    memset(nv,0,sizeof(nv));
    for (long i=1; i<=n; i++)
    {
        memset(dd,true,sizeof(dd));

        /*for (long j=0; j<adj[i].size();j++)
            dd[adj[i][j]]=false;*/
        dfs(i,i);
        //cout << nv[i]<< endl;
    }

    long maxx=nv[1];
    for (long i=2;i<=n; i++)
        maxx=max(maxx,nv[i]);
     cout << maxx << endl;
    for (long i=1; i<=n; i++)
          if (nv[i]==maxx) cout << i << " ";

}
