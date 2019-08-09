#include <bits/stdc++.h>

using namespace std;
long long cnt,r,stp,s[100007],tp[100007],num[100007],low[100007],n,m;
bool fr[100007];
bool a[10000][10000];
vector <long long> ke[100007];

void dfs(long u)
{
 low[u] = 10000000;
  num[u] = ++cnt;
 s[++r]=u;
 fr[u]=false;
 for (long i = 0; i < ke[u].size(); i++)
    {
        long v=ke[u][i];
        if (fr[v]==true)
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if (tp[v]==0) low[u]=min(low[u],num[v]);

    }
    if (low[u]==num[u])
        {
            tp[u]=++stp;
            while (s[r]!=u)
            {
                tp[s[r]]=stp;
                r--;
            }
            r--;
        }
}

int main()
{
  freopen("newroads.inp","r",stdin);
  freopen("newroads.out","w",stdout);
  memset(a,false,sizeof(a));
  cin >> n >> m;
  for (long i=1; i<=m ;i++)
  {
      long u,v;
      cin >> u >> v;
      a[u][v]=true;
      ke[u].push_back(v);
  }
  cnt=0; r=0; stp=0;
  for (long i=1; i<=n ;i++) low[i]=1000000;
  memset(fr,true,sizeof(fr));
  for (long i=1; i<=n ;i++)
     if ( fr[i]==true) dfs(i);
  long long res=0;
  for (long i=1; i<=n-1 ;i++)
     for (long j=i+1; j<=n; j++)
        if (tp[i]==tp[j])
     {
         if (a[i][j]==false) res++;
         if (a[j][i]==false) res++;
     }
 cout << res;

}
