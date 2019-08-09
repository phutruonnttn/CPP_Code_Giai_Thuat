#include <bits/stdc++.h>

using namespace std;

long n,k,res,t[100007];
vector <long> adj[100007];
bool dd[100007];

long long get(long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&-x);
    }
    return res;
}

void update(long x, long d)
{
    while (x<=100007)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}

void dfs(long u)
{
  update(u,1);
  dd[u]=true;
  res+=get(u-1);
  for (long i = 0; i < adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (!dd[v])
          dfs(v);
    }
  update(u,-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RELATION.inp","r",stdin);
    freopen("RELATION.out","w",stdout);
    cin >> n;
    cin >> k;
    for (long i=1; i<=n-1; i++)
    {
        long u,v;
        cin >> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(t,0,sizeof(t));
    memset(dd,false,sizeof(dd));
    res=0;
    dfs(k);
    cout << res;
}
