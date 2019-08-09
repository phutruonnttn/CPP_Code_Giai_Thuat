#include <bits/stdc++.h>

using namespace std;
typedef pair <long, long> ii;

long long n,k,d[250][250],l=0,r=-1,ans,dd[250];
vector <ii> a[250];
vector <long> adv[250];

void dfs(long u)
{
    dd[u]=1;
    for (long i=0; i<adv[u].size(); i++)
       if (dd[adv[u][i]]!=1)
          dfs(adv[u][i]);
}

bool kt(long long h)
{
    for (long i=1; i<=n; i++) {adv[i].clear(); dd[i]=0;}
    for (long i=1; i<=n; i++)
       for (long j=0; j<a[i].size(); j++)
         if (a[i][j].second<h)
            {
                adv[a[i][j].first].push_back(i);
                adv[i].push_back(a[i][j].first);
            }

    long long dem=0;
    for (long i=1; i<=n; i++)
    {
        if (dd[i]==0) {dem++; dfs(i);}
    }
    if (dem>=k) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CLUSTER.inp","r",stdin);
    freopen("CLUSTER.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
       {cin >> d[i][j]; r=max(r,d[i][j]);}

    for (long i=1; i<=n-1; i++)
       for (long j=i+1; j<=n; j++)
         a[i].push_back(ii(j,d[i][j]));

    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans;
}
