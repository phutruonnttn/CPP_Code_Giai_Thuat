#include <bits/stdc++.h>
#define nmax 70

using namespace std;

long long n,a[nmax];

long long mu(long m)
{
    return 1ll<<m;
}

long long timstt(long long k)
{
   long long res=k,ct=0;
   for (long long i=1; i<=k; i++)
   {
       //if (i<k) res--;
       for (long j=a[i-n]+1; j<=a[i]-1; j++)
         res+=mu(n-j);
   }
   return res;
}

void timxau(long long t)
{
    a[0]=0;
    long dem=0;
    for (long i=1; i<=n; i++)
    {
        if (t==1) break;
            t--;
        for (long j=a[i-1]+1; j<=n; j++)
            if (t>mu(n-j)) t-=mu(n-j);
        else {
            a[++dem]=j;
            break;
        }
    }
    for (long i=1; i<=dem; i++)
        cout << a[i] << " ";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TAPCON.inp","r",stdin);
    freopen("TAPCON.out","w",stdout);
    cin >> n;

    cout << mu(n)-1 << '\n';

    a[1]=1; a[2]=2; a[3]=3;
    cout << timstt(3);
    //for (long i=1 ; i<=n+1; i++) timxau(i);
    /*long long tv;
    while (cin>>tv)
    {

    }*/
}
