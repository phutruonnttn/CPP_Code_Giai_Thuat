#include <bits/stdc++.h>
#define nmax 100007
#define oo 1000000008

using namespace std;

long long n,a[nmax],ans=1,d[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DIVSEQ.inp","r",stdin);
    freopen("DIVSEQ.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    d[1]=a[n];
    for (long i=n-1; i>=1; i--)
    {
        long vt=lower_bound(d+1,d+ans+1,a[i])-d;
        if (vt==ans+1)
        {
            ans++;
            d[vt]=a[i];
        }
        else d[vt]=a[i];
    }
    cout << ans;
}
