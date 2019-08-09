#include <bits/stdc++.h>

using namespace std;

long long n,m,d,tr[200007];
bool dd[2000007];
vector <long long> adj[2000007];

void dfs(long u,long k)
{
    dd[u]=true; d++;
    for (long i=0;i<adj[u].size();i++)
    {
        long long v=adj[u][i];
        if (dd[v]==false && v!=k) dfs(v,k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GRAPH.inp","r",stdin);
    freopen("GRAPH.out","w",stdout);
    cin >> n >> m;

    for (long long i=1; i<=m; i++)
    {
        long long u,v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for (long long i=1; i<=n; i++)
    {
        long long ans=1; d=0;
        for (long j=1; j<=n; j++)
            dd[j]=false;

        if (i==n) dfs(1,i);
        else dfs(i+1,i);
        dd[i]=true; d++;

        long long dem=0;
        for (long j=1; j<=n; j++)
            if (dd[j]==false) {dem++;tr[dem]=j;};
        if (dem==0) cout << ans << endl;
        else
        {
        long long dt=1;

        while (d!=n)
        {
           if (dd[tr[dt]]==true) dt++;
           if (dt>dem) break;
           dfs(tr[dt],i); ans++;
           dt++;
           //if (dt>dem) break;
        }

        cout << ans << endl;
        }
    }
}
