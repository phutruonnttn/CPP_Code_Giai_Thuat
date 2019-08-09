#include <bits/stdc++.h>
#define nmax 100007
#define lmax 1000007

using namespace std;
typedef pair <long, long> ii;

struct data
{
    long u, v, w;
};

struct data1
{
    long gt,sl;
};

long long n,m,root[nmax],ans=0,dem=0;
data a[nmax];
data1 luu[nmax];
map <long,long > M;
vector <ii> a1[nmax];

bool comp(data p, data q)
{
    return p.w < q.w;
}

long get_root(long u)
{
    return (root[u]) ? root[u] = get_root(root[u]) : u;
}

void kruskal1()
{
    memset(root,0,sizeof(root));
    for (int i = 1; i <= m; i++)
    {
        int p = get_root(a[i].u);
        int q = get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        M[a[i].w]++;
        ans += a[i].w;
    }
    cout << ans << " ";
    //ans=(ans<<1);// tuong duong la nhan 2
}

bool join(long u,long v)
{
    long p = get_root(u);
    long q = get_root(v);
	if (p == q) return false;
	root[p]=q;
	return true;
}

long long kt(long uu, long vv, long ww)
{
    long res=0;
    memset(root,0,sizeof(root));
    int p = get_root(uu);
    int q = get_root(vv);
    root[p]=q;
    res+=ww;
    for (int i=1; i<= m; i++)
    {
        if ((a[i].u==uu && a[i].v==vv) || (a[i].u==vv && a[i].v==uu)) continue;
        int p = get_root(a[i].u);
        int q = get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        res+=a[i].w;
    }
    return res;
}

void calc()
{
    long ans1=1;
    for (long i=1; i<=dem; i++)
    {
        if (M[luu[i].gt]==3) continue;
        if (M[luu[i].gt]==1)
        {
            long demd=0;
            for (long j=0; j<a1[i].size(); ++j)
               if (kt(a1[i][j].first,a1[i][j].second,luu[i].gt)==ans) demd++;
            ans1+=(demd-1);
        }
        else
        {

        }
    }
    cout << ans1;
}

int main()//chua xong
{
    ios_base::sync_with_stdio(0);
    freopen("SIMPLIFY.inp","r",stdin);
    freopen("SIMPLIFY.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
      cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a+1,a+m+1,comp);
    for (long i=1; i<=m; i++)
       if (a[i].w!=a[i-1].w)
        {
            luu[++dem].gt=a[i].w;
            luu[dem].sl++;
            a1[dem].push_back(ii(a[i].u,a[i].v));
        }
        else
        {
            luu[dem].sl++;
            a1[dem].push_back(ii(a[i].u,a[i].v));
        }
    kruskal1();
    calc();
}
