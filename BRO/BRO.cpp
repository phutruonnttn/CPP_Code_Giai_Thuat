#include <bits/stdc++.h>
#define nmax 30007
#define oo 99999999999999999
using namespace std;

long long a[2*nmax],b[2*nmax],n,ans=oo,aa[nmax],bb[nmax];
long long dem,sum,anss,t1p,t2p,t1pp,t2pp,tt1,tt2,t1,t2,vt,ta[nmax],tb[nmax];

long long cp(long long x)
{
   long long res=0;
   sum=0;
   for (long i=1; i<=x; i++)
      sum+=aa[i];
   for (long i=1; i<=x-1; i++)
   {
      sum-=aa[i];
      res+=bb[i]*sum;
   }
   tt1=res;
   sum=0;
   for (long i=x+1; i<=n; i++)
      sum+=aa[i];
   for (long i=n; i>=x+1; i--)
   {
      res+=bb[i]*sum;
      sum-=aa[i];
   }
   tt2=res-tt1;
   return res;
}

long long tinh(long k)
{
   dem=0;
   for (long i=k; i<=n+k-1; i++) aa[++dem]=a[i];
   dem=0;
   for (long i=k; i<=n+k-1; i++) bb[++dem]=b[i];
   anss=oo;
   for (long i=1; i<=n; i++)
   {
      long long rb=cp(i);
      if (anss>rb)
      {
          t1=tt1;
          t2=tt2;
          anss=rb;
          vt=i;
      }
   }
   return anss;
}

long long suma(long u, long v)
{
    u=u%n;
    if (u==0) u=n;
    v=v%n;
    if (v==0) v=n;
    if (u<=v) return ta[v]-ta[u-1];
    return ta[v]+ta[n]-ta[u-1];
}

long long sumb(long u, long v)
{
    u=u%n;
    if (u==0) u=n;
    v=v%n;
    if (v==0) v=n;
    if (u<=v) return tb[v]-tb[u-1];
    return tb[v]+tb[n]-tb[u-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRO.inp","r",stdin);
    freopen("BRO.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i] >> b[i];
    for (long i=n+1; i<=2*n; i++)
    {
        a[i]=a[i-n];
        b[i]=b[i-n];
    }
    for (long i=1; i<=n+1; i++)
    {
        ta[i]=ta[i-1]+a[i];
        tb[i]=tb[i-1]+b[i];
    }
    ans=tinh(1);

    //cout << vt << endl;
    //cout << t1 << " " << t2 << endl;
    t1pp=t1; t2pp=t2;
    for (long i=2; i<=n; i++)
    {
        /*t1p=t1; t2p=t2;
        t1pp=t1; t2pp=t2;
        t1=t1-b[i-1]*suma(i,vt)+a[vt+1]*sumb(i,vt);
        t2=t2-a[vt+1]*sumb(vt+1,i-2)+b[i-1]*suma(vt+2,i-1);
        //cout <<i << "->" << vt+1<< ": " << t1 << " " << t2 << endl;

        t1p=t1p-b[i-1]*suma(i,vt)+a[vt+1]*sumb(i,vt)+a[vt+2]*sumb(i,vt+1);
        t2p=t2p-a[vt+1]*sumb(vt+1,i-2)-a[vt+2]*sumb(vt+2,i-2)+b[i-1]*suma(vt+3,i-1);*/

        t1pp=t1pp-b[i-1]*suma(i,vt);
        t2pp=t2pp+b[i-1]*suma(vt+1,i-1);

        /*while (t1pp+a[vt+1]*sumb(i,vt)+t2pp-a[vt+1]*sumb(vt+1,i-2)-b[i-1]*a[vt+1]<t1+t2 && t1pp+a[vt+1]*sumb(i,vt)+t2pp-a[vt+1]*sumb(vt+1,i-2)-b[i-1]*a[vt+1]>0)
        {
            t1pp=t1pp+a[vt+1]*sumb(i,vt);
            t2pp=t2pp-a[vt+1]*sumb(vt+1,i-2)-b[i-1]*a[vt+1];
            vt=(vt+1)%n;
            if (vt==0) vt=n;
            if (vt==i-1) break;
        }*/
        cout << t1pp << " " <<t2pp << " " << t1pp+t2pp << endl;
        ans=min(ans,t1pp+t2pp);
    }
    cout << ans;
}

/*#include <bits/stdc++.h>
#define nmax 30007
#define oo 99999999999999999
using namespace std;

long long a[2*nmax],b[2*nmax],n,ans=oo,aa[nmax],bb[nmax],dem,sum,anss,sa;

long long cp(long long x)
{
   long long res=0;
   sum=0;
   for (long i=1; i<=x; i++)
      sum+=aa[i];
   for (long i=1; i<=x-1; i++)
   {
      sum-=aa[i];
      res+=bb[i]*sum;
   }
   sum=0;
   for (long i=x+1; i<=n; i++)
      sum+=aa[i];
   for (long i=n; i>=x+1; i--)
   {
      res+=bb[i]*sum;
      sum-=aa[i];
   }
   return res;
}

long long tinh(long k)
{
   dem=0;
   for (long i=k; i<=n+k-1; i++) aa[++dem]=a[i];
   dem=0;
   for (long i=k; i<=n+k-1; i++) bb[++dem]=b[i];
   anss=oo;
   for (long i=1; i<=n; i++) //anss=min(anss,cp(i));
     if (anss>cp(i))
     {
         anss=cp(i);
         sa=i;
     }
   return anss;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRO.inp","r",stdin);
    freopen("BRO.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i] >> b[i];
    for (long i=n+1; i<=2*n; i++)
    {
        a[i]=a[i-n];
        b[i]=b[i-n];
    }
    long dau,cuoi;
    for (long i=1; i<=n; i++)
    {
        //ans=min(ans,tinh(i));
        if (ans>tinh(i))
        {
            ans=tinh(i);
            dau=i;
            cuoi=i+sa-1;
        }
    }
    cout << dau << " " << cuoi << endl;
    cout << ans <<endl;
    tinh(1);cout << sa;
}*/

