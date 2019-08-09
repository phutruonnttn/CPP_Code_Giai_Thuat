#include <bits/stdc++.h>
#define maxn 3000007
#define maxm 1000007

using namespace std;

struct data
{
    long long u, v, w;
};

long long n,m,q,tt,ten,ans,ans1,ll,dem;
data a[maxm],b[maxm],c[maxm],kq[maxm];
long long root[maxn];

bool comp(data p, data q)
{
    return p.w < q.w;
}

long long Get_root(long long u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal()
{
    memset(root, 0, sizeof(root));
    dem=0;
    for (long long i = 1; i <= m; i++)
     if (b[i].w<b[ll].w)
      {
        long long p = Get_root(b[i].u);
        long long q = Get_root(b[i].v);
        if (p == q) continue;
        root[p] = q;
        kq[++dem]=b[i];
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("comnet_voi2013.inp","r",stdin);
    freopen("comnet_voi2013.out","w",stdout);
    cin >> tt;
    for (long long k=1; k<=tt; k++)
    {
        cin >> n >> m >> q;
        for (long long i = 1; i <= m; i++)
           cin >> a[i].u >> a[i].v >> a[i].w;
        for (long long i=1; i<=q; i++)
        {
             for (long long j = 1; j <= m; j++)
               {
                  b[j].u= a[j].u;
                  b[j].v= a[j].v ;
                  b[j].w= a[j].w;
               }
             long long l;
             cin >> ll;
             cin >> l;
             for (long long j=1; j<=l; j++)
               {
                  long long uu,vv;
                  cin >> uu >> vv;
                  b[uu].w=vv;
               }
             Kruskal();
             bool ok=false;
             if (Get_root(b[ll].u)==Get_root(b[ll].v)) cout << "YES" << endl;
             else cout << "NO" << endl;
        }
    }
}
