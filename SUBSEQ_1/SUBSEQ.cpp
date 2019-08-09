#include <bits/stdc++.h>

using namespace std;

long n,k,a[1000007],s[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SUBSEQ.inp","r",stdin);
    freopen("SUBSEQ.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) cin >> a[i];

    s[0]=0;
    for (long i=1; i<=n; i++) s[i]=s[i-1]+a[i];

    //for (long i=1; i<=n; i++) cout << s[i] << " "; cout << endl;

    long smin=s[0], ans=s[k];
    for(int i=k+1; i<=n; i++)
      {
         smin=min(smin,s[i-k]);
         ans=max(ans,s[i]-smin);
         //cout << smin << " " << ans << endl;
      }
    cout << ans;
}
