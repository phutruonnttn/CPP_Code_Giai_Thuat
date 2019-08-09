#include <bits/stdc++.h>
#define nmax 100007
#define nmod 111539786

using namespace std;

long f[nmax][107],n,p,m;
string ps;

long neww(long t, long z)
{
    t=t*2+z;
    if (((t>>(m-1))&1)==1) t=t-1<<(m-1);
    return t;
}

long tinh(long i, long t)
{
   if (i>n) return 1;
   if (f[i][t]!=-1) return f[i][t];
   f[i][t]=0;
   for (long z=0; z<=1; z++)
     if (i<m || t*2+z!=p)
       f[i][t]=(f[i][t]+tinh(i+1,neww(t,z)))%nmod;
   return f[i][t];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("d.inp","r",stdin);
    freopen("d.out","w",stdout);
    cin >> n >> ps;
    m=ps.size();
    char psd[10];
    long dem=-1;
    for (long i=ps.size()-1; i>=0; i--)
    {
        psd[++dem]=ps[i];
    }
    for (long i=0; i<m; i++)
      if (psd[i]=='1') p=p+1<<i;

    for (long i=1; i<=n; i++)
      for (long j=0; j<=100; j++)
        f[i][j]=-1;

    long k=tinh(1,0)+tinh(1,1);
    cout << k;
}
