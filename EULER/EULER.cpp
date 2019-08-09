#include <bits/stdc++.h>

using namespace std;

long n;
long long c[100007],snt[100007];
bool prime[100007];

void sangnt()
{
   memset(prime,0,sizeof(prime));
   prime[1]=1 ;
   for (long i=2; i<=trunc(sqrt(n)); i++)
    if (prime[i]==0)
     {
        long j=i*i;
        while (j<=n)
         {
             prime[j]=1;
             j=j+i;
         }
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("EULER.inp","r",stdin);
    freopen("EULER.out","w",stdout);
    cin >> n;
    c[1]=1;
    c[2]=1;
    sangnt();

    long dem=0;

    for (long i=1; i<=n; i++)
    if (prime[i]==0) snt[++dem]=i;

    //for (long i=1; i<=dem; i++) cout << snt[i] << " ";

    for (long i=3; i<=n; i++)
       c[i]=i;

    long long nt[100007]; nt[0]=0;

    for (long i=3; i<=n; i++)
       {
          long d=1,d1=0;
          long j=i;
          if (prime[j]==0) nt[++d1]=j;
          else
          {
          while (j!=1)
          {
              if (j % snt[d]==0)
              {
                 j=(j / snt[d]);
                 if (snt[d]!=nt[d1])
                    nt[++d1]=snt[d];
              }
              else d++;
          };
          };
          for (long l=1; l<=d1; l++)
            c[i]=(c[i]*(nt[l]-1))/nt[l];
       };

     //for (long i=1; i<=n; i++) cout << c[i] << " ";

     long long ans=0;
     for (long i=1; i<=n; i++) ans+= c[i];
     cout << ans;
}
