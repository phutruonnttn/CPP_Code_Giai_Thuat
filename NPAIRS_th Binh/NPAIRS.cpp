#include <bits/stdc++.h>

using namespace std;

long long m,n,k,t,ans;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NPAIRS.inp","r",stdin);
    freopen("NPAIRS.out","w",stdout);
    cin >> t;
    while (t--)
    {
       cin >> n >> m;
       long long x=n/m,y=n%m;
       ans=(m-1)*x*x+x*(x-1);
       if (m%2==0) ans-=x;
       ans/=2;
       ans+=x*y;
       if (y>m/2) ans+=y-(m/2);
       cout << ans << '\n';
    }
}
