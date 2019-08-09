#include <bits/stdc++.h>
#define nmax 4007

using namespace std;

struct data
{
    long long x,y,id;
};

long long n,ans=0,dd[nmax];
data a[nmax],s[nmax];

bool cmp(data q, data p)
{
    if (q.x!=p.x) return q.x < p.x;
    return q.y < p.y;
}

long long ccw(data u1, data v1, data u2, data v2)
{
    data vto1,vto2;

    vto1.x=v1.x-u1.x; vto1.y=v1.y-u1.y;
    vto2.x=v2.x-u2.x; vto2.y=v2.y-u2.y;

    return vto1.x*vto2.y-vto2.x*vto1.y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MILITARY.inp","r",stdin);
    freopen("MILITARY.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i].x >> a[i].y; a[i].id=i; dd[i]=0;}

    sort(a+1,a+n+1,cmp);

    long long dem=n;
//nho xem TH cac diem thang hang
    while (dem>=3)
    {
        bool ok=true;
        data d1,d2;

        for (long i=1; i<=n; i++)
         if (dd[a[i].id]==0)
           {
             d1=a[i];
             break;
           }

        for (long i=1; i<=n; i++)
         if (dd[a[i].id]==0 && a[i].id!=d1.id)
           {
             d2=a[i];
             break;
           }

        for (long i=1; i<=n; i++)
         if (dd[a[i].id]==0 && ccw(d1,d2,d1,a[i])!=0)
           {
             ok=false;
             break;
           }
        if (ok)
        {
            cout << ans;
            return 0;
        }

        ans++;
        long long cnt=1;
        for (long i=1; i<=n; i++)
         if (dd[a[i].id]==0)
         {
             s[1]=a[i];
             break;
         }
        for (long i=2; i<=n; i++)
          if (dd[a[i].id]==0)
          {
              while (cnt>1 && ccw(s[cnt],s[cnt-1],s[cnt],a[i])<=0) cnt--;
              s[++cnt]=a[i];
          }
        long long chot=cnt;
        for (long i=n-1; i>=1; i--)
           if (dd[a[i].id]==0)
           {
              while (cnt>chot && ccw(s[cnt],s[cnt-1],s[cnt],a[i])<=0) cnt--;
              s[++cnt]=a[i];
           }
        for (long i=1; i<=cnt; i++) dd[s[i].id]=1;
        dem-=(cnt-1);
    }
    cout << ans;
}
