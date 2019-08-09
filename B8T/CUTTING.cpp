#include <bits/stdc++.h>

using namespace std;

long a[100000007],n,gt[100000007],ans=-1;

void print(long k)
{
   long tong=0;
   for (long i=1; i<=k; i++)
     if (a[i]!=0)
      tong+=gt[a[i]];
   ans=max(ans,tong);
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
   freopen("CUTTING.inp","r",stdin);
   freopen("CUTTING.out","w",stdout);
   cin >> n;
   for (long i=1; i<=n; i++) cin >> gt[i];
   tong(n);
   cout << ans;
}
