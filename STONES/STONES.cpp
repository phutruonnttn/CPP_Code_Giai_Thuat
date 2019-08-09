#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
    freopen("STONES.inp","r",stdin);
    freopen("STONES.out","w",stdout);
    cin >> n;
    if (n==0) cout << 0 << " " << 0;
    else
    {
    double u=(double)sqrt(n);
    if (u!=round(u)) u=trunc(u)+1;
    double v=double(n) / u;
    if (v!=round(v)) v=trunc(v)+1;
    cout << (long long)u << " " << (long long)v;
    }
}

