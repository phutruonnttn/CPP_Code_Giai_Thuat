#include <bits/stdc++.h>

using namespace std;

long m,n,a[1007][1007],ans=-1,x,y,r;
bool OK1=true,OK2=true;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RBULL.inp","r",stdin);
    freopen("RBULL.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
       {
          char s; cin >> s;
          if (s=='.') OK1=false;
          else OK2=false;
          if (s=='*') a[i][j]=1;
       }

    if (OK1) cout << "1 1 1 0";
    else
     if (OK2) cout << "0 1 1 0";
    else
    {
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
        {
           long rt=min(min(i-1,m-i),min(j-1,n-j));
           //cout << rt << endl;
           bool ok=false;
           while (!ok && rt>=0)
           {
               long sococ=0; bool ok1=true;
               for (long ii=i-rt; ii<=i+rt; ii++)
                if (ok1)
                 for (long jj=j-rt; jj<=j+rt; jj++)
                  {
                    if (a[ii][jj]==1)
                    {
                        long t1=i-ii, t2=j-jj;
                        if (abs(t1)+abs(t2)>rt) continue;
                        sococ++;
                        t1=i-ii-1; t2=j-jj;
                        if (abs(t1) + abs(t2)<=rt && a[ii+1][jj]==1) {rt--;ok1=false; break;};
                        t1=i-ii+1; t2=j-jj;
                        if (abs(t1) + abs(t2)<=rt && a[ii-1][jj]==1) {rt--;ok1=false; break;};
                        t1=i-ii; t2=j-jj+1;
                        if (abs(t1) + abs(t2)<=rt && a[ii][jj-1]==1) {rt--;ok1=false; break;};
                        t1=i-ii; t2=j-jj-1;
                        if (abs(t1) + abs(t2)<=rt && a[ii][jj-1]==1) {rt--;ok1=false; break;};
                    }
                  }
               if (ok1)
               {
                   ok=true;
                   if (ans<sococ)
                   {
                       ans=sococ;
                       x=i; y=j; r=rt;
                   }
               }
           }
        }
      cout << ans << " " << x <<  " " << y << " " << r;
    }
}
