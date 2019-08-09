#include <bits/stdc++.h>

using namespace std;

long long n,v[30],c,dem[100007],a[100000007];
bool so[100007];

void print(long k)
{
   /*for (long i=1; i<=k; i++)
     if (a[i]!=0)
      cout << a[i] << " ";
   cout << endl;*/
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
   ios_base::sync_with_stdio(0);
   freopen("Change.inp","r",stdin);
   freopen("Change.out","w",stdout);
   cin >> n;
   memset(so,false,sizeof(so));
   for (long i=1; i<=n; i++) {cin >> v[i]; so[v[i]]=true;}
   cin >> c;
   tong(c);
}
