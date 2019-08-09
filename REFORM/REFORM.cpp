#include <bits/stdc++.h>
#define nmax 2000007

using namespace std;

long long n,m,res=0,cnt=0,num[nmax],low[nmax],dcau,ccn=0,ccn1[nmax],ccn2[nmax],tplt=0,rb1,rb2,d0,child[nmax];
vector <long long> adj[nmax];
bool dd[nmax];

void dfs(long long u, long long p)
{
    num[u]=low[u]=++cnt;
    for (long i=0;i<adj[u].size() ;i++)
    {
        long long v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dfs(v,u);
            if (low[v]>num[u]) dcau++;
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}

void dfs2(long long u, long long p)
{
    num[u]=low[u]=++cnt;child[u]=1;
    for (long i=0;i<adj[u].size() ;i++)
    {
        long long v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dfs2(v,u);
            child[u]+=child[v];
            if (low[v]>num[u])
            {
                dcau++;
                res+=(n-child[v])*child[v]-1;
            }
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}

void dfstt(long long u)
{
    dd[u]=true;
    for (long i=0;i<adj[u].size();i++)
    {
        long long v=adj[u][i];
        if (dd[v]==false) dfstt(v);
    }
}

void dfs1(long long u)
{
    dd[u]=true; d0++;
    for (long i=0;i<adj[u].size();i++)
    {
        long long v=adj[u][i];
        if (dd[v]==false) dfs1(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("REFORM.inp","r",stdin);
    freopen("REFORM.out","w",stdout);
    cin >> n >> m;

    for (long i=1; i<=m; i++)
    {
        long long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ccn=n*(n-1)/2-m;

    for (long i=1; i<=n; i++) dd[i]=false;
    for (long i=1; i<=n; i++)
    if (dd[i]==false) {dfstt(i); tplt++;}
    if (tplt>=3) cout << 0;
    else
    if (tplt==2)
    {
        long long demd[10],k=0;
        for (long i=1; i<=n; i++) dd[i]=false;
        for (long i=1; i<=n; i++)
        {
            if (dd[i]==false) {d0=0; dfs1(i); demd[++k]=d0;}
        }
        for (long i=1; i<=n; i++) num[i]=0;
        dcau=0;
        for (int i=1;i<=n;i++)
          if (num[i]==0) dfs(i,0);
        cout << demd[1]*demd[2]*(m-dcau);
    }
    else
    {
        for (long i=1; i<=n; i++) num[i]=0;
        dcau=0; res=0;
        for (int i=1;i<=n;i++)
          if (num[i]==0) dfs2(i,0);
        res+=(m-dcau)*ccn;
        cout << res;
    }
}
