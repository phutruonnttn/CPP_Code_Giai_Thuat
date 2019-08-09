#include <bits/stdc++.h>

using namespace std;

long long n,a[20][20],x[20];
long long ans=10000000000,sum,best;
bool dd[20];

void tinh()
{
    if (sum<best) best=sum;
    ans=min(ans,best);
}

void giai( long i)
{
    if (sum>=best) return;
    for (long j=1; j<=n; j++)
      if (dd[j])
      {
         x[i]=j;
         dd[j]=false;
         sum+=a[x[i-1]][j];
         if (i==n) tinh();
         else giai(i+1);
         sum-=a[x[i-1]][j];
         dd[j]=true;
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("lem3.inp","r",stdin);
    freopen("lem3.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=n; j++)
         cin >> a[i][j];
    memset(dd,true,sizeof(dd));
    best=0; sum=0;
    for (long i=2; i<=n; i++)
        best+=a[i-1][i];
    giai(1);
    cout << ans;
}
