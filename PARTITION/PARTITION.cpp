#include <bits/stdc++.h>
#define nmax 300

using namespace std;

long n,k;
vector <long> a[nmax];
bool dd[nmax];

void dfs(long u)
{
    dd[u]=true;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i];
        if (!dd[v]) dfs(v);
    }
}

void dfs1(long u)
{
    k++;
    dd[u]=true;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i];
        if (!dd[v]) dfs1(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PARTITION.inp","r",stdin);
    freopen("PARTITION.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
       {
          long u; cin >> u;
          if (u==1) a[i].push_back(j);
       }
    long dem=0;
    memset(dd,false,sizeof(dd));
    for (long i=1; i<=n; i++)
      if (!dd[i]) {++dem; dfs(i);}
    if (dem>2) cout << "Impossible";
    else
    {
        if (dem==1)
        {
            if (n%2==0) cout << 0;
            else cout << 1;
        }
        else
        {
            memset(dd,false,sizeof(dd));
            k=0; dfs1(1);
            cout << max(k-(n-k),n-k-k);
        }
    }
}
