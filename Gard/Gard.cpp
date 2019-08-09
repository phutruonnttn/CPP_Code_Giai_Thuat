#include <bits/stdc++.h>
#define nmod 1000000000

using namespace std;

long n,k;
long long ans=0,c[57][57],f[57][57];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Gard.inp","r",stdin);
    freopen("Gard.out","w",stdout);
    cin >> n >> k;
    //c[N][K] to hop chap k cua n
    c[0][0]=1;
    for (long i=1; i<=51; i++)
    {
        c[i][0]=c[i][i]=1;
        for (long j=1; j<=i-1; j++)
           c[i][j]=(c[i-1][j]+c[i-1][j-1])%nmod;
    }
    f[0][0]=1;
    for (long j=1; j<=n; j++)
      for (long i=1; i<=n; i++)
        for (long t=1; t<=min(i,k); t++)
            //f[i][j]=(f[i][j]+((f[i-t][j-1]*c[i][t])%nmod) % nmod);
            {
                f[i][j]+=f[i-t][j-1]*c[i][t];
                f[i][j]%=nmod;
            }
    for (long i=1; i<=n; i++) ans=(ans+f[n][i])%nmod;//cout << f[n][i] << endl;
    cout << ans;
}
