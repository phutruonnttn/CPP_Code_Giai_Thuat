#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x < y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 300007
#define maxm 1000007
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

struct data
{
    long long u, v, w;
};

long long n,m,q,tt,ten,ans,ans1;
data a[maxm],b[maxm],c[maxm];
long long root[maxn];

bool comp(data p, data q)
{
    return p.w < q.w;
}

long Get_root(long u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal()
{
    sort(c+1, c+m+1, comp);
    memset(root, 0, sizeof(root));
    ans = 0;
    for (long i = 1; i <= m; i++)
    {
        long p = Get_root(c[i].u);
        long q = Get_root(c[i].v);
        if (p == q) continue;
        root[p] = q;
        ans += c[i].w;
    }
    ans+=ten;
}

void Kruskal1()
{
    sort(b+1, b+m+1, comp);
    memset(root, 0, sizeof(root));
    ans1 = 0;
    for (long i = 1; i <= m; i++)
    {
        long p = Get_root(b[i].u);
        long q = Get_root(b[i].v);
        if (p == q) continue;
        root[p] = q;
        ans1 += b[i].w;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("comnet_voi2013.inp","r",stdin);
    freopen("comnet_voi2013.out","w",stdout);
    cin >> tt;
    for (long k=1; k<=tt; k++)
    {
        //cout << k << endl;
        cin >> n >> m >> q;
        for (long i = 1; i <= m; i++)
           cin >> a[i].u >> a[i].v >> a[i].w;
        for (long i=1; i<=q; i++)
        {
             for (long j = 1; j <= m; j++)
               {
                  b[j].u= a[j].u;
                  b[j].v= a[j].v ;
                  b[j].w= a[j].w;
               }
             long ll,l;
             cin >> ll;
             cin >> l;
             for (long j=1; j<=l; j++)
               {
                  long uu,vv;
                  cin >> uu >> vv;
                  b[uu].w=vv;
               }
             for (long j = 1; j <= m; j++)
               {
                  c[j].u= b[j].u;
                  c[j].v= b[j].v ;
                  c[j].w= b[j].w;
               }
             Kruskal1();
             long long kq1=ans1;
             ten=c[ll].w;
             c[ll].w = 0;
             Kruskal();
             long long kq2=ans;
             if (kq2>kq1) cout << "YES" << endl;
             else cout << "NO" << endl;
        }
    }
}
