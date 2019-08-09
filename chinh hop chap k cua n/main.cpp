#include <bits/stdc++.h>

using namespace std;

long n,k,x[100007],b[100007];

void ghinhan()
{
    for (long i=1; i<=k; i++)
      cout << x[i] << " ";
     cout << endl;
}

void chinhhopkl(long i, long k)
{
   for (long j=1; j<=n; j++)
    if (b[j]==0)
     {
         x[i]=j;
         b[j]=1;
         if (i==k) ghinhan();
         else chinhhopkl(i+1,k);
         b[j]=0;
     }
}

int main()
{
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n >> k;
    chinhhopkl(1,k);
}
