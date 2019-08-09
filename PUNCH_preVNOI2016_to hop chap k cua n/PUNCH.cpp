#include <bits/stdc++.h>
#define nmax 1000007
#define vc 9999999999

using namespace std;

long long n,a[nmax],ans=vc,x[30],f[nmax],lat[5][nmax];

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

long getbit(long k,long long x)
{
    return ((x>>k)&1);
}

void batbit(long k, long long &x)
{
    x=x|(1<<k);
}

void tinh()
{
    long long tmp=0;
    for (long i=1; i<=n; i++)
      tmp=tmp+min(2-getbit(x[1]-1,a[i])-getbit(x[2]-1,a[i]),min(2-getbit(x[1]-1,lat[1][i])-getbit(x[2]-1,lat[1][i]),min(2-getbit(x[1]-1,lat[2][i])-getbit(x[2]-1,lat[2][i]),2-getbit(x[1]-1,lat[3][i])-getbit(x[2]-1,lat[3][i]))));
    ans=min(ans,tmp);
}

void tryy_(long i)
{
    for (long j=x[i-1]+1; j<=16-2+i; j++) //to hop chap k cua n voi k=2, n=16
    {
        x[i]=j;
        if (i==2) tinh();
        else tryy_(i+1);
    }
}

void lat90(long long y, long i, long j)
{
    if (getbit(0,y)==1) batbit(12,lat[i][j]);
    if (getbit(1,y)==1) batbit(8,lat[i][j]);
    if (getbit(2,y)==1) batbit(4,lat[i][j]);
    if (getbit(3,y)==1) batbit(0,lat[i][j]);
    if (getbit(4,y)==1) batbit(13,lat[i][j]);
    if (getbit(5,y)==1) batbit(9,lat[i][j]);
    if (getbit(6,y)==1) batbit(5,lat[i][j]);
    if (getbit(7,y)==1) batbit(1,lat[i][j]);
    if (getbit(8,y)==1) batbit(14,lat[i][j]);
    if (getbit(9,y)==1) batbit(10,lat[i][j]);
    if (getbit(10,y)==1) batbit(6,lat[i][j]);
    if (getbit(11,y)==1) batbit(2,lat[i][j]);
    if (getbit(12,y)==1) batbit(15,lat[i][j]);
    if (getbit(13,y)==1) batbit(11,lat[i][j]);
    if (getbit(14,y)==1) batbit(7,lat[i][j]);
    if (getbit(15,y)==1) batbit(3,lat[i][j]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PUNCH.inp","r",stdin);
    freopen("PUNCH.out","w",stdout);
    doc(n);
    for (long i=1; i<=n; i++)
    {
        doc(a[i]);
        lat90(a[i],1,i);
        lat90(lat[1][i],2,i);
        lat90(lat[2][i],3,i);
    }
    tryy_(1);
    cout << ans;
}
