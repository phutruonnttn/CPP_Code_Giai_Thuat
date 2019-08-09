#include <bits/stdc++.h>

using namespace std;

long n,a[30],x[30],cv[200000000],maxx;
bool dd[30];

void tinh()
{
    long chuvi=0;
    for (long i=1; i<=n; i++)
    {
      if ((a[x[i]]<=a[x[i+1]]) && (a[x[i]]<=a[x[i-1]]))  chuvi=chuvi+2;
      else
        if ((a[x[i]]<=a[x[i+1]]) && (a[x[i]]>a[x[i-1]])) chuvi=chuvi+2+a[x[i]]-a[x[i-1]];
         else
            if ((a[x[i]]>a[x[i+1]]) && (a[x[i]]<=a[x[i-1]])) chuvi=chuvi+2+a[x[i]]-a[x[i+1]];
              else chuvi=chuvi+2+a[x[i]]*2-a[x[i+1]]-a[x[i-1]];
    }
    cv[chuvi]++;
    maxx=max(maxx,chuvi);
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
    freopen("histogram.inp","r",stdin);
    freopen("histogram.out","w",stdout);
    while (1<2)
    {
        cin >> n;
        if (n==0) break;
        else
        {
            memset(a,0,sizeof(a));
            for (long i=1; i<=n ; i++)
                cin >> a[i];
            memset(cv,0,sizeof(cv));
            memset(x,0,sizeof(x));
            memset(dd,true,sizeof(dd));
            maxx=-1; giai(1);
            cout << maxx << " " << cv[maxx]<< endl;
        }
    }
}
