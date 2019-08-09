#include <bits/stdc++.h>
#define nmax 27
#define vc 999999999999

using namespace std;

long long n,a[nmax],b[nmax][nmax],s=0,l[1<<21][27];

long getbit(long k, long x)
{
    return ((x>>k)&1);
}

void batbit(long k, long &x)
{
    x=x|(1<<k);
}

void tatbit(long k, long &x)
{
    x=x&~(1<<k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("robot.inp","r",stdin);
    freopen("Robot.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i]; s+=a[i];}
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        cin >> b[i][j];
    /*for (long i=0; i<=(1<<n); i++)
      for (long j=0; j<=n; j++) f[i][j]=-vc;*/

    long long ans=1<<n;
    for (long x=0; x<=ans-1; x++)
      for (long j=0; j<n; j++)
        if (getbit(j,x)==1)
        {
            for (long p=0; p<n; p++)
               if (getbit(p,x)==0)
               {
                   long u=x;
                   batbit(p,u);
                   l[u][p+1]=max(l[u][p+1],l[x][j+1]+b[j+1][p+1]);
               }
        }
    long long tong=-vc-1;
    for (long i=1; i<=n; i++)
      tong=max(tong,l[ans-1][i]);
    cout << s-tong;
}
