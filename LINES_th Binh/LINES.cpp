#include <bits/stdc++.h>
#define nmax 300

using namespace std;

struct point
{
    long long x,y;
};

long long c[nmax][nmax],a[nmax],b[nmax],tr[nmax],n,lj,aa,bb,cc;
point l[nmax],r[nmax],ngang1[nmax],doc1[nmax],ngang2[nmax],doc2[nmax];
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
    freopen("LINES.inp","r",stdin);
    freopen("LINES.out","w",stdout);
    cin >> n;
    long long dn=0,dd=0;
    for (long i=1; i<=n; i++)
       {
           cin >> l[i].x >> l[i].y >> r[i].x >> r[i].y;
           if (l[i].x==r[i].x)
           {
               dd++;
               doc1[dd].x=l[i].x;
               doc1[dd].y=l[i].y;
               doc2[dd].x=r[i].x;
               doc2[dd].y=r[i].y;
           }
           if (l[i].y==r[i].y)
           {
               dn++;
               ngang1[dn].x=l[i].x;
               ngang1[dn].y=l[i].y;
               ngang2[dn].x=r[i].x;
               ngang2[dn].y=r[i].y;
           }
       }
    for (long i=1; i<=dd; i++)
       for (long j=1; j<=dn; j++)
         {
             if (min(doc1[i].y,doc2[i].y)<=ngang1[j].y && ngang1[j].y<=max(doc1[i].y,doc2[i].y) && min(ngang1[j].x,ngang2[j].x)<=doc1[i].x && doc1[i].x<=max(ngang1[j].x,ngang2[j].x))
                 c[i][j]=1;
         }
    long long mm=n;
    n=max(dd,dn);
    for (long i=1; i<=n; i++)
       if (a[i]==0)
        {
           memset(tr,0,sizeof(tr));
           ok=false;
           dfs(i);
           if (ok) tang_canh(lj);
        }
    long long dem=0;
    for (long i=1; i<=n; i++)
       if (a[i]>0) dem++;
    cout << mm-dem;
}

