#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,a[2*nmax],dd[2*nmax];

void sub1()
{
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    long long ans=0;
    dd[1]=1;
    a[n+1]=999999999999;
    for (long i=2; i<=n; i++)
    {
        for (long j=2; j<=n; j++) dd[j]=0;
        long long h=a[i]-a[1];
        dd[i]=1;
        bool ok=true;
        for (long j=2; j<=n; j++)
          if (dd[j]==0)
          {
             long long vt=lower_bound(a+1,a+n+1,a[j]+h)-a;
             if (a[vt]!=a[j]+h)
             {
                 ok=false;
                 break;
             }
             dd[j]=1;
             dd[vt]=1;
          }
        if (ok) ans++;
    }
    cout << ans;
}

void sub2()
{
    n/=2;
    long long ans=0;
    for (long i=1; i<=n; i++)
       if (n%i==0) ans++;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GRN.inp","r",stdin);
    freopen("GRN.out","w",stdout);
    cin >> n;
    n*=2;
    if (n/2<=1000) sub1();
    else sub2();
}
