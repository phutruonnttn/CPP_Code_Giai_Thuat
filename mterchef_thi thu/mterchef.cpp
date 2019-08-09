#include <bits/stdc++.h>
#define nmax 1007
#define vc 9999999999

using namespace std;

long long n,p,trace[nmax],kq[nmax],t[nmax],f[nmax];

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
    cin.tie(0); cout.tie(0);
    freopen("MTERCHEF.inp","r",stdin);
    freopen("MTERCHEF.out","w",stdout);
    doc(n); doc(p);
    for (long i=1; i<=n;i++) doc(t[i]);
    f[0]=0;
    for (long i=1; i<=n; i++)
    {
       long long maxtime=0;
       f[i]=vc;
       long long sum=0;
       for (long j=i; j>=1; j--)
       {
           sum+=t[j];
           if (sum>p) break;
           if (maxtime<t[j]) maxtime=t[j];
           if (f[i]>(maxtime+f[j-1]))
           {
               f[i]=maxtime+f[j-1];
               trace[i]=j-1;
           }
       }
    }
    cout << f[n] << '\n';
    long long k=n,d=1;
    kq[1]=n;
    while (trace[k]!=0)
    {
        kq[++d]=trace[k];
        k=trace[k];
    }
    long long tmp=1;
    for (long i=d; i>=1; i--)
     {
        for (long j=tmp; j<=kq[i]; j++)
           cout << j << " ";
        cout << '\n';
        tmp=kq[i]+1;
     }
}
