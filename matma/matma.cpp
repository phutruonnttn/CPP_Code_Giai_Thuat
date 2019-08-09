#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;
const long long b=37, m=1000000000+7,m2=m*m;

long long n,f[100000000];
string x;
long long h[10000007],s[100000007];

long long get(long l, long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("matma.inp","r",stdin);
    freopen("matma.out","w",stdout);
    cin >> n;
    cin >> x;

    h[0]=1; h[1]=b;

    for (long i=2; i<=n; i++)
        h[i]=(h[i-1]*b) % m;

    s[0]=(x[0]) % m;
    for (long i=1;i<=n-1; i++)
        s[i]=((s[i-1]*b)+x[i]) % m;



}
