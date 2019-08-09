#include <bits/stdc++.h>
#define nmax 100007
#define nmod 1000000007

using namespace std;

long long n,k,f[nmax],g[nmax],ans,m2;

long long mu(long k, long l)
{
    long long res=1;
    for (long i=1; i<=l; i++) res=(k*res)%nmod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LUCKYNUM.inp","r",stdin);
    freopen("LUCKYNUM.out","w",stdout);
    cin >> n >> k;
    m2=nmod*nmod;
    ans=(9*mu(10,n-1)) % nmod;
    if (k==1)
    {
        if (n==1)
        {
            cout << 1;
            return 0;
        }
        long long c=(8*mu(9,n-1))%nmod;
        cout << (ans-c)%nmod;
        return 0;
    }
    f[0]=1;
    f[1]=8; g[1]=1;
    for (long i=2; i<=n; i++)
    {
        f[i]=( (f[i-1]+g[i-1])*9 ) % nmod;
        /*if (f[i-1]+g[i-1]-f[i-k]<0) g[i]=(f[i-1]+g[i-1]-f[i-k]+m2) %nmod;
        else*/ g[i]=(f[i-1]+g[i-1]-f[i-k]) %nmod;
        //cout << f[i] << " " << g[i] << endl;
    }
    cout << (ans-f[n]-g[n])%nmod;
}
