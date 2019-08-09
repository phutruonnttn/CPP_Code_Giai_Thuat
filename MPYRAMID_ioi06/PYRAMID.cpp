#include <bits/stdc++.h>
#define nmax 1007
#define vc 9999999999

using namespace std;

struct point
{
    long long x,y,mn;
};

long long m,n,a,b,c,d,h[nmax][nmax],s[nmax][nmax],aa[nmax][nmax];
point dmn[4*nmax*nmax],def,t2;

long long sum(long u1,long v1,long u2,long v2)
{
    return s[u2][v2]-s[u2][v1-1]-s[u1-1][v2]+s[u1-1][v1-1];
}

point minp(point q, point p)
{
    if (q.mn < p.mn) return q;
    return p;
}

point build(long id,long a1,long b1,long a2,long b2)
{
    if (a1>a2 || b1>b2) return def;
    if (a1==a2 && b1==b2)
    {
        dmn[id].x=a1;
        dmn[id].y=b1;
        dmn[id].mn=aa[a1][b1];
        return dmn[id];
    }
    dmn[id]=def;
    dmn[id]=minp(dmn[id],build(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
    dmn[id]=minp(dmn[id],build(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
    dmn[id]=minp(dmn[id],build(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
    dmn[id]=minp(dmn[id],build(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
    return dmn[id];
}

point get(long id,long a1,long b1,long a2,long b2,long u1,long v1,long u2,long v2)
{
    if (u1 > a2 || v1 > b2 || u2 < a1 || v2 < b1 || a1 > a2 || b1 > b2)
       return def;
    if (u1 <= a1 && v1 <= b1 && a2 <= u2 && b2 <= v2) return dmn[id];
    point mx=def;
    mx = minp(mx, get(4 * id - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, u1, v1, u2, v2) );
    mx = minp(mx, get(4 * id - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, u1, v1, u2, v2) );
    mx = minp(mx, get(4 * id + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, u1, v1, u2, v2) );
    mx = minp(mx, get(4 * id + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, u1, v1, u2, v2));
    return mx;
}

void doc(long long &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;
    if (ktAm) n=-n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MPYRAMID.inp","r",stdin);
    freopen("MPYRAMID.out","w",stdout);
    doc(n); doc(m); doc(b); doc(a); doc(d); doc(c);
    def.x=0; def.y=0; def.mn=vc;
    for (long i=1; i<=m; ++i)
      for (long j=1; j<=n; ++j)
        {
            doc(h[i][j]);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+h[i][j];
        }
    for (long i=1; i<=m; ++i)
      for (long j=1; j<=n; ++j)
         aa[i][j]=vc;
    for (long i=1; i<=m-c+1; ++i)
       for (long j=1; j<=n-d+1; ++j)
          aa[i][j]=sum(i,j,i+c-1,j+d-1);
    long long ans=-vc,vta,vtb,vtc,vtd;
    build(1,1,1,m,n);
    for (long i=1; i<=m-a+1; ++i)
      for (long j=1; j<=n-b+1; ++j)
        {
             /*cout << i << " " << j << endl;
             cout << i+1 << " " << j+1 << " " << i+a-c-1 << " " << j+b-d-1 << endl;
             cout << endl;*/
             long long t1=sum(i,j,i+a-1,j+b-1);
             t2=get(1,1,1,m,n,i+1,j+1,i+a-c-1,j+b-d-1);
             if (t1-t2.mn>ans)
             {
                 ans=t1-t2.mn;
                 vta=i; vtb=j;
                 vtc=t2.x; vtd=t2.y;
             }
        }
     cout << vtb << " " << vta << '\n' << vtd << " " << vtc;

}
