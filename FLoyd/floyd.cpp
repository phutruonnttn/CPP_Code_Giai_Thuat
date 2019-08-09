#include <bits/stdc++.h>
#define vc 1000000007

using namespace std;

long n,m,s,t,a[1007][1007],tr[1007][1007];

void floyd()
{
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        for  (long k=1; k<=n; k++)
          if (a[i][j]> a[i][k] + a[k][j])
             {
                a[i][j] = a[i][k] + a[k][j];
                tr[i][j]=k;
             }
}

void truyvet(long i, long j)
{
    if (tr[i][j]==0) cout << i << " ";
    else
    {
        truyvet(i,tr[i][j]);
        truyvet(tr[i][j],j);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("floyd.inp","r",stdin);
    freopen("floyd.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
      {
          long u,v,w;
          cin >> u >> v >> w;
          a[u][v]=w;
      }
    cin >> s >> t;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=n; j++)
         if (a[i][j]==0) a[i][j]=vc;
    floyd();
    if (a[s][t]!=vc)
    {
        cout << a[s][t] << endl;
        truyvet(s,t);
        cout << t;
    }
    else
        cout << "KHONG CO DUONG DI";
}
