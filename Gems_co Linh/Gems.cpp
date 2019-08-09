#include <bits/stdc++.h>
#define nmax 10007
#define vc 999999999

using namespace std;

long long n,den[nmax],f[nmax][5],dd[nmax];
vector <long> a[nmax];

long long dfs(long u, long j)
{
    if (u!=1 && den[u]==1)
    {
        f[u][j]=j;
        return f[u][j];
    }
    dd[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i];
        if (dd[v]==0)
        {
            long long res=vc;
            for (long k=1; k<=3; k++)
               if (k!=j) res=min(res,dfs(v,k));
            f[u][j]+=res;
        }
    }
    f[u][j]+=j;
    return f[u][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Gems.inp","r",stdin);
    freopen("Gems.out","w",stdout);
    cin >> n;
    for (long i=1; i<n; i++)
    {
        long long u,v;
        cin >> u >> v;
        den[v]++; den[u]++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    long long ans=vc;
    for (long i=1; i<=3; i++)
    {
        memset(f,0,sizeof(f));
        memset(dd,0,sizeof(dd));
        ans=min(ans,dfs(1,i));
    }
    cout << ans;
}
