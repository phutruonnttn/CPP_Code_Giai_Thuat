#include <bits/stdc++.h>
#define nmax 30007

using namespace std;

struct data
{
    long long x,y,c;
};

long long t,n;
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
    freopen("HEADQRT.inp","r",stdin);
    freopen("HEADQRT.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n;
        for (long i=1; i<=n; i++) cin >> a[i].x >> a[i].y >> a[i].c;
        long long trai1,phai1,tren1,duoi1,trai2,phai2,tren2,duoi2;

        sort(a+1,a+n+1,cmp);

        long long cnt=1;
        for (long i=1; i<=n; i++)
        s[1]=a[1];
        for (long i=2; i<=n; i++)
         {
           while (cnt>1 && ccw(s[cnt],s[cnt-1],s[cnt],a[i])<=0) cnt--;
           s[++cnt]=a[i];
         }
        long long chot=cnt;
        for (long i=n-1; i>=1; i--)
         {
           while (cnt>chot && ccw(s[cnt],s[cnt-1],s[cnt],a[i])<=0) cnt--;
           s[++cnt]=a[i];
         }

    }
}
