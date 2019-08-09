#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long n,m;
vector <long> a[nmax];
bool dd[nmax];

void dfs(long u)
{
    dd[u]=false;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i];
        if (dd[v])
        {
            //dd[v]=false;
            dfs(v);
        }
    }
    dd[u]=true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("t2.inp","r",stdin);
    freopen("t2.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(dd,true,sizeof(dd));
    dfs(1);
    if (!dd[n]) cout << "co";
    else cout << "Khong";
}
