#include <bits/stdc++.h>
#define nmax 1007
#define vc 9999999999

using namespace std;

struct point
{
    long long x,y,mx;
};

long long n,m,a[nmax][nmax];
point d[16*nmax*nmax],def;

point maxp(point q, point p)
{
    if (q.mx > p.mx) return q;
    return p;
}

point build(long id,long a1,long b1,long a2,long b2)
{
    if (a1>a2 || b1>b2) return def;
    if (a1==a2 && b1==b2)
    {
        d[id].x=a1;
        d[id].y=b1;
        d[id].mx=a[a1][b1];
        return d[id];
    }
    d[id]=def;
    d[id]=maxp(d[id],build(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
    d[id]=maxp(d[id],build(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
    d[id]=maxp(d[id],build(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
    d[id]=maxp(d[id],build(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
    return d[id];
}

point get(long id,long a1,long b1,long a2,long b2,long u1,long v1,long u2,long v2)
{
    if (u1 > a2 || v1 > b2 || u2 < a1 || v2 < b1 || a1 > a2 || b1 > b2)
       return def;
    if (u1 <= a1 && v1 <= b1 && a2 <= u2 && b2 <= v2) return d[id];
    point mx=def;
    mx = maxp(mx, get(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, u1, v1, u2, v2) );
    mx = maxp(mx, get(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, u1, v1, u2, v2) );
    mx = maxp(mx, get(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, u1, v1, u2, v2) );
    mx = maxp(mx, get(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, u1, v1, u2, v2));
    return mx;
}

point update(long id,long a1,long b1,long a2,long b2,long x,long y,long value)
{
    if (a1 > a2 || b1 > b2) return def;
    if (x > a2 || y > b2 || x < a1 || y < b1) return d[id];
    if (x == a1 && y == b1 && x == a2 && y == b2)
        {
            d[id].x=x;
            d[id].y=y;
            d[id].mx=value;
            return d[id];
        }
    point mx = def;
    mx = maxp(mx, update(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value) );
    mx = maxp(mx, update(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
    mx = maxp(mx, update(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
    mx = maxp(mx, update(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value) );
    return d[id] = mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=m; j++)
          cin >> a[i][j];
    def.x=0; def.y=0; def.mx=-vc;
    build(1,1,1,n,m);
    update(1,1,1,n,m,2,4,2);
    point ans=get(1,1,1,n,m,2,3,3,4);
    cout << ans.x << " " << ans.y << " " << ans.mx;
}
