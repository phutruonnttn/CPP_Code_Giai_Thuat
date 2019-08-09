#include <bits/stdc++.h>

using namespace std;

string a;
long long ans=0;

void chuanhoa(string &a,string &b)
{
    while (a.size() < b.size()) a="0"+a;
    while (a.size() > b.size()) b="0"+b;
}

string sub(string a,string b)
{
   string c=""; long muon=0;
   chuanhoa(a,b);
   for (long i=a.size()-1; i>=0; i--)
    {
        long x=a[i]-48;
        long y=b[i]-48;
        long h=x-y-muon;
        if (h<0) {h=h+10; muon=1;}
        else muon=0;
        c=char(h+48) +c;
     }
   while (c.size()>1 && c[0]=='0') c.erase(0,1);
   return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("digitsum.inp","r",stdin);
    freopen("digitsum.out","w",stdout);
    cin >> a;
    string b="";
    for (long i=1; i<=a.size()-1; i++)
        {b="9"+b; ans+=9;}
    if (b=="") b="0";
    string c=sub(a,b);
    for (long i=0; i<c.size(); i++)
        ans+=(c[i]-48);
    cout << ans << '\n';
    cout << b << " " << c;
}
