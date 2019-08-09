#include <bits/stdc++.h>

using namespace std;

long k,n,si[20],x[20],ans=0;
bool dd[20];

void tinh()
{
    bool ok=true;
    for (long i=1; i<=n-1; i++)
      if (abs(si[x[i]]-si[x[i+1]])<=k) {ok=false; break;};
    if (ok) ans++;
}

void giai( long i)
{
    for (long j=1; j<=n; j++)
      if (dd[j])
      {
         x[i]=j;
         dd[j]=false;
         if (i==n) tinh();
         else giai(i+1);
         dd[j]=true;
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MIXUP2.inp","r",stdin);
    freopen("MIXUP2.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
        cin >> si[i];
    memset(dd,true,sizeof(dd));
    giai(1);
    cout << ans;
}
