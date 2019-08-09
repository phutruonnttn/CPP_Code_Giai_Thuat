#include <bits/stdc++.h>
#define nmax 5000007

using namespace std;

long n,d,f[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DIVS.inp","r",stdin);
    freopen("DIVS.out","w",stdout);
    cin >> n >> d;
    for (long x=1; x<=n; x++)
       for (long i=x+x; i<=n; i+=x)
         f[i]+=x;
    long ans=0;
    for (long i=1; i<=n; i++)
       if (abs(f[i]-i)<=d) ans++;
    cout << ans;
}
