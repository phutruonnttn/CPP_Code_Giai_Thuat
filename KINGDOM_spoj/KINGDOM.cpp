#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long long n,m,v[nmax],c[nmax];
vector <long> a[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("KINGDOM.inp","r",stdin);
    freopen("KINGDOM.out","w",stdout);
    cin >> n >> m;
    for (long i=2; i<=n; i++) cin >> v[i];
    for (long i=2; i<=n; i++) cin >> c[i];
    for (long i=1; i<n; i++)
    {
        long u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);

}
