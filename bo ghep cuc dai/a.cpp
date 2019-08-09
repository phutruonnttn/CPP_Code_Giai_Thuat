#include <bits/stdc++.h>
#define nmax 2007

using namespace std;

long c[nmax][nmax],a[nmax],b[nmax],tr[nmax],n,lj;
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
   for (long j=1; j<=n; j++)
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
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n;
    long i,j;
    while (cin >> i >> j) c[i][j]=1;
    for (long i=1; i<=n; i++)
       if (a[i]==0)
        {
           memset(tr,0,sizeof(tr));
           ok=false;
           dfs(i);
           if (ok) tang_canh(lj);
        }
    for (long i=1; i<=n; i++)
       if (a[i]>0) cout << i << " " << a[i] << '\n';
}

