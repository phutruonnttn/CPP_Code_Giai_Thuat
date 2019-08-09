#include <bits/stdc++.h>
#define nmax 1007

using namespace std;
typedef pair <long long, long long> ii;

long long n,m,t,ans;
vector <ii> a[nmax];
bool dd2[nmax][nmax];

void dfs(long long u,long long sum,long long rb)
{
    if (u==rb && sum!=0 && sum<ans) ans=sum;
    for (long i=0; i<a[u].size(); i++)
    {
        long long v=a[u][i].first;
        if (dd2[u][v])
        {
           dd2[u][v]=false;
           dfs(v,sum+a[u][i].second,rb);
           dd2[u][v]=true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TOURS13.inp","r",stdin);
    freopen("TOURS13.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n >> m;
        for (long i=1; i<=n; i++)
           for (long j=1; j<=n; j++)
              dd2[i][j]=false;
        for (long i=1; i<=m; i++)
        {
            long long u,v,w;
            cin >> u >> v >> w;
            a[u].push_back(ii(v,w));
            dd2[u][v]=true;
        }
        for (long i=1; i<=n; i++)
        {
            ans=1e10;
            dfs(i,0,i);
            if (ans==1e10) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
}
