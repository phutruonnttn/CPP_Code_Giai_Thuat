#include <bits/stdc++.h>
#define nmax 200007
#define mmax 200000007

using namespace std;

long long n,m,f[nmax],sl=0,a[mmax],ll=0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BUS.inp","r",stdin);
    freopen("BUS.out","w",stdout);
    cin >> n >> m;
    f[1]=0;
    for (long i=1; i<=n; i++)
    {
        long u,k,v; cin >> u >> k;
        f[i+1]=f[i]+u;
        for (long j=1; j<=k; j++)
        {
            cin >> v;
            a[++sl]=max(ll,v-f[i]);
            //cout << sl << " " << a[sl] << endl;
        }
    }
    sort(a+1,a+sl+1);
    cout << f[n+1]+a[m];
}
