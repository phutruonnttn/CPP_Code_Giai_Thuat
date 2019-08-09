#include <bits/stdc++.h>
#define nmax 2000007

using namespace std;

long long n,m,a[nmax],f[nmax];
long long ans=0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CARDIFF.inp","r",stdin);
    freopen("CARDIFF.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) {cin >> a[i]; f[a[i]]++;}
    for (long i=1000000; i>=1; i--)
       f[i]+=f[i+1];
    for (long x=1000000; x>=1; x--)
    {
      if (m==0) break;
      if (m>=f[x])
       {
          ans+=x*f[x];
          m-=f[x];
          if (m==0) break;
       }
      else {ans+=m*x; m=0; break;}
     }
    cout << ans;
}
