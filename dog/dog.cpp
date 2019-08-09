#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long, long> ii;

long n,d[nmax],dd[nmax],d1,d2,da[nmax],db[nmax];
vector <ii> a[nmax];

void dfs(long u)
{
    d[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
      long v=a[u][i].first;
      if (d[v]==0)
      {
         dd[v]=dd[u]+a[u][i].second;
         dfs(v);
      }
    }
}

void dfs1(long u)
{
    d[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
      long v=a[u][i].first;
      if (d[v]==0)
      {
         da[v]=da[u]+a[u][i].second;
         dfs1(v);
      }
    }
}

void dfs2(long u)
{
    d[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
      long v=a[u][i].first;
      if (d[v]==0)
      {
         db[v]=db[u]+a[u][i].second;
         dfs2(v);
      }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dog.inp","r",stdin);
    freopen("dog.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    memset(dd,0,sizeof(dd));
    memset(da,0,sizeof(da));
    memset(db,0,sizeof(db));
    memset(d,0,sizeof(d));
    dfs(1);
    long long maxx=-1;
    for (long i=1; i<=n; i++)
       if (dd[i]>maxx)
       {
           maxx=dd[i];
           d1=i;
       }
    memset(d,0,sizeof(d));
    dfs1(d1);

    maxx=-1;
    for (long i=1; i<=n; i++)
       if (da[i]>maxx)
       {
           maxx=da[i];
           d2=i;
       }
    memset(d,0,sizeof(d));
    dfs2(d2);

    for (long i=1; i<=n; i++)
      cout << max(da[i],db[i]) << " ";
}
