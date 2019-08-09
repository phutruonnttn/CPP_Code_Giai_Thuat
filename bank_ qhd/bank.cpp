#include <bits/stdc++.h>
#define nmax 10007

using namespace std;

struct data
{
    long long w,t;
};

long long n,f[nmax][nmax];
data kh[nmax];

bool cmp(data q, data p)
{
    return q.t < p.t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BANK.inp","r",stdin);
    freopen("BANK.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      cin >> kh[i].w >> kh[i].t;
    sort(kh+1,kh+n+1,cmp);
    for (long i=1; i<=n; i++)
      for (long j=0; j<=kh[i].t; j++)
        f[i][j]=max(f[i][j],max(f[i-1][j],f[i-1][j-1]+kh[i].w));
    long long ans=-1;
    for (long i=1; i<=n; i++)
       for (long j=0; j<=1000; j++)
         ans=max(ans,f[i][j]);
    cout << ans;
}
