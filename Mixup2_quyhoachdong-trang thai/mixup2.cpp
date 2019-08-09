#include <bits/stdc++.h>

using namespace std;

long k,n,si[20];
long long f[20][70000];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("mixup2.inp","r",stdin);
    freopen("mixup2.out","w",stdout);
    cin >> n >> k;
    for (long i=0; i<=n-1; i++)
        cin >> si[i];

    for (long i=0; i<=n-1; i++)
        f[i][1 << i]=1;

    for (long x=0; x<=(1<<n)-1; x++)
      for (long i=0; i<=n-1; i++)
         if (((x >> i) & 1)==1)
           {
              long y=x & ~(1 << i);
              for (long j=0; j<=n-1; j++)
                if (((y >> j) & 1)==1 && abs(si[i]-si[j])>k)
                  f[i][x]+=f[j][y];
           }

     long long ans=0;
     for (long i=0; i<=n-1; i++)
        ans+=f[i][(1<<n)-1];
     cout << ans;
}
