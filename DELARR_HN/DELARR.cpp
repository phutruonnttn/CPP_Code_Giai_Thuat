#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,a[nmax],a1[nmax],f[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DELARR.inp","r",stdin);
    freopen("DELARR.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    if (a[1]==0)
    {
        long long dem=1;
        for (long i=2; i<=n; i++) if (a[i]==0) dem++;
        cout << n-dem;
        return 0;
    }
    if (a[1]>0)
    {
        cout << n;
        return 0;
    }
    if (a[n]==0)
    {
        long long dem=1;
        for (long i=1; i<=n-1; i++) if (a[i]==0) dem++;
        cout << n-dem;
        return 0;
    }
    if (a[n]<0)
    {
        cout << n;
        return 0;
    }
    long long dem0=0,sl=0;
    for (long i=1; i<=n; i++)
      if (a[i]!=0) a1[++sl]=a[i];
    else dem0++;

    //for (long i=1;i<=sl;i++) cout << a1[i] << " ";cout << endl;

    long long vtd=0;
    for (long i=1; i<=sl; i++)
      if (a1[i]>0)
      {
          f[i]=a1[i];
          vtd=i;
          break;
      }
      else f[i]=f[i-1]+a1[i];
    for (long i=vtd+1; i<=sl; i++)
       f[i]=f[i-1]+a1[i];

    for (long i=1; i<=vtd-1; i++)
    {
        long long s1=f[vtd-1]-f[i-1],v1=lower_bound(f+vtd,f+sl+1,-s1)-f;
        //cout << s1 << " " << f[v1] << endl;
        if (s1+f[v1]==0)
        {
            cout << (sl-v1)+(i-1);
            return 0;
        }
    }
    cout << n-dem0;
}
