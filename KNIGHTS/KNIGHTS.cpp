#include <bits/stdc++.h>
#define nmod 1e9+9

using namespace std;

long n,m,tt[200];

int main
{
    ios_base::sync_with_stdio(0);
    freopen("KNIGHTS.inp","r",stdin);
    freopen("KNIGHTS.out","w",stdout);
    cin >> n >> m;
    long dem=0;
    for (long i=0; i<=256; i++)
    {
        long a=i>>4, b=i%16;
        if ((a>>2)&b==0 && (b>>2)&a==0) tt[++dem]=i;
    }

}
