#include <bits/stdc++.h>

using namespace std;

long long m,n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CUT.inp","r",stdin);
    freopen("CUT.out","w",stdout);
    cin >> m >> n >> k;

    if (m+n-2<=k)
    {
        cout << m*n;
        return 0;
    }
    else
    {
        if (m>n) swap(m,n);
        long long nua=k/2;
        if (m-1<=k/2) cout << m*(k-m+2);
        else
            if (k%2==0) cout << (k/2+1)*(k/2+1);
             else cout << (k/2+1)*(k/2+2);
    }
}
