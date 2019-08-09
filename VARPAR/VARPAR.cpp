#include <bits/stdc++.h>
#define oo 1000000000007

using namespace std;

long k,n,a[107];
double f[207][207];

double chiphi(long u,long v)
{
    long sl=v-u+1;
    double sum=0;
    for (long i=u; i<=v; i++) sum+=a[i];
    double tbc=(double)sum/sl;
    sum=0;
    for (long i=u; i<=v; i++)
       sum+=((double)a[i]-tbc)*((double)a[i]-tbc);
    return (double)sum/sl;
}

int main()
{
     ios_base::sync_with_stdio(0);
     freopen("VARPAR.inp","r",stdin);
     freopen("VARPAR.out","w",stdout);
     cin >> n >> k;
     for (long i=1; i<=n; i++) cin >> a[i];
     sort(a+1,a+n+1);

     for (long p=0; p<=k+2; p++)
       for (long i=0; i<=n+2; i++)
       {
          f[i][p]=oo;
          if (i<=p) f[i][p]=0;
       }

     for (long i=1; i<=n; i++) f[i][0]=0;
     for (long i=1; i<=n; i++)
        f[i][1]=chiphi(1,i);
     for (long p=2; p<=k; p++)
      for (long i=p+1; i<=n; i++)
        for (long j=1; j<=i-1; j++)
        {
           f[i][p]=min(f[i][p],(double)f[j][p-1]+chiphi(j+1,i));
        }
     cout << fixed << setprecision(5) << f[n][k];
     //cout <<fixed << setprecision(5) << f[4][3];
}
