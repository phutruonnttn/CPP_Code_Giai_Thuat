#include <bits/stdc++.h>

using namespace std;

long n,a[300],b[300],vtria[300],vtrib[300],vtrix[300],rb1[300],rb2[300],x[300];
bool dd[300];
long long d,dem;

void ktra()
{
  bool ok=true;
  for (long i=1; i<=n; i++)
    vtrix[x[i]]=i;
  for (long i=1; i<=d; i++)
    if (vtrix[rb1[i]]>vtrix[rb2[i]]) {ok=false; break;}
  if (ok) dem++;
}

void giai( long i)
{
    for (long j=1; j<=n; j++)
      if (dd[j])
      {
         x[i]=j;
         dd[j]=false;
         if (i==n) ktra();
         else giai(i+1);
         dd[j]=true;
      }
}


int main()
{
    freopen("GENETIC.inp","r",stdin);
    freopen("GENETIC.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    for (long i=1; i<=n; i++)
        cin >> b[i];
    for (long i=1; i<=n; i++)
    {
        vtria[a[i]]=i;
        vtrib[b[i]]=i;
    };
    d=0; dem=0;
    for (long i=1; i<=n-1; i++)
      for (long j=i; j<=n; j++)
        if (vtrib[a[i]]<vtrib[a[j]])
        {
            d++;
            rb1[d]=a[i]; rb2[d]=a[j];
        }
     memset(dd,true,sizeof(dd));
     giai(1);
     cout << dem;
}
