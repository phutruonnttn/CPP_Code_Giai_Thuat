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
       for (long i=0; i<=3; i++)
        {
           int ii=u+c1[i], jj=v+c2[i];
           if (ii<=m && ii>=1 && jj>=1 && jj<=n)
             if (dd[ii][jj]==0)
              {
                dd[ii][jj]=1;
                d[ii][jj]=d[u][v]+1;
                pq.push(make_pair(ii,jj));
              }
         }
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("pageant.inp","r",stdin);
    freopen("pageant.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
      {
         char ch;
         cin >> ch;
         if (ch=='X') a[i][j]=1;
      }

    danhdau(2); danhdau(3); danhdau(4);

    /*for (long i=1; i<=m; i++)
    {
        for (long j=1; j<=n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }*/

    for (long i=1; i<=sl[2]; i++)
    {
        long u=dinh[2][i].first, v=dinh[2][i].second;
        if (a[u+1][v]!=0 && a[u][v+1]!=0 && a[u-1][v]!=0 && a[u][v-1]!=0) continue;
        bfs(u,v);
        for (long j=1; j<=sl[3]; j++)
        {
            long u1=dinh[3][j].first,v1=dinh[3][j].second;
            d23=min(d23,d[u1][v1]-1);
        }
        for (long j=1; j<=sl[4]; j++)
        {
            long u1=dinh[4][j].first,v1=dinh[4][j].second;
            d24=min(d24,d[u1][v1]-1);
        }
    }

    for (long i=1; i<=sl[3]; i++)
    {
        long u=dinh[3][i].first, v=dinh[3][i].second;
        if (a[u+1][v]!=0 && a[u][v+1]!=0 && a[u-1][v]!=0 && a[u][v-1]!=0) continue;
        bfs(u,v);
        for (long j=1; j<=sl[4]; j++)
        {
            long u1=dinh[4][j].first,v1=dinh[4][j].second;
            d34=min(d34,d[u1][v1]-1);
        }
    }
    long long ans=min(d23+d34,min(d23+d24,d34+d24));


    for (long u=1; u<=m; u++)
      for (long v=1; v<=n; v++)
      {
            if (a[u+1][v]!=0 && a[u][v+1]!=0 && a[u-1][v]!=0 && a[u][v-1]!=0) continue;
            long long den2=vc,den3=vc,den4=vc;
            bfs(u,v);
            for (long j=1; j<=sl[2]; j++)
            {
               long u1=dinh[2][j].first,v1=dinh[2][j].second;
               den2=min(den2,d[u1][v1]-1);
            }
            for (long j=1; j<=sl[3]; j++)
            {
               long u1=dinh[3][j].first,v1=dinh[3][j].second;
               den3=min(den3,d[u1][v1]-1);
            }
            for (long j=1; j<=sl[4]; j++)
            {
               long u1=dinh[4][j].first,v1=dinh[4][j].second;
               den4=min(den4,d[u1][v1]-1);
            }
            ans=min(ans,den4+den2+den3+1);
      }
    cout << ans;
}
