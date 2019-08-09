#include <bits/stdc++.h>

using namespace std;

string s,res;
long n,ans;

bool ktra(long k)
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NOREPEAT.inp","r",stdin);
    freopen("NOREPEAT.out","w",stdout);
    cin >> s;
    n=s.size();
    long l=1, r=n;
    while (l<=r)
    {
        long mid=(l+r)/2;
        if (ktra(mid))
        {
            ans=mid;
            l=mid;
        }
        else r=mid;
    }
    cout << ans << endl;
    cout << res;
}
