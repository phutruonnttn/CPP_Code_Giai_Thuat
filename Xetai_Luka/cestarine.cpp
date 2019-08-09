#include <bits/stdc++.h>

using namespace std;

long n,x[100007],y[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cestarine.inp","r",stdin);
    freopen("cestarine.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    for (long i=n; i>=1;i--)
      if (x[i]==y[i])
         {
           /*if (i==1) swap(y[i],y[i+1]);
           else swap(y[i],y[i-1]);*/
           long tg=i+1;
            if (tg!=n) tg=tg%n;
           swap(y[i],y[tg]);
         }
    long ans=0;
    for (long i=1; i<=n; i++)
            ans+=abs(x[i]-y[i]);
    cout << ans << endl;
}
