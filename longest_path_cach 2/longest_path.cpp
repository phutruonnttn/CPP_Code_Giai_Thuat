#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

long n,d[1000007],vtmax;
bool dd[1000007];
vector <ii> a[1000007];

void dfs(long u)
{
    dd[u]=false;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i].first;
        if (dd[v])
         {
            d[v]=d[u]+a[u][i].second;
            dfs(v);
         }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("longest_path.inp","r",stdin);
    freopen("longest_path.out","w",stdout);
    cin >> n;
    for (long i=1; i<n; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    for (long i=1; i<=n; i++) dd[i]=true;

    dfs(1);
    for (long i=2; i<=n; i++)
      if (d[i]>d[1])
       {
          d[1]=d[i];
          vtmax=i;
       }

    for (long i=1; i<=n; i++) {d[i]=0; dd[i]=true;}
    dfs(vtmax);
    for (long i=1; i<=n; i++)
      if (d[i]>d[vtmax]) d[vtmax]=d[i];

    cout << d[vtmax];
}
