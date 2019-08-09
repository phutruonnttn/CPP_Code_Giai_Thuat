#include <bits/stdc++.h>

using namespace std;

long long m,n,thuyen[2007],nguoi[2007],k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SAPBE.inp","r",stdin);
    freopen("SAPBE.out","w",stdout);
    cin >> n >> m;
    long long dem=0;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=m; j++)
        cin >> thuyen[++dem];
    cin >> k;
    for (long i=1; i<=k; i++) cin >> nguoi[i];
    sort(thuyen+1,thuyen+m*n+1);
    sort(nguoi+1,nguoi+k+1);
    //for (long i=1; i<=k; i++) cout << nguoi[i] << " ";
    long long dt=m*n, dn=k,ans=0;
    while (dt!=0 && dn!=0)
    {
       if (nguoi[dn]<=thuyen[dt])
       {
           ++ans;
           dt--;
           dn--;
       }
       else
       {
           dn--;
       }
    }
    cout << ans;
}
