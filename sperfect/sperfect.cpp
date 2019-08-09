#include <bits/stdc++.h>

using namespace std;
long n,m,q,a[100007],b[100007],cnt,r,stp,s[100007],tp[100007],num[100007],low[100007],bac[100007],bacra[100007],bacvao[100007];
bool fr[100007],dd[100007],aa[10007][10007];
vector <long> adj[100007];

void dfs(long u)
{
 low[u] = 10000000;
  num[u] = ++cnt;
 s[++r]=u;
 fr[u]=false;
 for (long i = 0; i < adj[u].size(); i++)
    {
        long v=adj[u][i];
        if ((fr[v]==true) && (dd[v]==true))
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
    freopen("sperfect.inp","r",stdin);
    freopen("sperfect.out","w",stdout);
    cin >> q;
    for (long i=1; i<=q; i++)
    {
      for (long j=1; j<=n; j++) adj[i].clear();
      memset(dd,false,sizeof(dd));
      memset(aa,false,sizeof(aa));
      memset(bacra,0,sizeof(bacra));
      memset(bacvao,0,sizeof(bacvao));
      cin >> n >> m;
      for (long j=1; j<=m; j++)
      {
         cin >> a[j] >> b[j];
         if (a[j]!=b[j])
         {
         aa[a[j]][b[j]]=true;
         dd[a[j]]=true;
         dd[b[j]]=true;
         adj[a[j]].push_back(b[j]);
         }
      }
    cnt=0; r=0; stp=0;
    for (long j=1; j<=n ;j++) low[j]=1000000;
    memset(fr,true,sizeof(fr));
    for (long j=1; j<=n ;j++)
       if (( fr[j]==true) && (dd[j]==true)) dfs(j);


    for (long j=0; j<=n ;j++)
        if (dd[j]==true) cout << tp[j] << " ";
     cout << endl;

     for (long l=0; l<=n-1 ; l++)
      for(long j=l+1; j<=n; j++)
       if ((dd[l]==true) && (dd[j]==true))
        if ((tp[l]!=tp[j]) && (aa[l][j]==true))
        {
            bacra[l]++;
            bacvao[j]++;
        }

     for (long j=0; j<=n ;j++)
        if (dd[j]==true) cout << bacvao[j] << " ";
     cout << endl;

    }
}
