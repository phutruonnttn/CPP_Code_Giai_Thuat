#include <bits/stdc++.h>

using namespace std;
bool dd[100000007];
long k,nt[100000007];

void snt()
{
   memset(dd,true,sizeof(dd));
   dd[1]=false;
   for (long i=2; i<=trunc(sqrt(10000000)); i++)
    if (dd[i]==true)
     {
        long j=i*i;
        while (j<=10000000)
        {
             dd[j]=false;
             j=j+i;
        }
     }
}

bool check(long long x)
{
    for (long i=2; i<=trunc(sqrt(x)); i++)
      if (x % i==0) return false;
    return true;
}

bool kt(long long x, long long y)
{
     long yy=y,d1=1;
     while (1<2)
     {
         if (yy/10!=0) {d1++; yy=yy/10;}
         else break;
     }
     for (long i=1; i<=d1; i++) x=x*10;
     x=x+y;
     return check(x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("mprime.inp","r",stdin);
    freopen("mprime.out","w",stdout);
    cin >> k;
    snt();
    long dem=0,ans=0,chay=-1;
    for (long i=1; i<=10000000; i++)
      if (dd[i]) nt[++dem]=i;
    while (ans<k)
    {
        chay+=2;
        if (kt(nt[chay],nt[chay+1])) ans++;
        if (ans==k)
        {
            cout << nt[chay] << nt[chay+1];
            return 0;
        }
    }
}
