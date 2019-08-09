#include <bits/stdc++.h>

using namespace std;
const long long b=727, m=1e9+7, m2=m*m;

string x,y;
long long hashx[100007],hashy,h[100007];

long long get(long l, long r)
{
    return (hashx[r]-hashx[l-1]*h[r-l+1]+m2) % m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("test03.inp","r",stdin);
    freopen("test03.out","w",stdout);
    cin >> x >> y;
    h[0]=1;
    for (long i=1; i<=x.size(); i++)
       h[i]=(h[i-1]*b) % m;
    hashx[0]=x[0]%m;
    for (long i=1; i<x.size(); i++)
       hashx[i]=(hashx[i-1]*b+x[i]) % m;
    hashy=y[0];
    for (long i=1; i<y.size(); i++)
      hashy=(hashy*b+y[i]) % m;
    cout << hashy << " " << get(1,3);
}
