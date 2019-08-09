#include <bits/stdc++.h>

using namespace std;

long a[100000000], n=99783;

void print(long k)
{
   for (long i=1; i<=k; i++)
     if (a[i]!=0)
      cout << a[i] << " ";
   cout << endl;
}

void tong(long n)
{
   for (long i=1; i<=n; i++) a[i]=0;
   a[n]=n;
   print(n);
   long i=n;
   while (a[i]>1)
   {
      long j=i;
      while (a[j]>1) j--;
      a[j]=a[j]+1;
      a[j+1]=a[j+1]-1;
      print(n);
      if (a[i]>1)continue;
      i=i-1;
   }
}

int main()
{
   tong(n);
   return 0;
}
