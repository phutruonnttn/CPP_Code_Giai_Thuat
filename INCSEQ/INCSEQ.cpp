#include <bits/stdc++.h>

using namespace std;

long long n,k,s[10007],f[10007][20];


int main()
{
    freopen("INCSEQ.inp","r",stdin);
    freopen("INCSEQ.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
        cin >> s[i];
    memset(f,0,sizeof(f));
    for (long i=1; i<=n; i++)
    {
      for (long l=1; l<=k; l++)
        for (long j=1; j<=i-1; j++)
          f[i][l]=f[j][l-1];
    }
}

