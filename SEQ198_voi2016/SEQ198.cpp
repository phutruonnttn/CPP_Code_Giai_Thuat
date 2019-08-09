#include <bits/stdc++.h>
#define nmax 2007

using namespace std;

long long n,m,a[nmax],a1[nmax],sl[nmax],f[nmax][nmax];

long getbit(long k, long x)
{
    return ((x>>k)&1);
}

void batbit(long k, long &x)
{
    x=x|(1<<k);
}

void tatbit(long k, long &x)
{
    x=x&~(1<<k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SEQ198.inp","r",stdin);
    freopen("SEQ198.out","w",stdout);
    cin >> m;
    for (long i=1; i<=m; ++i) cin >> a1[i];
    sort(a1+1,a1+m+1);
    long n=0;
    for (long i=1; i<=m; ++i)
      if (sl[a1[i]]==0)
       {
           sl[a1[i]]++;
           a[++n]=a1[i];
       }
      else sl[a1[i]]++;
    if (m<10)
    {
        sub1();
        return 0;
    }
    while (n<10) a[++n]=500;
    for (long i=10; i<=n; ++i)
      for (long x=0; x<=1024; ++x)
        {
            long y=tatbit(9,x);
            if (!ktra(i,x)) f[i][x]=-1;
            else
            {
                f[i][x]=min(f[i-1][y])
            }
        }
}
