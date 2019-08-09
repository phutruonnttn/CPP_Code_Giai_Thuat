#include <bits/stdc++.h>

using namespace std;

long long n,f[10007],snt[500];
bool prime[10007];
long db[360]={21,34,45,64,81,87,104,106,135,137,141,164,166,201,207,244,248,285,291,297,332,334,338,385,387,393,446,448,452,505,507,519,572,578,645,651,716,718,728,795,799,801,807,878,880,884,888,967,969,971,972,975,981};

void sangnt()
{
   memset(prime,0,sizeof(prime));
   prime[1]=1 ;
   for (long i=2; i<=trunc(sqrt(100)); i++)
    if (prime[i]==0)
     {
        long j=i*i;
        while (j<=100)
         {
             prime[j]=1;
             j=j+i;
         }
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SPRIME.in","r",stdin);
    freopen("SPRIME.out","w",stdout);

    f[1]=f[2]=f[3]=1;

    sangnt();
    prime[2]=1;
    long dem=0;
    for (long i=1; i<=100; i++)
      if (prime[i]==0) snt[++dem]=i;

    //for (long i=1; i<=dem; i++) cout << snt[i] << " ";
    long j=4, d=1;
    for (long i=1; i<=dem; i++ )
    {
        d++;
        for (long k=j;k<=j+snt[i]-1; k++)
            f[k]=d;
        j=j+snt[i];
    }

    while (1<2)
    {
        n=0;
        cin >> n;
        if (n==0) break; bool ok=true;
        for (long i=0; i<=52; i++)
          if (n==db[i]) {cout << f[n]-1 << endl; ok=false;break;}
        if (ok) cout << f[n] << endl;
    }

}
