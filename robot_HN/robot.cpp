#include <bits/stdc++.h>
#define nmax 1007
#define vc 9999999999

using namespace std;
typedef pair <int,int> ii;

long long dem=1,n,a[nmax][nmax],a1[nmax][nmax],dd[nmax][nmax],l1,c1,l2,c2,d1[5]={1,-1,0,0},d2[5]={0,0,1,-1},d[nmax][nmax],tr[nmax][nmax],nho1[nmax*nmax],nho2[nmax*nmax];

void bfs()
{
   queue <ii> pq;
   pq.push(make_pair(l1,c1));
   d[l1][c1]=0;
   long long dem=1;
   nho1[1]=l1;
   nho2[1]=c1;
   tr[l1][c1]=1;
   a1[l1][c1]=1;
   while (!pq.empty())
     {
       int u=pq.front().first;
       int v=pq.front().second;
       pq.pop();
       for (long i=0; i<=3; i++)
        {
           int ii=u+d1[i], jj=v+d2[i];
           if (ii<=n && ii>=1 && jj>=1 && jj<=n)
             if (a1[ii][jj]==0)
              {
                long truoc1=nho1[tr[u][v]],truoc2=nho2[tr[u][v]];
                a1[ii][jj]=1;
                if ((truoc1==u && u==ii) || (truoc2==v && v==jj)) d[ii][jj]=min(d[u][v],d[ii][jj]);
                else d[ii][jj]=min(d[ii][jj],d[u][v]+1);


                tr[ii][jj]=++dem;
                nho1[dem]=u;
                nho2[dem]=v;
                pq.push(make_pair(ii,jj));
              }
         }
      }
}

void bfs2()
{
   queue <ii> pq;
   pq.push(make_pair(l2,c2));
   dd[l2][c2]=0;
   long long dem=1;
   nho1[1]=l2;
   nho2[1]=c2;
   tr[l2][c2]=1;
   a1[l2][c2]=1;
   while (!pq.empty())
     {
       int u=pq.front().first;
       int v=pq.front().second;
       pq.pop();
       for (long i=0; i<=3; i++)
        {
           int ii=u+d2[i], jj=v+d1[i];
           if (ii<=n && ii>=1 && jj>=1 && jj<=n)
             if (a1[ii][jj]==0)
              {
                long truoc1=nho1[tr[u][v]],truoc2=nho2[tr[u][v]];
                a1[ii][jj]=1;
                if ((truoc1==u && u==ii) || (truoc2==v && v==jj)) dd[ii][jj]=min(dd[u][v],dd[ii][jj]);
                else dd[ii][jj]=min(dd[ii][jj],dd[u][v]+1);


                tr[ii][jj]=++dem;
                nho1[dem]=u;
                nho2[dem]=v;
                pq.push(make_pair(ii,jj));
              }
         }
      }
}

/*void dfs(long l,long c)
{
       for (long i=0; i<=3; i++)
         {
           int ii=l+d1[i], jj=c+d2[i];
           if (ii<=n && ii>=1 && jj>=1 && jj<=n)
            if (a1[ii][jj]==0)
              {
                long truoc1=nho1[tr[l][c]],truoc2=nho2[tr[l][c]];
                a1[ii][jj]=1;

                //cout << truoc2 << " " << c << " " << jj << endl;

                if (truoc1==l && l==ii) d[ii][jj][1]=min(d[l][c][1],d[ii][jj][1]);
                if (truoc2==c && c==jj) d[ii][jj][2]=min(d[l][c][2],d[ii][jj][2]);
                if (truoc1==l && ii!=l) d[ii][jj][1]=min(d[ii][jj][1],d[l][c][1]+1);
                if (truoc2==c && jj!=c) d[ii][jj][2]=min(d[ii][jj][2],d[l][c][2]+1);

                tr[ii][jj]=++dem;
                nho1[dem]=l;
                nho2[dem]=c;
                dfs(ii,jj);
                a1[ii][jj]=0;
              }
         }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("robot.inp","r",stdin);
    freopen("robot.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
     for (long j=1; j<=n; j++)
         {cin >> a[i][j];
         a1[i][j]=a[i][j];}
    cin >> l1 >> c1 >> l2 >> c2;

    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        d[i][j]=vc;

    /*d[l1][c1][1]=0;
    d[l1][c1][2]=0;
    nho1[1]=l1;
    nho2[1]=c1;
    tr[l1][c1]=1;
    a1[l1][c1]=1;*/
    bfs();
    for (long i=1; i<=n; i++)
     for (long j=1; j<=n; j++)
        {a1[i][j]=a[i][j];
        dd[i][j]=vc;}
    bfs2();
    //cout << d[l2][c2] << " ";
    cout << d[2][3];
    /*dfs(l1,c1);
    cout << d[1][5][2];*/
}
