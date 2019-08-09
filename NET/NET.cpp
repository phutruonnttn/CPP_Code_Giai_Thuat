#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,m,k,l,cnt=0,num[nmax],low[nmax],dcau=0,dv[nmax],da[nmax],db[nmax];
vector <long> adj[nmax];

void dfs(int u,int p)
{
    int dem=0;
    num[u]=low[u]=++cnt;
    if (dv[u]==1) da[u]=1;
    if (dv[u]==2) db[u]=1;
    if (dv[u]==3) {da[u]=1;db[u]=1;}
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dem++;
            dfs(v,u);
            da[u]+=da[v];
            db[u]+=db[v];
            if (low[v]>num[u])
              if (da[v]==k || db[v]==l || da[v]==0 || db[v]==0) dcau++;

            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NET.inp","r",stdin);
    freopen("NET.out","w",stdout);
    cin>>n>>m>>k>>l;
    for (long i=1; i<=k; i++)
    {
        long x; cin>> x;
        dv[x]+=1;
    }
    for (long i=1; i<=l; i++)
    {
        long x; cin >> x;
        dv[x]+=2;
    }

    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    cout << dcau;
}
