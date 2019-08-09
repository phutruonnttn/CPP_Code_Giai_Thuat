#include <bits/stdc++.h>
#define nmax 500007

using namespace std;

long long n,m,cnt=0,num[nmax],low[nmax],kq[nmax],f[nmax],dk,dd[nmax],kk=0;
bool mark[nmax];
vector <long> adj[nmax];

void dfs(int u,int p)
{
    int dem=0;
    num[u]=low[u]=++cnt;
    //f[u]=1;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dem++;
            dfs(v,u);
            //f[u]+=f[v];
            if (low[v]>=num[u]) //mark[u]=true;
            {
                long dk=0;
                kk++;
                deem(u,v);
                kq[u]+=((f[u]-1)*(n-f[u])*2);
            }
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
    if ((p==0) && (dem<2)) //mark[u]=false;// neu u la goc cay dfs
        kq[u]=(n-1)*2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("blo.inp","r",stdin);
    freopen("blo.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(mark,false,sizeof(mark));
    memset(num,0,sizeof(num));
    for (long i=1; i<=n; i++) kq[i]=(n-1)*2;
    dfs(1,0);
    //for (long i=1; i<=n; i++) cout << kq[i] << '\n';
}
