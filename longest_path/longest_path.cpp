#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

long n,d1[1000007],d2[1000007];
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
           dfs(v);
           if (d1[u]<d1[v]+a[u][i].second)
           {
             d2[u]=d1[u];
             d1[u]=d1[v]+a[u][i].second;
           }
           else
           if (d2[u]<d1[v]+a[u][i].second) d2[u]=d1[v]+a[u][i].second;
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
    memset(dd,true,sizeof(dd));
    dfs(1);
    long ans=-1;
    for (long i=1; i<=n; i++)
       ans=max(ans,d1[i]+d2[i]);
       //cout << i << " "<< d1[i] << " " << d2[i] << endl;
    cout << ans;
}
