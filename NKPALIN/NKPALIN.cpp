#include <bits/stdc++.h>
#define nmax 2007

using namespace std;

string s;
long f[nmax][nmax],n;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKPALIN.inp","r",stdin);
    freopen("NKPALIN.out","w",stdout);
    cin >> s;
    n=s.size();
    for (long i=0; i<n; ++i)
       f[i][i]=1;
    for (long i=n-1; i>=0; --i)
      for (long j=i+1; j<n; ++j)
        if (s[i]==s[j]) f[i][j]=f[i+1][j-1]+2;
        else f[i][j]=max(f[i+1][j],f[i][j-1]);
    long i=0, j=n-1;
    string st="", st1="";
    while (i<=j)
    {
     if (s[i]==s[j])
       {
         st=st+s[i];
         st1=s[j]+st1;
         i++; j--;
       }
     else
       if (f[i+1][j]==f[i][j]) i++;
       else j--;
    }
    for (long i=1; i<st1.size(); ++i)
       st=st+st1[i];
    cout << st;
}
