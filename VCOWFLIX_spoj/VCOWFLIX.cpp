#include <bits/stdc++.h>
#define nmax 10007

using namespace std;

long long c,n,w[nmax],x[20],ans=-1,f[nmax][nmax];

void kt()
{
    long long sum=0;
    for (long i=1; i<=n; i++)
      if (x[i]==1) sum+=w[i];
    if (sum<=c) ans=max(ans,sum);
}

void tryy_(long i)
{
    for (long j=0; j<=1; j++)
    {
        x[i]=j;
        if (i==n) kt();
        else tryy_(i+1);
    }
}

void sub1()
{
    tryy_(1);
    cout << ans;
}

void sub2()
{
    //f[i][j] la tong khoi luong bo lon nhat ma john co the mang di xem phim khi co i con bo va suc chua la j
    for (long i=1; i<=n; i++)
      for (long j=0; j<=c; j++)
         if (w[i]<=j) f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
         else f[i][j]=f[i-1][j];
    cout << f[n][c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VCOWFLIX.inp","r",stdin);
    freopen("VCOWFLIX.out","w",stdout);
    cin >> c >> n;
    for (long i=1; i<=n; i++) cin >> w[i];
    if (n<=20) sub1();
    else sub2();
}
