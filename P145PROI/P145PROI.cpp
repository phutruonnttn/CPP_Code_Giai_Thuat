#include <bits/stdc++.h>
#define nmax 1007
#define vc 99999999

using namespace std;
typedef pair <int,int> ii;

long long n,m,a[nmax][nmax],d23=vc,d24=vc,d34=vc,d[nmax][nmax],dd[nmax][nmax],sl[5];
long c1[7]={0,0,1,-1},c2[7]={1,-1,0,0};
ii dinh[5][nmax];

void loang1(long i, long j, long k)
{
    ++sl[k];
    dinh[k][sl[k]].first=i;
    dinh[k][sl[k]].second=j;
    a[i][j]=k;
    for (long l=0; l<4; l++)
      if (a[i+c1[l]][j+c2[l]]==1) loang1(i+c1[l],j+c2[l],k);
}

void danhdau(long h)
{
    bool ok=true;
    for (long i=1; i<=m; i++)
    {
      for (long j=1; j<=n; j++)
        if (a[i][j]==1) {ok=false; loang1(i,j,h); break;}
      if (!ok) break;
    }
}

void bfs(long u, long v)
{
   queue <ii> pq;
   for (long i=0; i<=m+1; i++)
     for (long j=0; j<=n+1; j++)
       {
           d[i][j]=vc;
           dd[i][j]=0;
       }
   pq.push(make_pair(u,v));
   d[u][v]=0;
   dd[u][v]=1;
   while (!pq.empty())
     {
       int u=pq.front().first;
       int v=pq.front().second;
       pq.pop();
       for