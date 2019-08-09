#include <bits/stdc++.h>

using namespace std;
long q,n,m,a[100007],b[100007],bac[100007];
bool fr[100007],aa[10000][10000],fr1[100007];
vector<long> adj[100007];

void dfs(long u)
{
 /*fr[u]=false;
 for (long i = 0; i < adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (fr[v]==true)
        {
            dfs(v);
        }
    }   */

  fr[u]=false;
  for (long v=1; v<=n; v++)
        if ((aa[u][v]==true) && (fr[v]==true)) dfs(v);

}

int main()
{
    freopen("sperfect.inp","r",stdin);
    freopen("sperfect.out","w",stdout);
    /*memset(bac,0,sizeof(bac));
    memset(aa,false,sizeof(aa));
    memset(fr,false,sizeof(fr));*/
    cin >> q;
    for (long i=1; i<=q; i++)
    {
      memset(bac,0,sizeof(bac));
      memset(aa,false,sizeof(aa));
      memset(fr,false,sizeof(fr));
      cin >> n >> m;
      for (long j=1; j<=m; j++)
      {
         cin >> a[j] >> b[j];
         bac[b[j]]++;
         adj[a[j]].push_back(b[j]);
         adj[b[j]].push_back(a[j]);

         aa[a[j]][b[j]]=true;
         aa[b[j]][a[j]]=true;
         fr[a[j]]=true;
         fr[b[j]]=true;
      }
     long d=0;
     for (long j=1;j<=n;j++)
        fr1[j]=fr[j];
     //memset(fr,true,sizeof(fr));
     for (long j=1; j<=n ; j++)
     {
        if (fr[j]==true)
        {
            ++d;
            dfs(j);
        }
     }
     if (d!=1) cout << "NO" << endl;
     else
     {
         long d=0;
         for (long j=1 ; j<=n; j++)
            if ((bac[j]==0) && (fr1[j]==true)) ++d;

         if (d==1) cout << "YES" << endl;
         else cout << "NO" << endl;
     }
    }
}
