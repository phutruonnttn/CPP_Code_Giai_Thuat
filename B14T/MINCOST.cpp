#include <bits/stdc++.h>

using namespace std;

long long n,m,a[10007][10007],ans=10000000000;

void loang(long i, long j,long long tong)
{
    if (i==n && j==m) ans=min(ans,tong);
    if (a[i+1][j]!=-10000000000) {long long tt=a[i+1][j];a[i+1][j]=-10000000000;loang(i+1,j,tong+tt);a[i+1][j]=tt; }
    if (a[i-1][j]!=-10000000000) {long long tt=a[i-1][j];a[i-1][j]=-10000000000;loang(i-1,j,tong+tt); a[i-1][j]=tt;}
    if (a[i][j+1]!=-10000000000) {long long tt=a[i][j+1];a[i][j+1]=-10000000000;loang(i,j+1,tong+tt); a[i][j+1]=tt;}
    if (a[i][j-1]!=-10000000000) {long long tt=a[i][j-1];a[i][j-1]=-10000000000;loang(i,j-1,tong+tt); a[i][j-1]=tt;}
    if (a[i+1][j+1]!=-10000000000) {long long tt=a[i+1][j+1];a[i+1][j+1]=-10000000000;loang(i+1,j+1,tong+tt); a[i+1][j+1]=tt;}
    if (a[i+1][j-1]!=-10000000000) {long long tt=a[i+1][j-1];a[i+1][j-1]=-10000000000;loang(i+1,j-1,tong+tt); a[i+1][j-1]=tt;}
    if (a[i-1][j-1]!=-10000000000) {long long tt=a[i-1][j-1];a[i-1][j-1]=-10000000000;loang(i-1,j-1,tong+tt); a[i-1][j-1]=tt;}
    if (a[i-1][j+1]!=-10000000000) {long long tt=a[i-1][j+1];a[i-1][j+1]=-10000000000;loang(i-1,j+1,tong+tt); a[i-1][j+1]=tt;}
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MINCOST.inp","r",stdin);
    freopen("MINCOST.out","w",stdout);
    cin >> n >> m;
    //memset(a,-10000000000,sizeof(a));
    for (long i=0; i<=n+1; i++)
       for (long j=0; j<=m+1; j++)
         a[i][j]=-10000000000;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=m; j++)
         cin >> a[i][j];
    loang(1,1,a[1][1]);
    cout << ans;
}
