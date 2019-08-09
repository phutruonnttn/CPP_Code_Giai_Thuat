#include <bits/stdc++.h>

using namespace std;

long long a,b,f[21][11][11];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GERM.inp","r",stdin);
    freopen("GERM.out","w",stdout);
    cin >> a >> b;
    for (long i=0; i<=9; i++)
      for (long j=0; j<=9; j++)
        if (i!=j) f[2][i][j]=1;

    for (long k=3; k<=20; k++)
      for (long i=0; i<=9; i++)
        for (long j=0; j<=9; j++)
          for (long p=0; p<=9; p++)
             /*if (p!=i)*/ f[k][i][j]+=f[k-1][j][p];
    cout << f[3][1][2];
}
