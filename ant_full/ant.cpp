#include <bits/stdc++.h>
#define vc 1000000007

using namespace std;
typedef pair <int,int> ii;

int a[5007][5007];
int n,s,d1[5]={0,0,1,-1},d2[5]={1,-1,0,0};
long long ans=0,d[5007][5007];

void bfs()
{
   queue <ii> pq;
   pq.push(make_pair(1001,1001));
   d[1001][1001]=0;
   a[1001][1001]=1;
   while (!pq.empty())
     {
       int u=pq.front().first;
       int v=pq.front().second;
       pq.pop();
       if (d[u][v]>s) continue;
       for (long i=0; i<=3; i++)
        {
           int ii=u+d1[i], jj=v+d2[i];
           if (ii<=2002 && ii>=0 && jj>=0 && jj<=2002)
             if (a[ii][jj]==0)
              {
                a[ii][jj]=1;
                d[ii][jj]=d[u][v]+1;
                pq.push(make_pair(ii,jj));
              }
         }
      }
}

long long t1(long x)
{
    long long res=0;
    for (long i=0; i<=2002; i++)
      if (d[x][i]<s) res+=s-d[x][i];
    return res;
}

long long t2(long x)
{
    long long res=0;
    for (long i=0; i<=2002; i++)
      if (d[i][x]<s) res+=s-d[i][x];
    return res;
}

long long t3(long x, long y)
{
    if (d[x][y]>=s) return 0;
    return (s-d[x][y])*(s-d[x][y]-1)/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ant.inp","r",stdin);
    freopen("ant.out","w",stdout);
    cin >> n >> s;
    for (long i=1; i<=n; i++)
    {
        int b,c;
        cin >> b >> c;
        a[b+1001][c+1001]=1;
    }
    for (long i=0; i<=2007; i++)
      for (long j=0; j<=2007; j++)
       d[i][j]=vc;
    bfs();
    for (long i=0; i<=2002; i++)
     for (long j=0; j<=2002; j++)
       if (d[i][j]<=s) ans++;
    //cout << ans;
    ans+=t1(0)+t1(2002)+t2(0)+t2(2002)+t3(0,2002)+t3(0,0)+t3(2002,0)+t3(2002,2002);
    cout << ans;
}
