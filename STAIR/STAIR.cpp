#include <bits/stdc++.h>

using namespace std;

long n;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("STAIR.inp","r",stdin);
    //freopen("STAIR.out","w",stdout);
    cin >> n;
    long long ans=0;
    if (n %2==1) ans+=n/2;
    else ans+=(n/2) -1;
    bool ok=true; long rb=6, crb=3;
    while (ok)
    {
        if (n==rb) {ans+=1; ok=false; break;};
        if (n> rb)
        {
            ans+=(n-rb);
            crb+=1;
            rb+=crb;
        };
        if (n<rb) ok=false;
    }
    cout << ans;
}
