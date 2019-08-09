#include <bits/stdc++.h>
#define nmod 1000000000

using namespace std;

long n,dx[10]={1,1,0,-1,-1,0},dy[10]={0,-1,-1,0,1,1};
long long f[57][107][107];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BEE.inp","r",stdin);
    freopen("BEE.out","w",stdout);
    cin >> n;
    f[0][51][51]=1;
    for (long k=1; k<=n; k++)
      for (long i=1; i<=100; i++)
        for (long j=1; j<=100; j++)
          for (long x=0; x<=5; x++)
             f[k][i][j]=(f[k][i][j]+f[k-1][i+dx[x]][j+dy[x]]) % nmod;
    cout << f[n][51][51];
}
