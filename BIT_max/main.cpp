#include <bits/stdc++.h>

using namespace std;

long long n,a[60007],t[60007];

long long get(long x)
{
    long long res=-1000000000;
    while (x>0)
    {
       //res+=t[x];
       res=max(res,t[x]);
       x-=(x&-x);
    }
    return res;
}

/*void update(long x, long d)
{
    while (x<=60007)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BIT.inp","r",stdin);
    freopen("BIT.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      {cin >> a[i];
      t[i]=a[i];}
    cout << get(n);
}
