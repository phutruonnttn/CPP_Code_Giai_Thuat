#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

long n,a[100007];
int f[10000][10000];

int main()
{
    freopen("SUBSEQ.inp","r",stdin);
    freopen("SUBSEQ.out","w",stdout);
    cin >> n ;
    for (long i=1; i<=n; i++)
        cin >> a[i];

    for (long i=1; i<=n; i++)
        f[1][i]=1;

    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
      {
        for (long j1=1; j1<=j-1; j1++)
          if (a[j1]<a[j])
            f[i][j]=(f[i][j]+f[i-1][j1]) % nmod;
      }


    long long ans1;
    for (long k=1; k<=n; k++)
    {
        long long ans=0;
        for (long i=1; i<=n; i++)
          ans=(ans+f[k][i]) % nmod;
        if (ans==0)
        {
            cout << ans1;
            return 0;
        }
        ans1=ans;
    }
}
