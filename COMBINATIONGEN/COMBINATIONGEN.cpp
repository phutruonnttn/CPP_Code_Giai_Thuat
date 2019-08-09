#include <bits/stdc++.h>

using namespace std;

long n,m,a[10007];
bool dd[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("COMBINATIONGEN.inp","r",stdin);
    freopen("COMBINATIONGEN.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++) cin >> a[i];
    memset(dd,true,sizeof(dd));
    dd[n+1]=false;
    bool ok=false;
    for (long i=m; i>=1; i--)
      {if (dd[a[i]+1])
      {
         ok=true;
         a[i]++;
         long dem=0;
         for (long j=i+1; j<=m; j++) a[j]=a[i]+(++dem);
         break;
      }
      dd[a[i]]=false;}
      if (!ok) cout << "-1";
      else{
      for (long i=1; i<=m; i++) cout << a[i] << " ";}
}
