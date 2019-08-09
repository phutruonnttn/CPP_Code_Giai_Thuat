#include <bits/stdc++.h>
#define nmod 1000000000

using namespace std;

long n,k,a[10007],t[10007];
int f[17][10007];

/*long long get(long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&-x);
    }
    return res;
}

void update(long x, long d)
{
    while (x<=10007)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("KINV.inp","r",stdin);
    freopen("KINV.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    //memset(t,0,sizeof(t));

    for (long i=1; i<=k; i++ )
      for (long j=1; j<=n; j++)
        f[i][j]=0;

    for (long i=1; i<=n; i++)
        f[1][i]=1;

    for (long i=1; i<=k; i++)
      for (long j=1; j<=n; j++)
      {
        for (long j1=1; j1<=j-1; j1++)
          if (a[j1]>a[j])
            f[i][j]=(f[i][j]+f[i-1][j1]) % nmod;
        /*f[i][j]=(f[i][j]+get(a[j]-1)) % nmod;
        update(a[j],f[i][j]);*/
      }

    long long ans=0;
    for (long i=1; i<=n; i++)
       ans=(ans+f[k][i]) % nmod;
    cout << ans;
}
