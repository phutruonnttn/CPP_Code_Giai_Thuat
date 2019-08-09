#include <bits/stdc++.h>

using namespace std;

long long t,n,m,k,f[100][100][10];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TPCNINJA.inp","r",stdin);
    freopen("TPCNINJA.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n >> k >> m;
        for (long i=1; i<=n; i++) {f[i][i][0]=1; f[i][1][0]=1;}
        f[k][1][0]=0;

        for (long i=3; i<=n; i++)
        {
            for (long j=2; j<=i-1; j++)

        }
    }
}
