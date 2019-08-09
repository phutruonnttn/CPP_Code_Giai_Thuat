#include <bits/stdc++.h>

using namespace std;

string t,s[300];

int main()
{
    freopen("PASSWORD.inp","r",stdin);
    freopen("PASSWORD.out","w",stdout);
    cin >> t; long d=1; t[t.length()+1]='a';
    for (long i=0; i<=t.length()-1; i++)
    {
       if (('0'<=t[i]) && (t[i]<='9')) s[d]+=t[i];
       if (((t[i]<'0') || (t[i]>'9')) && (('0'<=t[i+1]) && (t[i+1]<='9'))) d++;

    };
    for (long i=1; i<=d-1; i++)
        cout << s[i] << endl;
}
