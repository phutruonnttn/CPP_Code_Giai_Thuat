#include <bits/stdc++.h>

using namespace std;

string s;
char x,y;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VMRR.inp","r",stdin);
    freopen("VMRR.out","w",stdout);
    getline(cin,s);
    string tmp;
    cin >> tmp;
    x=tmp[0]; y=tmp[1];
    if (x==y)
    {
        long long ans=0,d=0;
        for (long i=s.size()-1; i>=0; i--) if (s[i]==x) d++;
        for (long i=1; i<=d-1; i++) ans+=i;
        cout << ans;
        return 0;
    }
    long long ans=0,dem=0;
    for (long i=s.size()-1; i>=0; i--)
    {
        if (s[i]==y) dem++;
        if (s[i]==x) ans+=dem;
    }
    cout << ans;
}
