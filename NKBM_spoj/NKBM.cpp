#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

long c[nmax][nmax],a[nmax],b[nmax],tr[nmax],lj,m,ans=0,x,y;
bool ok;

void tang_canh(long j)
{
  long i,p=0;
  while (j!=0)
    {
       i=tr[j]; p=a[i];
       a[i]=j; b[j]=i; j=p;
    }
}

void dfs(long i)
{
   for (long j=1; j<=y; j++)
     if (c[i][j]==1 && tr[j]==0)
        {
            tr[j]=i;
            if (b[j]==0)
             {
                ok=true; lj=j;
                return;
             }
             else dfs(b[j]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("NKBM.inp","r",stdin);
    //freopen("NKBM.out","w",stdout);
    cin >> x >> y >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        c[u][v]=1;
    }
    for (long i=1; i<=x; i++)
       if (a[i]==0)
        {
           memset(tr,0,sizeof(tr));
           ok=false;
           dfs(i);
           if (ok) tang_canh(lj);
        }
    for (long i=1; i<=x; i++)
       if (a[i]>0) ans++;
    cout << ans;
}
