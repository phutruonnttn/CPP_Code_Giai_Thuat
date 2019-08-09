#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

long f,n,m,k,d[507],u1[50007],v1[50007],w1[50007],demm;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("wormhole.inp","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin >> f;
    for (long i1=1; i1<=f; i1++)
    {
        cin >> n >> m >> k;
        demm=0;
        for (long i=1; i<=m; i++)
        {
            long u,v,w;
            cin >> u >> v >> w;
            ++demm; u1[demm]=u; v1[demm]=v; w1[demm]=w;
            ++demm; u1[demm]=v; v1[demm]=u; w1[demm]=w;
        }
        for (long i=1; i<=k; i++)
        {
            long u,v,w;
            cin >> u >> v >> w;
            ++demm; u1[demm]=u; v1[demm]=v; w1[demm]=-w;
        }

        fill(d,d+n+1,1e9);
        d[1]=0;
        long change=1;
        for (long i=1; i<=n; i++)           //Thuat toan Forbell Man
        {
          change=0;
          for (long j=1; j<=demm; j++)
           if (d[u1[j]]+w1[j]<d[v1[j]])
           {
               d[v1[j]]=d[u1[j]]+w1[j];
               change=1;
           }
        }
        if (change==1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
