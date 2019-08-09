#include <bits/stdc++.h>
#define nmax 200007
using namespace std;
int n,m,cnt=0,num[nmax],low[nmax],dkhop=0,dcau=0;
bool mark[nmax];
vector <int> adj[nmax];

void dfs(int u,int p)
{
    int dem=0;
    num[u]=low[u]=++cnt;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dem++;
            dfs(v,u);
            if (low[v]>num[u]) /*cout<<u<<" "<<v<<endl;*/ dcau++;
            if (low[v]>=num[u]) mark[u]=true;
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
    if ((p==0) && (dem<2)) mark[u]=false;// neu u la goc cay dfs
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("khopcau.inp","r",stdin);
    freopen("khopcau.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(mark,false,sizeof(mark));
    memset(num,0,sizeof(num));

    for (int i=1;i<=n;i++)
    if (num[i]==0) dfs(i,0);

    for (int i=1;i<=n;i++)
        if (mark[i]) {dkhop++;/*cout<<i<<endl;*/}

    cout<<dkhop<<" "<<dcau;
}
