#include <bits/stdc++.h>
#define nmax 1507

using namespace std;

long long x,y,a,b,m,sl[nmax],dd[nmax],f[nmax][nmax];

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

bool ktra(long long h)
{
    if (h<=b) return true;
    if (h<=a)
    {
        long long tinh=m-x,can=h/b;
        if (h%b!=0) can++;
        if (tinh<=y/can) return true;
        return false;
    }
    if (h>(x*a+y*b)/m) return false;

    for (long i=1; i<=m; i++) {sl[i]=0; dd[i]=0;}
    long cur=x+y,sa=x,sb=y,chay=1,dem=0;
    while (1<2)
    {
        if (dem==m) break;
        if (cur==0) break;
        if (x==0 && y==0) break;
        if (chay>m) chay%=m;
        if (sl[chay]>=h && dd[chay]==0)
        {
            dem++;
            dd[chay]=1;
            chay++;
            continue;
        }
        if (sa!=0)
        {
            sl[chay]+=a;
            sa--; cur--;
        }
        else if (sb!=0)
        {
            sl[chay]+=b;
            sb--; cur--;
        }
        chay++;
    }
    bool ok=true;
    for (long i=1; i<=m; i++)
        if (sl[i]<h)
        {
            ok=false;
            break;
        }
    if (ok) return true;


    for (long i=0; i<=x; i++)
       for (long j=0; j<=y; j++)
         f[i][j]=0;
    long cx=h/a; if (h%a!=0) cx++;
    long cy=h/b; if (h%b!=0) cy++;
    for (long i=0; i<cx; i++) f[i][0]=0;
    f[cx][0]=1;
    for (long i=0; i<cy; i++) f[0][i]=0;
    f[0][cy]=1;
    for (long i=0; i<=x; i++)
       for (long j=0; j<=y; j++)
          for (long u=i; u>=0; u--)
          {
             if (a*u+b*j<h) break;
             for (long v=j; v>=0; v--)
                if (a*u+v*b>=h)
                   f[i][j]=max(f[i-u][j-v]+1,f[i][j]);
                else break;
          }
    if (f[x][y]>=m) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRIDGE.inp","r",stdin);
    freopen("BRIDGE.out","w",stdout);
    //cin >> x >> a >> y >> b >> m;
    doc(x); doc(a); doc(y); doc(b); doc(m);
    if (a<b)
    {
        swap(a,b);
        swap(x,y);
    }
    long long l=1, r=50000, ans=0;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (ktra(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans;
}
