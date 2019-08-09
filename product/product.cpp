#include <bits/stdc++.h>

using namespace std;

long long n,res1=-3,l1,r1,a[200007],res2=0,l2,r2;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PRODUCT.inp","r",stdin);
    freopen("PRODUCT.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i];
        if (a[i]>res1)
        {
            res1=a[i];
            l1=i;
            r1=i;
        }
    }

    long long t0=0, c0=0, t1=-1, c1=0, t=0, c=0;
    for (long i=1; i<=n; i++)
      {
        if (abs(a[i])==2) c=c+1;
        if (a[i]<0) t=1-t;
        if (a[i]==0)
         {
            t0=i; c0=0; t1=-1; c1=0; c=0; t=0;
            continue;
         }
        if (t==1)
          {
            if (t1==-1)
              {
                t1=i; c1=c;
              }
            else
            if (res2<c-c1)
              {
                res2=c-c1;
                l2=t1+1;
                r2=i;
              }
          }
        else
        if (res2<c-c0)
          {
            res2=c-c0;
            l2=t0+1;
            r2=i;
          }
      }
      if (r2!=0) cout << l2 << " " << r2;
      else cout << l1 << " " << r1;
}
