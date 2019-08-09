#include <bits/stdc++.h>

using namespace std;

long p,d;
string pi;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("PIFIVE.inp","r",stdin);
    //freopen("PIFIVE.out","w",stdout);
    cin >> p >> d;
    pi="31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    long q,r,n=pi.size();
    for (long i=d; i<=n-1; i++)
      if ((long)pi[i] -48 ==d) {q=i;break;};
    cout << pi[q] << " " << "5";
}
