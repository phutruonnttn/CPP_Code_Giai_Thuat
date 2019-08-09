#include <bits/stdc++.h>

using namespace std;

long long n,m,k;
int a[10007][10007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("QUERY.inp","r",stdin);
    freopen("QUERY.out","w",stdout);
    cin >> m >> n >> k;
    //memset(a,0,sizeof(a));
    for (long i=1; i<=k; i++)
    {
        string s; cin >> s;
        if (s=="S")
        {
            //cout << 1;
            long u,v,w;
            cin >> u >> v >> w;
            a[u][v]=w;
        };
        if (s=="Q")
        {
            //cout << 2;
            long x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long long sum=0;
            for (long u=x1; u<=x2; u++)
                for (long v=y1; v<=y2; v++)
                 sum+=a[u][v];
            cout<< sum << endl;
        };
    }
}
