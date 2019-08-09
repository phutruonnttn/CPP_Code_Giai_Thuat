#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long,long> ii;

long n,m,ans=-1;
vector <ii> a[nmax];
bool dd[nmax];

void dfs(long u,long dich,long minn, long maxx)
{
    dd[u]=false;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i].first;
        if (v==dich)
            ans=max(ans,minn+maxx);
        if (dd[v])
        {
            dfs(v,dich,min(minn,a[u][i].second),max(maxx,a[u][i].second));
        }
    }
    dd[u]=true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bgame.inp","r",stdin);
    freopen("bgame.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    for (long i=1; i<=n; i++)
    {
       memset(dd,true,sizeof(dd));
       dfs(i,i,1e9,-1);
    }
    cout << ans;
}
