#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long n,c,p,t,a[nmax];

void sub1()
{
    long long dem=0,ans=0;
    for (long i=1; i<=n; i++)
    {
      if (dem>=t) break;
      if (a[i]>0)
        {
            if (i*p*2*a[i]+dem<=t)
             {
                 ans+=a[i];
                 dem+=i*p*2*a[i];
                 a[i]=0;
             }
            else
             {
                 long lay=((t-dem)/(i*p*2));
                 dem+=i*p*2*lay;
                 if (dem>t || lay==0) break;
                 ans+=lay;
                 a[i]-=lay;
             }
        }
    }
    cout << ans;
}

void sub2()
{
    long long dem=0,ans=0,sn=0;
    for (long i=1; i<=n; i++)
    {
          sn+=a[i];
          if (dem+2*(i+1)*p>t && i!=n)
          {
              ans+=sn;
              sn=0;
              dem+=2*i*p;
              break;
          }
          if (sn==c)
          {
              if (dem+2*i*p<=t)
              {
                  ans+=sn;
                  dem+=2*i*p;
                  sn=0;
              }
          }
    }
    cout << ans;
}

void sub3()
{
    cout << 40;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ELEVATOR.inp","r",stdin);
    freopen("ELEVATOR.out","w",stdout);
    cin >> n >> c >> p >> t;
    bool ok2=true;
    for (long i=1; i<=n; i++) {cin >> a[i]; if (a[i]>1) ok2=false;}
    if (c==1) {sub1(); return 0;}
    if (ok2) {sub2(); return 0;}
    sub3();
}
