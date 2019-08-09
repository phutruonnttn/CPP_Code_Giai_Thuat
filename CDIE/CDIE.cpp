#include <bits/stdc++.h>
#define nmax 57

using namespace std;

long n,m,a[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CDIE.inp","r",stdin);
    freopen("CDIE.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);

    //for (long i=1; i<=n; i++) cout << a[i] << " ";cout <<endl;

    long ans=0,ct=1;
    bool ok=false;
    for (long i=n; i>=1; i--)
    {
        ans++;
        ct=ct-1+a[i];
        if (ct>=m)
        { ok=true; break;}
    }
    if (m==1) cout << 0;
    else if (!ok) cout <<-1;
    else cout << ans;
}
