#include <bits/stdc++.h>
#define nmax 5007
#define vc 999999999

using namespace std;
typedef pair <long, double> ii;
const double eps=1e-5;

long long a[nmax],next[nmax],head[nmax],t[nmax],f[nmax],n,m,dd[nmax],res;
bool ok=true;

bool kt(double k)
{


     for (long i=1; i<=n; i++)
     {
         res=1; ok=true;
         for (long j=1; j<=n; j++) dd[j]=0;
         if (res==-1) return true;
     }
     return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("promotion.inp","r",stdin);
    freopen("promotion.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
       cin >> f[i];
    for (long i=1; i<=m; i++)
       //cin >> u[i] >> v[i] >> t[i];
       {
           long long u,v;
           cin >> u >> v >> t[i];
           a[i]=v;
           next[i]=head[u];
           head[u]=i;
       }
for (long i=1; i<=n; i++) cout << next[i] << endl;
    /*double l=0, r=vc, ans=0;

    while (r-l>eps)
     {
        double mid=(double)(l+r)/2;
        //cout << mid << endl;
        if (kt(mid)) l=mid;
        else r=mid;
     }

    printf("%0.2f",r);*/
}
