#include <bits/stdc++.h>

using namespace std;

long n,m,a[1007],b[1007],c[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("test07.inp","r",stdin);
    freopen("test07.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) cin >> a[i];
    for (long i=1; i<=m; i++) cin >> b[i];
    a[n+1]=1e9+7; b[m+1]=1e9+7;
    long dem=0,l1=1,l2=1;
    while (dem<=m+n)
    {
        if (a[l1]<=b[l2]) c[++dem]=a[l1++];
        else c[++dem]=b[l2++];
    }
    for (long i=1; i<=n+m; i++)
       cout << c[i] << " ";
}
