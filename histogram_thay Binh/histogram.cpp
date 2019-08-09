#include <bits/stdc++.h>
#define nmax 1e9+7

using namespace std;

long n,dp[1<<17][17],h[17],dem[1<<17][17],nho[1<<17][17];

long calc(long y, long j)
{
    if (y==1<<(j-1)) {dp[y][j]=2*h[j]+2; return dp[y][j];}
    if (nho[y][j]==1) return dp[y][j];
    nho[y][j]=1; dp[y][j]=0;
    long x=y^(1<<(j-1));
    for (long i=1; i<=n; i++)
     if (x>>(i-1)&1==1)
      {
         long tmp=calc(x,i);
         if (dp[y][j]<tmp+h[j]-h[i]+abs(h[j]-h[i])+2)
         {
             dp[y][j]<tmp+h[j]-h[i]+abs(h[j]-h[i])+2;
             dem[y][j]=dem[x][i];
         }
         if (dp[y][j]==tmp+h[j]-h[i]+abs(h[j]-h[i])+2) dem[y][j]+=dem[x][i];
      }
    return dp[y][j];
}

void tinh()
{
   for (long i=1; i<=n; i++) cin >> h[i];
   memset(dp,0,sizeof(dp));
   memset(nho,0,sizeof(nho));
   memset(dem,0,sizeof(dem));
   long ans=-1, sl=0;
   for (long i=1; i<=n; i++) cout <<calc(1<<(n-1),i) << " ";
    /*if (ans<calc(1<<(n-1),i))
     {
        ans=dp[1<<(n-1)][i];
        sl=dem[1<<(n-1)][i];
     }
    cout << ans << " " << sl << '\n';*/
}

int main()
{
    freopen("histogram.inp","r",stdin);
    freopen("histogram.out","w",stdout);
    while (1<2)
    {
        cin >> n;
        if (n==0) break;
        else tinh();
    }
}
