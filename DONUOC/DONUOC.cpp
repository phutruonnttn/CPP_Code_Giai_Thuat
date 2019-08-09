#include <bits/stdc++.h>

using namespace std;

long long a,b,n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DONUOC.inp","r",stdin);
    freopen("DONUOC.out","w",stdout);
    cin >> a >> b >> n;
    long long ans=(n-1)*b-(n-2)*a;
    cout << ans;
}
