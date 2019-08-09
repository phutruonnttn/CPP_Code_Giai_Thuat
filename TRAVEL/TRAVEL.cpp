#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long a,b;
};

long long n,f[3*nmax],x[3*nmax];
data cung[2*nmax];
vector <long> v;

bool cmp(data q, data p)
{
    if (q.a!=p.a) return q.a < p.a;
    return q.b < p.b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TRAVEL.inp","r",stdin);
    freopen("TRAVEL.out","w",stdout);
    cin >> n;
    long long dem=0;
    for (long i=1; i<=n; i++) {cin >> cung[i].a >> cung[i].b; x[++dem]=cung[i].a; x[++dem]=cung[i].b;}
    v.assign(x+1,x+2*n+1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long i=1;i<=2*n;i++)
         x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1;

    dem=0;
    for (long i=1; i<=n; i++)
    {
        cung[i].a=x[++dem];
        cung[i].b=x[++dem];
    }

    sort(cung+1,cung+n+1,cmp);
    for (long i=1; i<=n; i++) f[cung[i].b]=0;

    for (long i=1; i<=n; i++)
    {
        //f[cung[i].b]+=f[cung[i].a];
        f[cung[i].b]=max(1+f[cung[i].a],f[cung[i].b]);
    }
    long long ans=f[cung[1].b];
    for (long i=2; i<=n; i++) ans=max(ans,f[cung[i].b]);
    cout << ans;
}
