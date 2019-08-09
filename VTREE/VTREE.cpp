#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

long n,tr[100007],a[10007][10007];
vector <long> adj[100007];
vector <long> w[100007];

void bfs(long s)
{
   long q[100007],f=1,r=1,u,v;
   q[1]=s;
   memset(tr,0,sizeof(tr));
   tr[s]=-1;
   do
   {
       u=q[f++];
       for (long i=0; i<adj[u].size() ; i++)
       {
        long v=adj[u][i];
         if (tr[v]==0)
         {
             q[++r]=v;
             tr[v]=u;
         }
       }
   }
   while (f<=r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VTREE.inp","r",stdin);
    freopen("VTREE.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n-1; i++)
    {
        long u,v,ww;
        cin >> u >> v >> ww;
        a[u][v]=ww;
        a[v][u]=ww;
        adj[u].push_back(v);
        adj[v].push_back(u);
        w[u].push_back(ww);
        w[v].push_back(ww);
    };
    long long ans=0;
    for (long i=1; i<=n-1; i++)
    {
        bfs(i);
        for(long j=i+1; j<=n; j++)
        {
            long long jj=j,kq=1;
            while (jj!=i)
            {
               kq=(kq*a[jj][tr[jj]]) % nmod;
               jj=tr[jj];
            }
            ans=(ans+kq) % nmod;
        }
    }
    cout << ans;
}
