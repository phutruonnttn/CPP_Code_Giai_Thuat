#include <bits/stdc++.h>
#define nmod  20122007

using namespace std;
long long a;

long long power(long x)
{
     if (x==1) return 3;
     long long u=power(x/2) % nmod;
     u=(u*u)%nmod;
     if (x%2==1) return (u*3)%nmod;
     return u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MYSTERY.inp","r",stdin);
    freopen("MYSTERY.out","w",stdout);
    cin >> a;
    long long ans=1;
    for (long i=1; i<=sqrt(a); i++)
      if (a % i==0)
        {
          if (i*i==a) ans=ans*(power(i)-1 + nmod) % nmod;
          else ans=((ans*(power(i)-1 + nmod) % nmod)*(power(a/i)-1 + nmod))%nmod;
        }
    cout << ans;
}
