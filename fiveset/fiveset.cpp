#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,w1,w2,a[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("fiveset.inp","r",stdin);
    freopen("fiveset.out","w",stdout);
    cin >> n >> w1 >> w2;
    for (long i=1; i<=n; i++) cin >> a[i];
    if (n==5)
    {
        cout << w1*(a[1]+a[5])+w2*(a[2]+a[4])+a[3];
        return 0;
    }
    if (w1==w2 && w1==0)
    {
        for (long i=2; i<=n; i++) a[1]=max(a[1],a[i]);
        cout << a[1];
        return 0;
    }
    if (w1==0 && w2<0)
    {
        long long ans=0,c=3;
        for (long i=4; i<=n-2; i++)
           if (a[i]>a[c])
    }
}
