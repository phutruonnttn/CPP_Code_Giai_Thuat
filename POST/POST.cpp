#include <bits/stdc++.h>
#define nmax 307
#define vc 9999999999

using namespace std;

long long v,p,a[nmax],f[nmax][nmax],tr[nmax][nmax],t[nmax][nmax],t2[nmax],kq[nmax];

long long cp(long m, long n)
{
    long long ts=0;
    for (long i=m; i<=n; i++)
       ts+=min(abs(a[m]-a[i]),abs(a[n]-a[i]));
    return ts;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("post.inp","r",stdin);
    freopen("post.out","w",stdout);
    cin >> v >> p;
    for (long i=1; i<=v; i++) cin >> a[i];

    for (long i=0; i<=v+1; i++)
       for (long j=0; j<=v+1; j++)
            f[i][j]=vc;

    f[1][1]=0;
    for (long i=1; i<=v; i++)
    {
        f[i][1]=0;
        for (long j=1; j<=i; j++)
          f[i][1]+=abs(a[i]-a[j]);
    }

    for (long i=1; i<=v; i++)
      for (long j=i; j<=v; j++)
         t[i][j]=cp(i,j);

    for (long i=1; i<=v; i++)
      for (long j=i+1; j<=v; j++)
         t2[i]+=abs(a[i]-a[j]);

    for (long j=2; j<=p; j++)
      for (long i=j; i<=v; i++)
        for (long k=j-1; k<=i-1; k++)
           if (f[i][j]>f[k][j-1]+t[k][i])
           {
               f[i][j]=f[k][j-1]+t[k][i];
               tr[i][j]=k;
           }
    long long ans=vc,l1=0,l2=0;
    for (long i=p; i<=v; i++)
      if (ans>f[i][p]+t2[i])
       {
           ans=f[i][p]+t2[i];
           l1=i; l2=p;
       }
    cout << ans << '\n';
    long dem=0;
    while (l1!=0)
    {
        kq[++dem]=a[l1];
        l1=tr[l1][p];
        p--;
    }
    for (long i=dem; i>=1; i--) cout << kq[i] << " ";
}
