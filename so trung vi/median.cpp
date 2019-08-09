#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

long long m,n,r,c,a[nmax][nmax],b[nmax][nmax],tong[nmax][nmax],maxx=-1;

void taobang(long k)
{
    for (long i=1; i<=m; i++)
       for (long j=1; j<=n; j++)
        if (a[i][j]<=k) b[i][j]=1;
        else b[i][j]=0;
}

void taobang2()
{
    for (long i=1; i<=m; i++)
       for (long j=1; j<=n; j++)
         tong[i][j]=tong[i-1][j]+tong[i][j-1]-tong[i-1][j-1]+b[i][j];
}

long long sum(long l1, long r1, long l2, long r2)
{
    return tong[l2][r2]-tong[l2][r1-1]-tong[l1-1][r2]+tong[l1-1][r1-1];
}

bool kt(long long k)
{
    for (long i=1; i<=m-r+1; i++)
      for (long j=1; j<=n-c+1; j++)
        if (sum(i,j,i+r-1,j+c-1)>=(r*c)/2+1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("median.inp","r",stdin);
    freopen("median.out","w",stdout);
    //cin >> m >> n >> r >> c;
    scanf("%lld%lld%lld%lld",&m,&n,&r,&c);
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
        {//cin >> a[i][j];
        scanf("%lld",&a[i][j]);
        maxx=max(maxx,a[i][j]);}
    long long dau=0, cuoi=maxx,ans=0;
    while (dau<=cuoi)
    {
        long long giua=(dau+cuoi)/2;
        taobang(giua);
        taobang2();
        if (kt(giua))
        {
            ans=giua;
            cuoi=giua-1;
        }
        else dau=giua+1;
    }
    //cout << ans;
    printf("%lld",ans);
}
