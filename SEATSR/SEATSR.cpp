#include <bits/stdc++.h>

using namespace std;

string s,w;
long a,b,k,f[10007][10007];

void xuli()
{
    long m=s.size(), n=w.size();
    for (long i=1; i<=max(m,n); i++)
    {
        f[0][i]=i*a;
        f[i][0]=i*a;
    }
    for (long i=1; i<=m; i++)
       for (long j=1;j<=n; j++)
          f[i][j]=min(f[i-1][j]+a,min(f[i][j-1]+a,f[i-1][j-1]+b*(s[i-1]!=w[j-1])));

    if (f[m][n]>k) cout << -1 << endl;
    else cout << f[m][n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SEATSR.inp","r",stdin);
    freopen("SEATSR.out","w",stdout);
    long t; cin >> t;
    for (long i=1; i<=t; i++)
    {
        cin >> s;
        cin >> w;
        cin >> a >> b >> k;
        xuli();
    }
}
