#include <bits/stdc++.h>

using namespace std;

long a,b;

long UCLN(long a, long b)
{
  /*if (a % b==0) return b;
  else return UCLN(b, a % b);*/
  return (b==0) ? a : UCLN(b,a % b);
}

int main()
{
  freopen("Euclid.inp","r",stdin);
  freopen("Euclid.out","w",stdout);
  cin >> a >> b;
  cout << UCLN(a,b);
}
