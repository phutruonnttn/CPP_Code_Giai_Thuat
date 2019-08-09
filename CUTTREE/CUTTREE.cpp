#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

long n,k;
bool a[107][107],dd[107];
vector <long> adj[107];

/*void bfs()
{
   long q[100007],f=1,r=1,u,v;
   q[1]=1;
   //memset(tr,0,sizeof(tr));
   //tr[1]=-1;
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
}*/

int main()
{
    freopen("CUTTREE.inp","r",stdin);
    freopen("CUTTREE.out","w",stdout);
    cin >>n >> k;
    memset(a,false,sizeof(a));
    for (long i=1; i<=n-1;i++)
    {
        long u,v;
        cin >> u >> v;
        a[u][v]=true;
        a[v][u]=true;
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    cout << 0;

}
