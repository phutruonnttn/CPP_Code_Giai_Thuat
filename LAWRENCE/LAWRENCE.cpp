#include <bits/stdc++.h>

using namespace std;

long long n,m,gtri[600],a[600];
bool dd[600];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LAWRENCE.inp","r",stdin);
    freopen("LAWRENCE.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    memset(gtri,0,sizeof(gtri));
    for (long i=1; i<=n-1; i++)
    {
        for (long j=i+1; j<=n;j++ )
            gtri[i]+=(a[i]*a[j]);
    }
    //for (long i=1; i<=n-1; i++) cout << gtri[i] << " ";
    memset(dd,true,sizeof(dd));
    for (long i=1;i<=m; i++)
    {
        long long maxx=-1,k;
        for (long j=1; j<=n-1;j++)
          if (dd[j])
          {
              if (gtri[j]>maxx)
              {
                  maxx=gtri[j];
                  k=j;
              }
          }

        dd[k]=false;
    }
    long long ans=0;
    for (long i=1; i<=n-1; i++)
      {if (dd[i])
        for (long j=i+1; j<=n; j++)
          {
            if (dd[j]==false) break;
            ans+=a[i]*a[j];
          }}
    cout << ans;
}
