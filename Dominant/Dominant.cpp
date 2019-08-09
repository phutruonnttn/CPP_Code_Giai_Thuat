#include <bits/stdc++.h>
#define nmax 300007

using namespace std;

long long v,f1[nmax],f0[nmax],n,f[nmax],res[nmax],ans=-1;
string a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("Dominant.inp","r",stdin);
    freopen("Dominant.out","w",stdout);
    cin >> v;
    cin >> a;
    n=a.size();
    a="*"+a;
    for (long i=1; i<=n; i++)
    {
      if (a[i]=='1')
      {
         f1[i]=f1[i-1]+1;
         f0[i]=i-f1[i];
      }
      else
      {
         f1[i]=f1[i-1];
         f0[i]=i-f1[i];
      }
      f[i]=f1[i]-f0[i];
    }
   res[1]=f[1];
   for (long i=2; i<=n; i++)
     res[i]=min(res[i-1],f[i]);

   for (long i=1; i<=n; i++)
   {
       long long l=0, r=i, h=i;
       while (l<=r)
       {
           long g=(l+r)/2;
           if (res[g]<f[i]) {r=g-1; h=g;}
           else l=g+1;
       }
       ans=max(ans,i-h);
   }
   if (v==1) cout << ans;
   else
   {
       long long k=0;
       for (long i=1; i<=n-ans+1; i++)
          if (f1[i+ans-1]-f1[i-1]>f0[i+ans-1]-f0[i-1])
             k++;
       cout <<k;
   }
}
