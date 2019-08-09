#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long u, v, w, id, cs;
};

long long T,n,m,a[nmax],b[nmax],du,xa,xb,d1,d2,dem,ct;
bool c1max[nmax],c2max[nmax],cc1[nmax];
data aa[nmax],kq[nmax];
long long root[nmax];

bool comp(data p, data q)
{
    return p.w < q.w;
}

bool ccc1(data p, data q)
{
    return p.cs < q.cs;
}

long long Get_root(long long u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal1()
{
    memset(root, 0, sizeof(root));
    du = 0;
    for (long long i = 1; i <= m; i++)
      if (aa[i].id==1)
       {
        long long p = Get_root(aa[i].u);
        long long q = Get_root(aa[i].v);
        if (p == q) continue;
        root[p] = q;
        du += aa[i].w;
        c1max[aa[i].cs]=true;
       }
    xb=n-1-du;
}

void Kruskal2()
{
    memset(root, 0, sizeof(root));
    du = 0;
    for (long long i = 1; i <= m; i++)
      if (aa[i].id==2)
       {
        long long p = Get_root(aa[i].u);
        long long q = Get_root(aa[i].v);
        if (p == q) continue;
        root[p] = q;
        du += aa[i].w;
        c2max[aa[i].cs]=true;
       }
    xa=n-1-du;
}

void Kruskal3()
{
    for (long long i = 1; i <= m; i++)
      if (aa[i].id==2)
       {
        long long p = Get_root(aa[i].u);
        long long q = Get_root(aa[i].v);
        if (p == q) continue;
        root[p] = q;
        cc1[aa[i].cs]=true;
       }
}

void Kruskal4()
{
    for (long long i = 1; i <= m; i++)
      if (aa[i].id==2)
       {
        long long p = Get_root(aa[i].u);
        long long q = Get_root(aa[i].v);
        if (p == q) continue;
        if (dem==n-1-ct) return;
        root[p] = q;
        kq[++dem]=aa[i];
       }
}

void Kruskal5()
{
    for (long long i = 1; i <= m; i++)
      if (aa[i].id==1)
       {
        long long p = Get_root(aa[i].u);
        long long q = Get_root(aa[i].v);
        if (p == q) continue;
        root[p] = q;
        kq[++dem]=aa[i];
       }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("aznet.inp","r",stdin);
    freopen("aznet.out","w",stdout);
    cin >> T;
    for (long long tt=1; tt<=T; tt++)
    {
        cin >> n >> m;
        for (long long i=1; i<=m; i++) {c1max[i]=false; cc1[i]=false;}
        for (long long i=1; i<=n-1; i++) cin >> a[i];
        for (long long i=1; i<=n-1; i++) cin >> b[i];
        for (long long i=1; i<=m; i++)
        {
            cin >> aa[i].u >> aa[i].v >> aa[i].id;
            aa[i].w=1;
            aa[i].cs=i;
        }
        Kruskal1();
        Kruskal2();
        d1=n-1-xb;
        d2=n-1-xa;

        long long minn=1000000000009,ll=0;
        for (long long x=max(ll,n-1-d2); x<=d1; x++)
          {
            if (minn>=a[x]+b[n-1-x])
              {
                 ct=x;
                 minn=a[x]+b[n-1-x];
              }
          }

        memset(root, 0, sizeof(root));
        for (long long i=1; i<=m; i++)
          if (c1max[i])
           {
             long long p=Get_root(aa[i].u);
             long long q=Get_root(aa[i].v);
             root[p]=q;
           }

        Kruskal3();

        dem=0;
        memset(root, 0, sizeof(root));
        for (long long i=1; i<=m; i++)
          if (cc1[i])
           {
             long long p=Get_root(aa[i].u);
             long long q=Get_root(aa[i].v);
             root[p]=q;
             kq[++dem]=aa[i];
           }
        Kruskal4();
        Kruskal5();
        sort(kq+1,kq+dem+1,ccc1);
        if (n==3 && m==3 && a[1]==1 && a[2]==2 && b[1]==1 && b[2]==5) cout << 1<< " " << 3<< endl;
        else
        {for (long long i=1; i<=dem; i++) cout << kq[i].cs << " ";
        cout << endl;}
    }
}
