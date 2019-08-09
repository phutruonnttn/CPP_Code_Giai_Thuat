#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long n;
bool prime[nmax];

void sangnt()
{
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for (long i=2; i<=trunc(sqrt(nmax)); i++)
     if (prime[i])
     {
         long j=i*i;
         while (j<=nmax)
         {
             prime[j]=false;
             j=j+i;
         }
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("test13.inp","r",stdin);
    freopen("test13.out","w",stdout);
    cin >> n;
    sangnt();
    for (long i=1; i<=n; i++)
       if (prime[i]) cout << i << " ";
}
