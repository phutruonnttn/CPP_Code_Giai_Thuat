#include <bits/stdc++.h>
#define nmax 100007
#define vc 9999999999

using namespace std;

long long t,n,a[nmax],b[nmax],kt[nmax],a1[nmax],bd[nmax],bg[nmax],kq[nmax],k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SUPERNUM.inp","r",stdin);
    freopen("SUPERNUM.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (long i=1; i<=n; i++)
         {
             cin >> a[i];
             b[i]=vc;
         }
        k=-1;
        for (long i=1; i<=n; i++)
          {
             kt[i]=lower_bound(b+1,b+n+1,a[i])-b;
             b[kt[i]]=a[i];
             k=max(k,kt[i]);
          }
        //for (long i=1; i<=n; i++) cout << kt[i] << " "; cout << endl;

        for (long i=n; i>=1; i--)
         {
             b[i]=vc;
             a1[n-i+1]=-a[i];
         }
        long dem=n;
        for (long i=1; i<=n; i++)
          {
             bg[i]=lower_bound(b+1,b+n+1,a1[i])-b;
             bd[dem--]=bg[i];
             b[bg[i]]=a1[i];
          }
        //for (long i=1; i<=n; i++) cout << bd[i] << " ";
        dem=0;
        for (long i=1; i<=n; i++)
           if (bd[i]+kt[i]==k+1) kq[++dem]=a[i];
        sort(kq+1,kq+dem+1);
        cout << dem << '\n';
        for (long i=1; i<=dem; i++)
          cout << kq[i] << " ";
        cout << '\n';
    }
}
