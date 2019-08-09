#include <bits/stdc++.h>
#define nmax 10007

using namespace std;

struct data
{
    long a,b,id;
    double ts;
};

long n;
data xe[nmax];

bool comp(data q, data p)
{
   if (q.ts!=p.ts) return q.ts < p.ts;
   if (q.a!=p.a) return q.a > p.a;
   return q.b < p.b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("car.inp","r",stdin);
    freopen("car.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; ++i) cin >> xe[i].a;
    for (long i=1; i<=n; ++i)
    {
        cin >> xe[i].b;
        xe[i].id=i;
        xe[i].ts=(double) xe[i].b/xe[i].a;
    }
    sort(xe+1,xe+n+1,comp);
    long long ans=0,sn=0;
    for (long i=1; i<=n; i++)
    {
        ans+=(xe[i].b+sn)*xe[i].a;
        sn+=xe[i].b;
    }
    cout << ans << '\n';
    for (long i=1; i<=n; i++) cout << xe[i].id << " ";
}
