#include <bits/stdc++.h>
#define nmax 10007
using namespace std;
int n,f[nmax][4],kq[nmax],res;
vector <int> adj[nmax];
vector <int> child[nmax];
bool dd[nmax];

void dfs(int u)
{
    dd[u]=true;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (!dd[v]) {child[u].push_back(v);dfs(v);}
    }

    if (child[u].size()==0) {f[u][1]=1;f[u][2]=2;f[u][3]=3;}
    else
    {
        for (int z=1;z<=3;z++) f[u][z]=z;
        for (int i=0;i<child[u].size();i++)
        {
            int v=child[u][i];
            f[u][1]+=min(f[v][2],f[v][3]);
            f[u][2]+=min(f[v][1],f[v][3]);
            f[u][3]+=min(f[v][2],f[v][1]);
        }
    }
}
void dfs2(int u,int mau)
{
    kq[u]=mau;
    dd[u]=true;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (!dd[v])
        {
            int minn=round(1e9),cs;
            for (int z=1;z<=3;z++)
            if ((z!=mau) && (f[v][z]<minn)) {minn=f[v][z];cs=z;}

            dfs2(v,cs);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ctree.inp","r",stdin);
    freopen("ctree.out","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i=1;i<=nmax;i++) dd[i]=false;
    dfs(1);

    res=min(f[1][1],min(f[1][2],f[1][3]));
    cout<<res<<endl;
    for (int i=1;i<=nmax;i++) dd[i]=false;
    if (f[1][1]==res) dfs2(1,1);
    else
        if (f[1][2]==res) dfs2(1,2); else dfs2(1,3);

    for (int i=1;i<=n;i++) cout<<kq[i]<<endl;
}
