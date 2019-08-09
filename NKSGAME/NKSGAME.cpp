#include <bits/stdc++.h>

using namespace std;

long long n, a[100007], b[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("NKSGAME.inp","r",stdin);
    //freopen("NKSGAME.out","w",stdout);
    cin >> n; bool ok1=true, ok2=true;
    for (long i=1; i<=n; i++)
        {cin >> a[i]; if (a[i]<0) ok1=false;};
    for (long i=1; i<=n ; i++)
        {cin >> b[i]; if (b[i]<0) ok2=false;};

    if (ok1 && ok2)
     {
        sort(a+1,a+n+1); sort(b+1,b+n+1);
        cout << abs(a[1]+b[1]);
     }
    else
     {
        long long ans=LONG_LONG_MAX;
        for (long i=1; i<=n; i++)
            for (long j=1; j<=n; j++)
              ans=min(ans,abs(a[i]+b[j]));
        cout << ans;
     }
}
