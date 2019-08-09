#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

struct data
{
    long long x,y,id;
};

long long n;
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

/*long long ccw1(data p1, data p2, data p3)
{
    long long a1,b1,a2,b2;
    a1=p2.x-p1.x;
    b1=p2.y-p1.y;
    a2=p3.x-p2.x;
    b2=p3.y-p2.y;
    return a1*b2 - a2*b1;
}*/

double dodai(data b, data c)
{
    long long res=(b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y);
    return (double)sqrt(res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CONVEX.inp","r",stdin);
    freopen("CONVEX.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      {
          cin >> a[i].x >> a[i].y;
          a[i].id=i;
      }
    sort(a+1,a+n+1,cmp);
    long long cnt=1;
    s[1]=a[1];
    for (long i=2; i<=n; i++)
    {
        while (cnt>1 && ccw(s[cnt],s[cnt-1],s[cnt],a[i])<=0) cnt--;
        //while (cnt>1 && ccw1(s[cnt-1],s[cnt],a[i])<=0) cnt--;
        s[++cnt]=a[i];
    }
    long long chot=cnt;
    for (long i=n-1; i>=1; i--)
    {
        while (cnt>chot && ccw(s[cnt],s[cnt-1],s[cnt],a[i])<=0) cnt--;
        //while (cnt>1 && ccw1(s[cnt-1],s[cnt],a[i])<=0) cnt--;
        s[++cnt]=a[i];
    }
    cout << cnt-1 << '\n';
    for (long i=cnt; i>1; i--) cout << s[i].id << " ";
    cout << '\n';
    double chuvi=0;
    for (long i=cnt; i>1; i--)
        chuvi+=dodai(s[i],s[i-1]);
    cout << fixed << setprecision(15) << chuvi << '\n';
    long long dientich=0;
    for (long i=1; i<cnt; i++)
      dientich+=((long long)(s[i+1].x-s[i].x)*(s[i+1].y+s[i].y));
    dientich=abs(dientich);
    cout << dientich/2;
    if (dientich%2==0) cout << ".0";
    else cout << ".5";
}
