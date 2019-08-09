#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,m,f[nmax][5],a[nmax],b[nmax];

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
    freopen("linhvat.inp","r",stdin);
    freopen("linhvat.out","w",stdout);
    doc(n); doc(m);
    long long s=0;
    for (long i=1; i<=n; ++i) {doc(a[i]); s+=a[i];}
    //cout << s << endl;
    for (long i=1; i<=n; ++i) doc(b[i]);
    f[1][0]=a[1]; f[1][1]=b[1];
    for (long i=2; i<=n; ++i)
      for (long k=0; k<=1; ++k)
       {
          if (k==0) f[i][k]=min(f[i-1][k]+a[i],f[i-1][1-k]+m+a[i]);
          else f[i][k]=min(f[i-1][k]+b[i],f[i-1][1-k]+m+b[i]);
       }
    printf("%lld",f[n][1]);
}
