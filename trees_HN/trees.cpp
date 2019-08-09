#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

long long n,a[nmax][nmax],nhom1[nmax],nhom2[nmax],d1,d2,dd[nmax];

bool kt(long long k)
{
    d1=0; d2=0;
    bool ok;
    for (long i=1; i<=n; i++) dd[i]=0;
    nhom1[++d1]=1;
    dd[1]=1;
    for (long i=n; i>=2; i--)
    {
        ok=true;
        for (long j=1; j<=d1; j++)
           if (a[nhom1[j]][i]>k)
           {
               ok=false;
               break;
           }
        if (ok)
        {
            dd[i]=1;
            nhom1[++d1]=i;
        }
    }

    for (long i=1; i<=n; i++)
      if (dd[i]==0)
      {
         for (long j=1; j<=d2; j++)
            if (a[nhom2[j]][i]>k) return false;
         nhom2[++d2]=i;
      }
    return true;
}

bool kt1(long long k)
{
    d1=0; d2=0;
    bool ok;
    for (long i=1; i<=n; i++) dd[i]=0;
    nhom1[++d1]=1;
    dd[1]=1;
    for (long i=2; i<=n; i++)
    {
        ok=true;
        for (long j=1; j<=d1; j++)
           if (a[nhom1[j]][i]>k)
           {
               ok=false;
               break;
           }
        if (ok)
        {
            dd[i]=1;
            nhom1[++d1]=i;
        }
    }

    for (long i=1; i<=n; i++)
      if (dd[i]==0)
      {
         for (long j=1; j<=d2; j++)
            if (a[nhom2[j]][i]>k) return false;
         nhom2[++d2]=i;
      }
    return true;
}

bool kt3(long long k)
{
    d1=0; d2=0;
    bool ok;
    for (long i=1; i<=n; i++) dd[i]=0;
    nhom1[++d1]=1;
    dd[1]=1;
    for (long i=n/2; i<=n; i++)
    {
        ok=true;
        for (long j=1; j<=d1; j++)
           if (a[nhom1[j]][i]>k)
           {
               ok=false;
               break;
           }
        if (ok)
        {
            dd[i]=1;
            nhom1[++d1]=i;
        }
    }

    for (long i=n/2-1; i>=1; i--)
    {
        ok=true;
        for (long j=1; j<=d1; j++)
           if (a[nhom1[j]][i]>k)
           {
               ok=false;
               break;
           }
        if (ok)
        {
            dd[i]=1;
            nhom1[++d1]=i;
        }
    }

    for (long i=1; i<=n; i++)
      if (dd[i]==0)
      {
         for (long j=1; j<=d2; j++)
            if (a[nhom2[j]][i]>k) return false;
         nhom2[++d2]=i;
      }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("trees.inp","r",stdin);
    freopen("trees.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n-1; i++)
       for (long j=i+1; j<=n; j++)
       {
           cin >> a[i][j];
           a[j][i]=a[i][j];
       }
    long long l=0, r=1000000,ans;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    l=0, r=1000000;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt1(mid))
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }

    l=0, r=1000000;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt3(mid))
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }

    cout << ans;
}
