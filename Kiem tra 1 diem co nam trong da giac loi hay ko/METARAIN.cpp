#include <bits/stdc++.h>
#define nmax 50007

using namespace std;

struct data
{
    long long x,y;
};

long long n,m;
data a[nmax];

long long ccw(data u1, data v1, data u2, data v2)
{
    data vto1,vto2;

    vto1.x=v1.x-u1.x; vto1.y=v1.y-u1.y;
    vto2.x=v2.x-u2.x; vto2.y=v2.y-u2.y;

    return vto1.x*vto2.y-vto2.x*vto1.y;
}

void ktra(data b)
{
    long long l=2,r=n,mid;
    while (r-l>1)
    {
        mid=(l+r)/2;
        if ((ccw(a[1],b,a[1],a[mid])>=0 && ccw(a[1],b,a[1],a[r])<=0) || (ccw(a[1],b,a[1],a[mid])<=0 && ccw(a[1],b,a[1],a[r])>=0))
           l=mid;
        else r=mid;
    }
    if (abs(ccw(a[1],a[l],a[1],a[r]))==abs(ccw(a[1],b,a[1],a[l]))+abs(ccw(a[1],b,a[1],a[r]))+abs(ccw(b,a[r],b,a[l])))
        cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("METARAIN.inp","r",stdin);
    freopen("METARAIN.out","w",stdout);
    cin >> n;
    for(long i=1; i<=n; i++)
       cin >> a[i].x >> a[i].y;
    cin >> m;
    for (long i=1; i<=m; i++)
    {
        data b;
        cin >> b.x >> b.y;
        bool ok=false;
        a[n+1]=a[1];
        for (long j=2; j<=n+1; j++)
          if (ccw(a[j-1],b,a[j-1],a[j])==0)
          {
             cout << "NO" << '\n';
             ok=true;
             break;
          }
        if (ok) continue;
        ktra(b);
    }
}
