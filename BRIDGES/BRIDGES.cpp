#include <bits/stdc++.h>

using namespace std;

long n,m,d;
bool dd[10000000];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRIDGES.inp","r",stdin);
    freopen("BRIDGES.out","w",stdout);
    cin >> n >> m;
    memset(dd,false,sizeof(dd));
    d=0;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        if (u!=v)
        {
        if (dd[u]==false)
        {
            d++;
            dd[u]=true;
        };
        if (dd[v]==false)
        {
            d++;
            dd[v]=true;
        }
        if (d==n)
        {
            d=i;
            break;
        }
        }
    }
    cout << d;
}
