#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long n,m,vtm,a[nmax],l[nmax],r[nmax],am[nmax],duong[nmax],tk0=0;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SREDNJI.inp","r",stdin);
    freopen("SREDNJI.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
      {cin >> a[i]; if (a[i]==m) vtm=i;}
    long lh=0,nh=0;
    for (long i=vtm; i>=1; i--)
    {
        if (a[i]>m) lh++;
        if (a[i]<m) nh++;
        l[i]=lh-nh;
        if (l[i]==0) tk0++;
        if (l[i]<0) am[-l[i]]++;
        if (l[i]>0) duong[l[i]]++;
    }
    //for (long i=1; i<=3; i++) cout << l[i] << " ";
    lh=0,nh=0;
    for (long i=vtm; i<=n; i++)
    {
        if (a[i]>m) lh++;
        if (a[i]<m) nh++;
        r[i]=lh-nh;
    }
    //for (long i=3; i<=5; i++) cout << r[i] << " ";
    long long ans=0;
    for (long i=vtm; i<=n; i++)
    {
        if (r[i]==0) ans+=tk0;
        if (r[i]<0)
        {
            long tim=-r[i];
            ans+=duong[tim];
        }
        if (r[i]>0)
        {
            ans+=am[r[i]];
        }
    }
    cout << ans;
}
