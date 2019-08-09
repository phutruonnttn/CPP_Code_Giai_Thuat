#include <bits/stdc++.h>

using namespace std;

string s;
long n;

long tinh(long u, long v)
{
    long ans=0;
    for (long i=u; i<=v; i++)
    {
      if (s[i]=='(')
      {
          long k;
          for (long j=i; j<=v; j++)
            if (s[j]==')')
            {
               k=j;
               break;
            }
          ans+=(tinh(i+1,k-1))*(s[k+1]-48);
          i=k+2;
      }
      if (s[i]<=57 && s[i]>=50)
       {
          if (s[i-1]=='H') ans+=(s[i]-48);
          if (s[i-1]=='O') ans+=16*(s[i]-48);
          if (s[i-1]=='N') ans+=14*(s[i]-48);
          if (s[i-1]=='C') ans+=12*(s[i]-48);
       }
      if ((s[i]>57 || s[i]<50) && (s[i+1]>57 || s[i+1]<50))
      {
          if (s[i]=='H') ans+=1;
          if (s[i]=='O') ans+=16;
          if (s[i]=='N') ans+=14;
          if (s[i]=='C') ans+=12;
      }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("H2O.inp","r",stdin);
    freopen("H2O.out","w",stdout);
    cin >> s;
    n=s.size();
    s="0"+s;
    cout << tinh(1,n);
}
