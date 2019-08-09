#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

long long n,q,a[nmax],b[nmax];

int Get1(int u)
{
    if (a[u]==u) return u;
    a[u]=Get1(a[u]);
    return a[u];
}

void gop1(long x, long y)
{
    long u=Get1(x);// tim goc x
    long v=Get1(y);// tim goc y
    if (u!=v) a[u]=v;
}

int Get2(int u)
{
    if (b[u]==u) return u;
    b[u]=Get2(b[u]);
    return b[u];
}

void gop2(long x, long y)
{
    while(1<2)
    {
       long z=Get2(x)+1;
       if (z>y) break;
       b[z-1]=z;
       gop1(z-1,z);
       x=z;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RESTRUCT.inp","r",stdin);
    freopen("RESTRUCT.out","w",stdout);
    cin >> n >> q;
    for (long i=1; i<=n; i++)
    {
        a[i]=i;
        b[i]=i;
    }
    for (long i=1; i<=q; i++)
    {
        long tip,x,y;
        cin >> tip >> x >> y;
        if (tip==1) gop1(x,y);
        else if (tip==2) gop2(x,y);
        else
        {
            if (Get1(x)==Get1(y)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
