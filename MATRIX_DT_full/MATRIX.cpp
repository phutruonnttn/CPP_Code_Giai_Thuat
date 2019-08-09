#include <bits/stdc++.h>
#define nmax 40007

using namespace std;

long long n,k,st[nmax],ans=0,dem0=0;
long long a[nmax];
string s;
map <long long,long long> M;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MATRIX.inp","r",stdin);
    freopen("MATRIX.out","w",stdout);
    cin >> k;
    cin >> s;
    n=s.size();
    for (long i=0; i<n; i++)
    {
        a[i+1]=s[i]-48;
        if (a[i+1]==0) dem0++;
        st[i+1]=st[i]+a[i+1];
    }
    if (k==0)
    {
       long long dd=((n-1)*(n-1)+(n-1))/2;
       ans=2*n*dem0-dem0*dem0+dem0*2*dd;
       long long dem=0;
       for (long i=1; i<=n-1; i++)
          for (long j=i+1; j<=n; j++)
            if (st[j]-st[i-1]==0) dem++;
       dd=(n*n+n)/2-dem0;
       ans=ans+2*dem*dd-dem*dem;
       cout << ans;
       return 0;
    }

    for (long i=1; i<=n; i++)
      for (long j=i; j<=n; j++)
      {
         long long sum=st[j]-st[i-1];
         if (sum!=0)
          if (k%sum==0) M[sum]++;
      }

    for (long i=1; i<=n; i++)
      for (long j=i; j<=n; j++)
      {
         long long sum=st[j]-st[i-1];
         if (sum!=0)
           if (k%sum==0) ans+=M[k/sum];
      }
    cout << ans;
}
