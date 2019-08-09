#include <bits/stdc++.h>
#define nmax 1000007

long long m,q,a[nmax],p[nmax],mx[nmax],b,e;
map <long, long> M;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("UNIQUEK.inp","r",stdin);
    freopen("UNIQUEK.out","w",stdout);
    while (1<2)
    {
        cin >> m >> q;
        if (m==0 && q==0) return 0;
        for (long i=1; i<=m; i++) cin >> a[i];

        M.clear();
        for (long i=1; i<=m; i++) p[i]=0;
        for (long i=1; i<=m; i++)
        {
            p[i]=M[a[i]];
            M[a[i]]=i;
        }
        mx[1]=a[1];
        for (long i=2; i<=m; i++)
             mx[i]=max(mx[i-1],a[i]);
        for (long i=1; i<=q; i++)
        {
            cin >> b >> e;
            if (mx[e]<b) cout << "OK" << '\n';
            else cout << a[mx[e]] << '\n';
        }
        cout << '\n';
    }
}
