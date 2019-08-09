#include <bits/stdc++.h>

using namespace std;

long k,u,v;
string s,s1;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FIBVAL.inp","r",stdin);
    freopen("FIBVAL.out","w",stdout);
    //cin >> k;
    s="1235813213455891442333776109871597";
    s1="1235813213455891442333776109871597";
    for (long i=0; i<s.size(); i++)
    {
      if (s[i]=='1' || s[i]=='8') s1[i]='C';
      if (s[i]=='2' || s[i]=='9') s1[i]='D';
      if (s[i]=='3') s1[i]='E';
      if (s[i]=='4') s1[i]='F';
      if (s[i]=='5') s1[i]='G';
      if (s[i]=='6') s1[i]='A';
      if (s[i]=='7') s1[i]='B';
    }
    cout << s1;
}
