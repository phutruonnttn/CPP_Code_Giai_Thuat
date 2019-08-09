#include <bits/stdc++.h>

using namespace std;

long long a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SQU.inp","r",stdin);
    freopen("SQU.out","w",stdout);
    cin >> a >> b;
    if (a==b) cout << a;
    else
      if (a==1) cout << b;
        else
           if (b==1) cout << a;
             else cout <<a+b-__gcd(a,b);
}
