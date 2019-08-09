#include <bits/stdc++.h>

using namespace std;

long long n,minn=10000000000,maxx=-10000000000,a[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("suadiem.inp","r",stdin);
    freopen("suadiem.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i];
        maxx=max(a[i],maxx);
        minn=min(a[i],minn);
    }
    for (long i=1; i<=n; i++)
       if (a[i]==maxx) a[i]=minn;
    for (long i=1; i<=n; i++)
       cout << a[i] << " ";
}
