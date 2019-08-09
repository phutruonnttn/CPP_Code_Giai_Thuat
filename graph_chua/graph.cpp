#include <bits/stdc++.h>
#define vc 10000000000

using namespace std;

long number[20007],countt[20007],low[20007],k,parren[20007];
bool dd[20007];
long n,m;
vector <long> adj[20007];

void dfs(long u)
{
    dd[u]=true;
    number[u]=++k;
    for (long i=0; i< adj[u].size();i++)
    {
        long v=adj[u][i];
        if (dd[v]==false)
        {
            parren[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if (low[v]>=number[u]) countt[u]++;
        }
        else low[u]=min(low[u],number[v]);
    }
}

void dfs1(long u)
{
    dd[u]=true;
    for (long i=0;i<adj[u].size();i++)
    {
        long v=adj[u][i];
        if (dd[v]==false) dfs1(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GRAPH.inp","r",stdin);
    freopen("GRAPH.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long dem=0;


    k=0;
    for (long i=1; i<=n; i++)
        {low[i]=vc; countt[i]=0; parren[i]=-1;number[i]=0;}

        for (long i=1; i<=n;i++)
          if (dd[i]==false) {dfs(i); dem++;}

    /*for (long i=1; i<=n;i++)
        if (dd[i]==false)
    dfs(i);*/
    for (long i=1; i<=n; i++)
     if (parren[i]==-1) cout << countt[i]+dem-1 << endl;
     else cout << countt[i]+dem << endl;
}
