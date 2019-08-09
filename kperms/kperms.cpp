#include <bits/stdc++.h>

using namespace std;

long long d,n,k,x[20];
bool dd[20];

void tinh()
{
    bool ok=true;
    for (long i=1; i<=n-1; i++)
      if ((abs(x[i]-x[i+1]))>k)
      {
          ok=false;
          break;
      }
     if (ok==true) d=d+1;
}

void giai( long i)
{
    for (long j=1; j<=n; j++)
      if (dd[j])
      {
         x[i]=j;
         dd[j]=false;
         if (i==n) tinh();
         else giai(i+1);
         dd[j]=true;
      }
}


int main()
{
    freopen("kperms.inp","r",stdin);
    freopen("kperms.out","w",stdout);
    memset(dd,true,sizeof(dd));
    cin >> n >> k;
    d=0;
    giai(1);
    cout << d;
}
