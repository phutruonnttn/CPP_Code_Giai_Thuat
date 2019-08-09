#include <bits/stdc++.h>

using namespace std;

string s;
long n;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRACKETS.inp","r",stdin);
    freopen("BRACKETS.out","w",stdout);
    cin >> s; n=s.size();
    long dem=0,d=0;
    for (long i=0; i<=n-1; i++)
    {
        if (s[i]==')') dem=dem-1;
        if (s[i]=='(') dem=dem+1;
        //cout << dem << " " << s <<endl;
        if (dem<0)
        {
            s[i]='('; dem+=2; d++;
        }
    }
    if (dem>0)
    {

       for (long i=n-1; i>=1; i--)
       {
          if (s[i]=='(') {s[i]=')';dem-=2; d++;};
          if (dem==0) break;
       }
    }
    cout << d << endl << s;
}
