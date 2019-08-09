#include <bits/stdc++.h>

using namespace std;

long n,f[50007]['Z'+7];
string s;

long qhd(long i, long z)
{
    if (i==n+1) return 0;
    if (f[i][z]!=-1) return f[i][z];
    if (s[i]==z) f[i][z]=qhd(i+1,z)+1;
    else f[i][z]=min(qhd(i+1,z)+2,qhd(i+1,s[i])+2);
    return f[i][z];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ispis.inp","r",stdin);
    freopen("ispis.out","w",stdout);
    cin >> s; s='.'+s;
    n=s.size()-1;
    memset(f,-1,sizeof(f));
    cout << qhd(1,s[1])+1;
}
