#include <bits/stdc++.h>

using namespace std;

long n;
long long a[500007],ans=0,dem[500007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("patrik.inp","r",stdin);
    freopen("patrik.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    long s[500007];
    long long top=0;
    for (long i=1; i<=n; i++)
    {
        while (s[top]<a[i] && top>=1)
        {
            ans+=dem[top];
            --top;
        }
        if (s[top]==a[i])
        {
            ans+=dem[top];
            dem[top]++;
            if (top>1) ans++;
        }
        else
        {
            if (top>=1) ans++;
            top++; s[top]=a[i];
            dem[top]=1;
        }
    }
    cout << ans;
}
