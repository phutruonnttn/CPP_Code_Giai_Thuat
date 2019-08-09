#include <bits/stdc++.h>
#define nmax 300007
#define F first
#define S second
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int n,m,num[nmax],low[nmax],cnt=0,demtp=0; long ans=-1;
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
                ++demtp; long dem=0;
                while (vt.size()>0)
                {
                    int p=vt.back().F;
                    int q=vt.back().S;
                    vt.pop_back();
                    dem++;
                    if ((p==u) && (q==v)) break;
                }
                dem++; ans=max(ans,dem);
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
            if (cnt==tmp+1) {demtp++;ans=max(ans,(long)1);}
        }

    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SAFENET2.inp","r",stdin);
    freopen("SAFENET2.out","w",stdout);
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
