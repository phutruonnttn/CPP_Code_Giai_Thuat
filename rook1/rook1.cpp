#include <bits/stdc++.h>
#define nmod 1000001

using namespace std;

long n,m,k,t,c[67][67];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rook1.inp","r",stdin);
    freopen("rook1.out","w",stdout);
    cin >> t;
    for (long i=1; i<=60; i++)
      {
          c[i][i]=1;
          c[1][i]=i;
          c[0][i]=1;
      }
    for (long i=2; i<=60; i++)
      for (long j=2; j<=60; j++)
        if (j>i) c[i][j]=(c[i][j-1]+c[i-1][j-1])%nmod;


    for (long ii=1; ii<=t; ii++)
    {
        cin >> m >> n >> k;
        if (n>m) swap(n,m);
        if (k>n || k>m)
        {
            cout << 0 << endl;
            continue;
        }
        long long ans=n;
        for (long i=1;i<k; i++)
        {
            ans=(ans*(n-1))%nmod;
            n--;
        }
        long th=m-k;
        ans=(ans*c[th][m])%nmod;
        cout << ans << endl;
    }
}
