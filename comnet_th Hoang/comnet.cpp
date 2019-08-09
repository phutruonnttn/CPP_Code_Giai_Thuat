#include <bits/stdc++.h>
#define nmax 5*100007

using namespace std;
typedef pair <int,int> ii;

vector <ii> a[nmax];
long long n,m,dd[nmax],ans=9999999999999999;

void dfs(long long u,long long cs)
{
    //dd[u]=1;
    if (u==n) ans=min(ans,cs);
    for (long i=0; i<a[u].size(); i++)
    {
        long long v=a[u][i].first;
        long long cs1=a[u][i].second;
        if (dd[v]==0)
        {
            dd[v]=1;
            dfs(v,max(cs,cs1));
            dd[v]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("comnet.inp","r",stdin);
    freopen("comnet.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        a[u].push_back(ii(v,i));
    }
    dd[1]=1;
    dfs(1,-1);
    cout << ans;
}
