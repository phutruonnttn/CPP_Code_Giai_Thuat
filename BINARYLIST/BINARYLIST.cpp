#include <bits/stdc++.h>

using namespace std;

long n,k,ct;
string s="";

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BINARYLIST.inp","r",stdin);
    freopen("BINARYLIST.out","w",stdout);
    cin >> n >> k >> ct;
    for (long i=1; i<=n; i++) s+='0';
    long vt=-1;
    while (vt<=n-1)
    {
        vt+=ct;
        if (vt>n-1) break;
        s[vt]='1';
    }

    for (long ii=1; ii<=k-1; ii++)
    {
        long vt=-1;
        for (long i=n-1; i>=0; i--)
           if (s[i]=='0')
            {
               vt=i;
               break;
            }
        if (vt==-1)
        {
            cout << -1;
            return 0;
        }
        s[vt]='1';
        for (long i=vt+1; i<=n-1; i++) s[i]='0';
        vt=vt+ct;
        while (vt<=n-1)
        {
          s[vt]='1';
          vt+=ct;
        }
    }
    for (long i=0; i<=n-1; i++) cout << s[i] << " ";
}
