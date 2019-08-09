#include <bits/stdc++.h>

using namespace std;

long n;
bool prime[100007];

void Sangnt( long n)
{
  memset(prime,true,sizeof(prime));
  prime[1]=false;
  for (long i=2; i<=int(sqrt(n)) ; i++)
        if (prime[i])
  {
      long j=i*i;
      while (j<=n)
      {
          prime[j]=false;
          j=j+i;
      }
  }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sangnt.inp","r",stdin);
    freopen("sangnt.out","w",stdout);
    cin >> n;
    Sangnt(n);
    for (long i=1; i<=n; i++)
        if (prime[i]) cout << i << " ";
}
