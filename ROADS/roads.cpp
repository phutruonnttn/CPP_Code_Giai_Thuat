#include <bits/stdc++.h>
#define PB push_back
#define maxn 3000005
#define maxm 10000007

using namespace std;

struct data
{
    long long u, v, w,id;
};

long long n, m, k,x;
bool dd[maxm];
data a[maxm];
long long root[maxm];
vector <long> kq;

void nhap()
{
    cin >> n >> m >> k;
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

void Kruskal1()
{
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    x=0;
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        if (a[i].w==1)
        {
            dd[a[i].id]=true;
            x++;
        }
    }
}

void Kruskal2()
{
    long demk=0;
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    for (int i = 1; i <= m; i++)
    {
        if (a[i].w==0) continue;
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        kq.PB(a[i].id);
        demk++;
        if (demk==k) break;
    }
    if (demk<k) return;
    for (int i = 1; i <= m; i++)
    {
        if (a[i].w!=0) continue;
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p == q) continue;
        root[p] = q;
        kq.PB(a[i].id);
    }
}



void xuli()
{
  memset(dd,false,sizeof(dd));
  Kruskal1();
  if (x>k) {cout << -1; return ;}
  for (long i=1; i<=m; i++)
    if (dd[a[i].id]==true)
     a[i].w=-10000000;
  Kruskal2();
  if (kq.size()<n-1) cout << -1;
  else
{
  sort(kq.begin(),kq.end());
  for (long i=0; i< kq.size(); i++)
    cout << kq[i] << " ";
}
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen("roads.inp", "r", stdin);
    freopen("roads.out", "w", stdout);
    nhap();
    xuli();
}
