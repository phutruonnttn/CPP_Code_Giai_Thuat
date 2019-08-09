#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

long long n,k;

long long power(long long x, long long k)
{
    if (k==1) return x;
    long long tmp=power(x,k/2);
    tmp=(tmp*tmp)%nmod;
    if (k%2==1) tmp=(tmp*x)%nmod;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CWORDS.inp","r",stdin);
    freopen("CWORDS.out","w",stdout);
    cin >> n >> k;
    cout << (500000004*(power(k,n)+power(k,(n+1)/2))) % nmod;
}
