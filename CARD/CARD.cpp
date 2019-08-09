#include <bits/stdc++.h>

using namespace std;

long long n,a[200],f[105][105];

long long giai(long l, long r)
{
    if (l==r-2) return a[l]*a[r-1]*a[r];
    if (l==r-1) return 0;
    if (f[l][r]!=-1) return f[l][r];
    f[l][r]=100000000000;
      for (long k=l+1; k<=r-1; k++)
        f[l][r]=min(f[l][r],giai(l,k)+giai(k,r)+a[l]*a[r]*a[k]);
    return f[l][r];
}

int main()
{
    freopen("CARD.inp","r",stdin);
    freopen("CARD.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    memset(f,-1,sizeof(f));
    cout << giai(1,n);
}
