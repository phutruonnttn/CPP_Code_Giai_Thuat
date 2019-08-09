#include <bits/stdc++.h>

using namespace std;

long n,bac[10007];
long long f[10007][3];
vector <long> adj[10007];


int main()
{
    freopen("CTREE.inp","r",stdin);
    freopen("CTREE.out","w",stdout);
    cin >> n;

    memset(bac,0,sizeof(bac));

    for (long i=1; i<=n-1; i++)
    {
        long u,v;
        cin >> u >> v;

        bac[v]++;
        bac[u]++;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (long i=1; i<=n; i++ )
        for (long j=1; j<=3; j++)
         {
            for (long k=1; k<=3;k++)
            {
                if (k!=j)
                {
                    for (long u=0; u<adj[i].size(); u++)
                    {
                        long v=adj[i][u];
                        if (bac[v]==1) f[v][k]=k;
                        else
                        {

                        }
                    }
                }
            }
         }


}
