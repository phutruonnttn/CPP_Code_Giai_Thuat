#include <bits/stdc++.h>

using namespace std;

long n;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BINARYGEN.inp","r",stdin);
    freopen("BINARYGEN.out","w",stdout);
    cin >> n;
    cin >> s;
    bool ok=true;
    for (long i=0; i<n; i++)
      if (s[i]!='1')
      {
          ok=false;
          break;
      }
    if (ok) cout << "-1";
    else
    {
        long vt=-1;
        for (long i=n-1; i>=0; i--)
          if (s[i]=='0')
          {
             vt=i;
             break;
          }
        for (long i=n-1; i>=vt+1; i--)
           s[i]='0';
        s[vt]='1';
        cout << s;
    }
}
