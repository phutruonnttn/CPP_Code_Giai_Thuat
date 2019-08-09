#include <bits/stdc++.h>
#define nmax 10000

using namespace std;

long p,x,y,z,root[nmax+7];

int Get_root(int u)
{
    if (root[u]==0 ) return u; // neu i la goc
    root[u]=Get_root(root[u]);
    return root[u];
}

void gop(long x, long y)
{
    long u=Get_root(x);// tim goc x
    long v=Get_root(y);// tim goc y
    if (u==v) return; // cung goc
    if (root[u] < root[v])
    { // u nhieu con hon v
        root[u]+=root[v];
        root[v] = u; // noi nhanh v vao u
    }
    else
    {
        root[v]+=root[u];
        root[u]=v;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DS2509.inp","r",stdin);
    freopen("DS2509.out","w",stdout);
    cin >> p;
    while (p--)
    {
        cin >> x >> y >> z;
        if (z==1) gop(x,y);
        else
        {
            if (Get_root(x)==Get_root(y)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        //for (long i=1; i<=7; i++) cout << root[i] << " ";cout << endl;
    }
}
