#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,q,m=0;
string s[nmax],f[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TTXau.inp","r",stdin);
    freopen("TTXau.out","w",stdout);
    cin >> n >> q;
    for (long i=1; i<=n; i++) cin >> s[i];
    sort(s+1,s+n+1);
    s[0]="****";
    for (long i=1; i<=n; i++)
       if (s[i]!=s[i-1]) f[++m]=s[i];
    for (long i=1; i<=q; i++)
    {
        long j,l;
        string t;
        cin >> j;
        if (j==1)
        {
            cin >> t;
            long cs=lower_bound(f+1,f+m+1,t)-f;
            if (f[cs]==t) cout << cs;
            else cout << -1;
            cout << '\n';
        }
        else
        {
            cin >> l;
            if (1<=l && l<=m) cout << f[l];
            else cout << -1;
            cout << '\n';
        }
    }
}
