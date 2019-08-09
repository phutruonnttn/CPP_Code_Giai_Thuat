#include <bits/stdc++.h>

using namespace std;

long n,m,num[107],child[107],cnt=0,low[107],dcau=0;
long long ans=0;
vector <long> adj[107];

void dfs(int u,int p)
{
    num[u]=low[u]=++cnt; child[u]=1;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dfs(v,u);
            child[u]+=child[v];
            if (low[v]>num[u]) {dcau++; ans+=(n-child[v])*child[v];}
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("WEATHER.inp","r",stdin);
    //freopen("WEATHER.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (long i=1; i<=n; i++) num[i]=0;
    dfs(1,0);
    cout << ans;
}
