#include <bits/stdc++.h>
#define nmax 500

using namespace std;

long long n,m,k,sum1[nmax][nmax],ans=0,ts[nmax];
char a[nmax][nmax];

long long sum(long l1, long r1, long l2, long r2)
{
    return sum1[l2][r2]-sum1[l2][r1-1]-sum1[l1-1][r2]+sum1[l1-1][r1-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Letters.inp","r",stdin);
    freopen("Letters.out","w",stdout);
    cin >> n >> m >> k;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=m; j++)
        {
            cin >> a[i][j];
            if (a[i][j]=='a') sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+1;
            else sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1];
        }
    for (long r1=1; r1<=n; r1++)
       for (long r2=r1+1; r2<=n; r2++)
        {
            memset(ts,0,sizeof(ts));
            long long c1=1,c2;
            for (c2=1; c2<=m; c2++)
            {
                while (c1<c2 && sum(r1,c1,r2,c2)>k)
                {
                    if (a[r1][c1]==a[r2][c2]) ts[a[r1][c1]]--;//ts[ch]: số lần xuất hiện kí tự ch
                    c1++;
                }
                if (a[r1][c2]==a[r2][c2])
                {
                    ans+=(long long)ts[a[r1][c2]];
                    ts[a[r1][c2]]++;
                }
            }
        }
    cout << ans;
}
