#include <bits/stdc++.h>
#define nmax 300007

using namespace std;

long long n,k,a[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("KDIFF.inp","r",stdin);
    freopen("KDIFF.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) cin >> a[i];
    long long l=1, dd=1, d1, c1, r=1, ans1=-1, minn=a[1], maxx=a[1];
    for (long i=2; i<=n; i++)
    {
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
        if (maxx-minn<=k)
        {
            r++;
            dd++;
            if (dd>ans1)
            {
                ans1=dd;
                d1=l; c1=r;
            }
        }
    }
}
