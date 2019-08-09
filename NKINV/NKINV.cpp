#include <bits/stdc++.h>

using namespace std;

long n,a[60007],t[60007] ;

long long get(long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&-x);
    }
    return res;
}

void update(long x, long d)
{
    while (x<=60007)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}

int main()
{
    //freopen("NKINV.inp","r",stdin);
    //freopen("NKINV.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n;i++)
        cin >> a[i];
    memset(t,0,sizeof(t));
    long long res=0;
    for (long i=n; i>=1; i--)
    {
        res+=get(a[i]-1);
        update(a[i],1);
    }
    cout << res;
}
