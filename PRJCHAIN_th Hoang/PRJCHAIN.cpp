#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long a,b,thu,dau,id;
};

long long n,thutu[nmax];
data da[nmax];

bool cmp(data q, data p)
{
    if (q.dau!=p.dau) return q.dau < p.dau;
    if (q.dau==p.dau && p.dau==1 && q.thu!=p.thu) return q.thu > p.thu;
    if (q.dau==p.dau && p.dau==2 && q.b!=p.b) return q.b > p.b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PRJCHAIN.inp","r",stdin);
    freopen("PRJCHAIN.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> da[i].a; da[i].id=i;}
    for (long i=1; i<=n; i++) cin >> da[i].b;
    for (long i=1; i<=n; i++) {da[i].thu=da[i].b-da[i].a; if (da[i].thu>=0) da[i].dau=1;else da[i].dau=2;}
    sort(da+1,da+n+1,cmp);
    long long cur=0;
    for (long i=1; i<=n; i++)
    {
        //long long vt=da[i].id;
        //cout << da[i].a << " " << da[i].b <<endl;
        thutu[i]=cur-da[i].a;
        cur=thutu[i]+da[i].b;
    }
    long long minn=999999999999999999;
    for (long i=1; i<=n; i++) minn=min(minn,thutu[i]);
    cout << -minn << '\n';
    for (long i=1; i<=n; i++) cout << da[i].id << " ";
}
