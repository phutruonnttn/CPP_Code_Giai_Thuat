#include <bits/stdc++.h>
#define nmod 1000007

using namespace std;

long long k,n,f[100007];

long long lt(long l)
{
    long long ans=1;
    for (long i=1;i<=l;i++)
        ans=(ans*2);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bitstr.inp","r",stdin);
    freopen("bitstr.out","w",stdout);
    cin >> n >> k;
    f[0]=1;
    for (long i=1; i<=n+1; i++)
        for (long j=0; j<=k; j++)
           if (i>=j) f[i]=(f[i]+f[i-j]);
    cout << (lt(n)%nmod-((f[n+1])%nmod)) ;//%nmod;
}
