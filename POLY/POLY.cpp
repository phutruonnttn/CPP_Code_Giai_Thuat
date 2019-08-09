#include <bits/stdc++.h>

using namespace std;

int n,k,nn;
long x[207],y[207],xx[207];
bool dd[207];
float ans;

void ktra()
{
    bool ok1=false,ok2=false;
    for (long i=1; i<=nn-1; i++)
      if (x[xx[i]]!=x[xx[i+1]]) {ok1=true; break;};

    for (long i=1; i<=nn-1; i++)
      if (y[xx[i]]!=y[xx[i+1]]) {ok2=true; break;};

    if (ok1 && ok2)
    {
    float s=0;
    xx[nn+1]=xx[1];
    for (long i=1;i<=nn; i++)
       s=s+(float)(x[xx[i]]*y[xx[i+1]] - x[xx[i+1]]*y[xx[i]])/2;

    ans=max(ans,s);
    }
}

void tinh( long i)
{
    for (long j=1; j<=n; j++)
      if (dd[j])
      {
         xx[i]=j;
         dd[j]=false;
         if (i==nn) ktra();
         else tinh(i+1);
         dd[j]=true;
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("POLY.inp","r",stdin);
    freopen("POLY.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
      cin >> x[i] >> y[i];
    ans=0;
    for (long i=3; i<=k; i++)
    {
        nn=i;
        memset(dd,true,sizeof(dd));
        tinh(1);
    }
    cout << fixed << setprecision(2) << ans;
}
