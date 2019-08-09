#include <bits/stdc++.h>

using namespace std;

long n,h[10007],bac,bacmax;
vector <long> adj[10007];
bool dd[10007];

void dfs(long u)
{
    dd[u]=true;
    for (long i=0;i<adj[u].size();i++)
    {
        long v=adj[u][i];
        if (dd[v]==false) {bac++;dfs(v);}
    }
    if (bac>bacmax)
    {
        bacmax=bac;
    }
    bac--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n-1; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(h,0,sizeof(h));
    for (long i=1; i<=n; i++)
    {
       memset(dd,false,sizeof(dd));
       bac=0; bacmax=-1;
       dfs(i);
       h[i]=bacmax;
    }
    long ans=h[1], ans1=1;
    for (long i=2; i<=n; i++)
       if (ans>=h[i])
       {
           ans=h[i];
           ans1=i;
       }

    cout << ans1 << " " << ans;

}
