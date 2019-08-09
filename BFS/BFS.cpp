#include <bits/stdc++.h>

using namespace std;

long n,m,tr[100007];
vector <long> adj[100007];

void bfs()
{
   long q[100007],f=1,r=1,u,v;
   q[1]=1;
   memset(tr,0,sizeof(tr));
   tr[1]=-1;
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
    freopen("BFS.inp","r",stdin);
    freopen("BFS.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m ; i++)
    {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs();
    long f=n;
    while (f!=1)
    {
        cout << f << "<-";
        f=tr[f];
    }
    cout << 1;
}
