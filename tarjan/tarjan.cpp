#include <bits/stdc++.h>
#define nmax 100007
#define pb push_back
using namespace std;
int n,m,cnt,num[nmax],low[nmax],demtp=0,tp[nmax]={0};
vector <int> adj[nmax],vt;
bool dd[nmax];

void dfs(int u)
{
    dd[u]=true;
    num[u]=low[u]=++cnt;
    vt.pb(u);
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (dd[v]) {if (tp[v]==0) low[u]=min(low[u],num[v]);} // khong xet cung cheo
        else
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
    }
    if (low[u]==num[u])
    {
        ++demtp;
        while (vt.size()>0)
        {
            int v=vt.back();
            cout<<v<<" ";
            tp[v]=demtp;
            vt.pop_back();
            if (v==u) break;
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("tarjan.inp","r",stdin);
    freopen("tarjan.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for (int i=1;i<=n;i++) dd[i]=false;

    cnt=0;
    for (int i=1;i<=n;i++)
        if (!dd[i]) dfs(i);
}
