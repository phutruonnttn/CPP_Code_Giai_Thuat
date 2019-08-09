#include <bits/stdc++.h>

using namespace std;
const long long b=37, m=1000000000+7,m2=m*m;

string s;
long k;
long long h[300007],s1[300007],s2[300007];

long long get1(long l, long r)
{
    return ((s1[r]-s1[l-1]*h[r-l+1]+m2) % m);
}

long long get2(long l, long r)
{
    return ((s2[r]-s2[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STRPALIN.inp","r",stdin);
    freopen("STRPALIN.out","w",stdout);
    cin >> s;

    long n=s.size();

    h[0]=1;
    for (long i=1; i<=n; i++)
      h[i]=(h[i-1]*b) % m;

    s1[0]=(s[0]) % m;
    for (long i=1;i<=n-1; i++)
       s1[i]=((s1[i-1]*b)+s[i]) % m;

    char ss[300005];
    for (long i=n-1; i>=0; i--)
       ss[n-i-1]=s[i];

    s2[0]=(ss[0]) % m;
    for (long i=1;i<=n-1; i++)
       s2[i]=((s2[i-1]*b)+ss[i]) % m;

    cin >> k;
    for (long i=1; i<=k; i++)
    {
        long l,r;
        cin >> l >> r;
        if (get1(l-1,l+((r-l+1)/2)-2)==get2(n-r,n-r+((r-l+1)/2)-1)) cout << 1 << endl;
        else cout << -1 << endl;
    }
}
