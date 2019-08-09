#include <bits/stdc++.h>

using namespace std;

long m,t,nt[1000007],dem,p[1000007],dlt[1000007],tinh[1000007],d;
map <long,long> M;

void sang()
{
    for (long i=2; i<=1000000; i++) nt[i]=i;
    for (long i=2; i<=1000; i++)
      if (nt[i]==i)
      {
         long j=i*i;
         while (j<=1000000)
         {
             nt[j]=i;
             j+=i;
         }
      }
}

void phantich(long n)
{
    while (n>1)
    {
        p[++dem]=nt[n];
        n=n/p[dem];
        if (M[p[dem]]==0)
        {
            M[p[dem]]=++d;
            tinh[d]++;
        }
        else tinh[M[p[dem]]]++;
        /*if (danhdau[iii][p[dem]]==0)
        {
            danhdau[iii][p[dem]]=++d;
            tinh[d]++;
        }
        else tinh[iii][danhdau[p[dem]]]++;*/
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DIV.inp","r",stdin);
    freopen("DIV.out","w",stdout);
    sang();
    cout << nt[6];
    cin >> t;
    for (long i=1; i<=t; i++)
    {
        cin >> m;
        M.clear();
        dem=0; d=0;
        long ans1=1,ans2=1;
        for (long j=0; j<=2; j++) phantich(m+j);
        /*sort(p+1,p+dem+1);
        for (long j=1; j<=p[dem]; j++) dlt[j]=0;
        for (long j=1; j<=dem; j++)
           dlt[p[j]]++;
        for (long j=1; j<=p[dem]; j++)
           if (dlt[j]!=0) ans1*=(dlt[j]+1);
        for (long j=1; j<=p[dem]; j++)
           if (dlt[j]!=0) ans2*=(2*dlt[j]+1);*/
        for (long j=1; j<=d; j++)
           ans1*=(tinh[j]+1);
        for (long j=1; j<=d; j++)
           ans2*=(2*tinh[j]+1);
        for (long j=1; j<=d; j++) tinh[j]=0;
        cout << trunc(ans2/2)+1-ans1 << endl;
    }
}
