#include <bits/stdc++.h>

using namespace std;

long n,f[10007],c[10007];
string s;

int main()
{
    freopen("SETNJA.inp","r",stdin);
    freopen("SETNJA.out","w",stdout);
    cin >> s;
    n=s.size();
    f[0]=1; c[0]=1;
    for (long i=0;i<=n-1; i++)
    {
        if (s[i]=='L') {f[i+1]=f[i]*2; c[i+1]=c[i];};
        if (s[i]=='R') {f[i+1]=f[i]*2+c[i]; c[i+1]=c[i];};
        if (s[i]=='P') {f[i+1]=f[i]; c[i+1]=c[i];};
        if (s[i]=='*') {c[i+1]=c[i]*3; f[i+1]=5*f[i]+c[i];};
    }
    cout << f[n];
}
