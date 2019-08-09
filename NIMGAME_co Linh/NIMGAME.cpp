#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long n,m,a[nmax][nmax],b[nmax];

long f(long k, long u, long v)
{
    if (a[u][v]!=-1) return a[u][v];
    if (k==0)
    {
        b[u]=a[u][v];//******
        return a[u][v];
    }
    a[u][v]=0;
    for (long i=1; i<=m; ++i)
    {
        if (i>k) break;
        a[u][v]=max(a[u][v],k+u+v-f(k-i,v,u+i));
    }
    return a[u][v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NIMGAME.inp","r",stdin);
    freopen("NIMGAME.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
    {
        for (long u=0; u<=n; u++)
          for (long v=0; v<=n; v++)
           a[u][v]=-1;
        b[i]=f(i,0,0);
    }
    cout << b[n];
}
