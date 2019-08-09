#include <bits/stdc++.h>

using namespace std;

long n,k,gt[107],d[107];
vector <long> a[107];
long long ans=-1;
bool dd[107];

void dfs(long u, long long sum, long ii)
{
   ans=max(ans,sum);
   dd[u]=false;
   if (ii<k)
    for (long i=0; i<a[u].size(); i++)
     {
       long v=a[u][i];
       if (dd[v])
       {
           dfs(v,sum+gt[v],ii+1);
       }
     }
     dd[u]=true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("OPTION.inp","r",stdin);
    freopen("OPTION.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
    {
        cin >> gt[i];
        long m; cin >> m;
        for (long j=1; j<=m; j++)
        {
           long v; cin >> v;
           a[i].push_back(v);
        }
    }

    for (long i=1; i<=n; i++)
    {
        memset(dd,true,sizeof(dd));
        dfs(i,gt[i],1);
    }
    cout << ans;
}
