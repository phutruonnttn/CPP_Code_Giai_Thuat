#include <bits/stdc++.h>
#define nmax 100007
#define F first
#define S second
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n,m,num[nmax],low[nmax],cnt=0,demtp=0;
vector <pii> vt;
vector <int> adj[nmax];

void dfs(int u)
{
    num[u]=low[u]=++cnt;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (num[v]==0)
        {
            vt.push_back(mp(u,v));
            dfs(v);
            if (low[v]>=num[u])
            {
                ++demtp;
                while (vt.size()>0)
                {
                    int p=vt.back().F;
                    int q=vt.back().S;
                    vt.pop_back();
                    cout<<q<<" ";
                    if ((p==u) && (q==v)) break;
                }
                cout<<u<<endl;
            }
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}
void xuli()
{
    for (int i=1;i<=n;i++)
        if (num[i]==0)
        {
            int tmp=cnt;
            dfs(i);
            if (cnt==tmp+1) {demtp++;cout<<i<<endl;}
        }

    //cout<<demtp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("songlt.inp","r",stdin);
    freopen("songlt.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    xuli();
}
