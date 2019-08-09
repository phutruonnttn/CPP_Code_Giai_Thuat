#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,k,a[nmax],f[1007][1007],bb[7*nmax],b[7*nmax],d[7*nmax];

void sub1()
{
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
      {
          f[i][j]=max(f[i][j],max(f[i-1][j],f[i][j-1]));
          if (abs(i-a[j])<=k) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
      }
    cout << f[n][n];
}

void sub2()
{
    long dem=0;
    for (long i=1; i<=n; i++)
       for (long j=min(n,a[i]+k); j>=max((long long)1,a[i]-k); j--)
        bb[++dem]=j;
    long long ans=0;
    for (long i=1; i<=dem; i++) b[i]=1000000007;
    for (long i=1; i<=dem; i++)
    {
        d[i]=lower_bound(b+1,b+dem+1,bb[i])-b;
        b[d[i]]=bb[i];
        ans=max(ans,d[i]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("L1L2K.inp","r",stdin);
    freopen("L1L2K.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) cin >> a[i];
    if (n<=1000) sub1();
    else sub2();
}
