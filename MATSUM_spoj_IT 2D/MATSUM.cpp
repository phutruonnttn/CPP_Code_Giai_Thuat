#include <bits/stdc++.h>
#define nmax 2007

using namespace std;

long long n,t,d[16*nmax*nmax];
string s;

long long get(long id,long a1,long b1,long a2,long b2,long u1,long v1,long u2,long v2)
{
    if (u1 > a2 || v1 > b2 || u2 < a1 || v2 < b1 || a1 > a2 || b1 > b2)
       return 0;
    if (u1 <= a1 && v1 <= b1 && a2 <= u2 && b2 <= v2) return d[id];
    long long m1,m2,m3,m4;
    m1 = get(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, u1, v1, u2, v2);
    m2 = get(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, u1, v1, u2, v2);
    m3 = get(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, u1, v1, u2, v2);
    m4 = get(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, u1, v1, u2, v2);
    return m1+m2+m3+m4;
}

long long update(long id,long a1,long b1,long a2,long b2,long x,long y,long value)
{
    if (a1 > a2 || b1 > b2) return 0;
    if (x > a2 || y > b2 || x < a1 || y < b1) return d[id];
    if (x == a1 && y == b1 && x == a2 && y == b2)
        {
            d[id]=value;
            return d[id];
        }
    long long m1,m2,m3,m4;
    m1 = update(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value);
    m2 = update(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value);
    m3 = update(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value);
    m4 = update(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value);
    return d[id] = m1+m2+m3+m4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MATSUM.inp","r",stdin);
    freopen("MATSUM.out","w",stdout);
    scanf("%lld",&t);
    while (t--)
    {
        scanf("%lld",&n);
        n++;
        //memset(d,0,sizeof(d));
        for (long i=1; i<=n*n*2; i++) d[i]=0;
        while (true)
        {
            char s[10];
            scanf("%s",s);
            if (s[0]=='E') break;
            if (s[1]=='E')
            {
                long long x,y,num;
                scanf("%lld%lld%lld", &x, &y, &num);
                x++; y++;
                update(1,1,1,n,n,x,y,num);
            }
            else
            {
                long long x1,x2,y1,y2;
                scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
                x1++; y1++; x2++; y2++;
                printf("%lld\n",get(1,1,1,n,n,x1,y1,x2,y2));
            }
        }
        puts("");
    }
}
