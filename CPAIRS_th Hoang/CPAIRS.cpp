#include <bits/stdc++.h>

using namespace std;

long long m,n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CPAIRS.inp","r",stdin);
    freopen("CPAIRS.out","w",stdout);
    cin >> m >> n >> k;
    long long ans=0;
    ans=ans+(m/k+1)*(n/k+1);
    ans=ans+(m/k)*(n/k)*(k-1);
    ans=ans+(m-k*(m/k))*(n/k)+(n-k*(n/k))*(m/k);
    long long du1=m-k*(m/k), du2=n-k*(n/k);
    if (du1<=du2)
    {
        long long ll1=0;
        ans=ans+max(ll1,du1-(k-1-du2));
    }
    else
    {
        long long ll1=0;
        ans=ans+max(ll1,du2-(k-1-du1));
    }
    cout << ans;
}
