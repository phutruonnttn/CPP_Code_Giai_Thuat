#include <bits/stdc++.h>
#define nmax 100007
#define vc 9999999999

using namespace std;

long n;
long long x[nmax],y[nmax],xt[nmax],yt[nmax],res=vc;

long long dis(long long i, long long j)
{
   return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void sortx(long long k, long long l)
{
   long long r=x[(k+l)/2];
   long long i=k,j=l;
   while (i<=j)
   {
      while (x[i]<r) i++;
      while (x[j]>r) j--;
      if (i<=j)
       {
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            i++; j--;
       }
   }
   if (k<j) sortx(k,j);
   if (i<l) sortx(i,l);
}

void merge_(long long k, long long l)
{
   for (long long i=k; i<=l; i++)
     {
         xt[i]=x[i];
         yt[i]=y[i];
     }
   long long j=(k+l)/2+1, i=k, u=k-1;
   while (u!=l)
   {
      u++;
      if (i>(k+l)/2)
       {
            x[u]=xt[j];
            y[u]=yt[j];
            j++;
       }
       else if (j>l)
        {
            x[u]=xt[i];
            y[u]=yt[i];
            i++;
        }
       else
        {
            if (yt[i]<=yt[j])
              {
                  x[u]=xt[i];
                  y[u]=yt[i];
                  i++;
              }
            else
              {
                  x[u]=xt[j];
                  y[u]=yt[j];
                  j++;
              }
        }
   }
}

void check(long long u, long long v)
{
   if (u!=v)
    {
         long long r=dis(u,v);
         if (r<res) res=r;
    }
}

void sorty(long long k, long long l)
{
   if (k==l) return;
   long long mid=(k+l)/2;
   long long r=x[mid];
   sorty(k,mid);
   sorty(mid+1,l);
   merge_(k,l);
   long long i1,i2,i3,i4;
   i1=k; i2=k; i3=k; i4=k;
   for (long long i=k+1; i<=l; i++)
      if (abs(x[i]-r)<res)
        {
            check(i,i1); check(i,i2);
            check(i,i3); check(i,i4);
            i1=i2; i2=i3; i3=i4;
            i4=i;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Poison.inp","r",stdin);
    freopen("Poison.out","w",stdout);
    cin >> n;
    for (long long i=1; i<=n; i++)
    {
        long long u; cin >> u;
        x[i]=u+i; y[i]=i;
    }
    sortx(1,n);
    sorty(1,n);
    cout << res;
}
