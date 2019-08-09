#include <bits/stdc++.h>
#define nmax 2007
#define vc 9999999999

using namespace std;

long long m,n,k,a[nmax][nmax],s1[nmax][nmax],s2[nmax][nmax],ans=-vc;

long long sum(long l1, long r1, long l2, long r2)
{
    return s1[l2][r2]-s1[l2][r1-1]-s1[l1-1][r2]+s1[l1-1][r1-1];
}

long long scheo(long l1, long r1, long l2, long r2)
{
    return s2[l2][r2]-s2[l1-1][r1-1];
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
    freopen("TRI.inp","r",stdin);
    freopen("TRI.out","w",stdout);
    doc(m); doc(n); doc(k);
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
        {
            doc(a[i][j]);
            s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1]+a[i][j];
            s2[i][j]=s2[i-1][j-1]+a[i][j];
        }
    for (long i=1; i<=m-k+1; i++)
    {
       long long tt=0,l1=i,r1=1,l2=i+k-1,r2=k;
       for (long j=1; j<=k; j++)
       {
           tt+=scheo(l1,r1,l2,r2);
           l1++; r2--;
       }
       ans=max(ans,tt);
       for (long j=2; j<=n-k+1; j++)
       {
           tt=tt-sum(i,j-1,i+k-1,j-1)+scheo(i,j,i+k-1,j+k-1);
           ans=max(ans,tt);
       }
    }
    cout << ans;
}
