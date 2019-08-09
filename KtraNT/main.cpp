#include <bits/stdc++.h>

using namespace std;

long n;

bool ktra(long n)
{
    if ((n==2) || (n==3)) return true;
    if ((n==1) || (n % 2==0) || (n % 3==0)) return false;
    long k=-1;
    do
    {
      k=k+6;
      if ((n%k==0) || (n % (k+2)==0)) break;
    }
    while (k>int(sqrt(n)));
    return (k>int(sqrt(n)));
}

int main()
{
    freopen("KtraNT.inp","r",stdin);
    freopen("KtraNT.out","w",stdout);
    cin >> n;
    if (ktra(n)) cout << "YES";
    else cout << "NO";
}
