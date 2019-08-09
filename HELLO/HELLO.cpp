#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("HELLO.inp","r",stdin);
    //freopen("HELLO.out","w",stdout);
    cin >> s;
    string ss="*hello";
    long d=1;
    for (long i=0; i<s.size(); i++)
      if (s[i]==ss[d]) d++;
    if (d>5) cout << "YES";
    else cout << "NO";
}
