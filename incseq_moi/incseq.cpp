#include <bits/stdc++.h>
#define mn 1000007
#define maxn 1000007
using namespace std;

struct BITTree
{
    long long tree[mn];

    void update(long long x, long long v)
    {
        while(x <= mn)
        {
            tree[x] += v;
            x += (x & (-x));
        }
    }

    long long get(long long x)
    {
        long long ret = 0;
        while(x)
        {
            ret += tree[x];
            x -= (x & (-x));
        }
        return ret;
    }
} T[57];

long long n,k,a[mn],f[mn][57],nen[maxn],val[maxn],pos[maxn];

void sx(long long l, long long r)
{
    long long i=l, j=r, chot=val[(l+r)/2];
    do
    {
         while (val[i]<chot) i++;
         while (val[j]>chot) j--;
         if (i<=j)
          {
              swap(val[i],val[j]);
              swap(pos[i],pos[j]);
              i++; j--;
          }
    }
    while (i<=j);
    if (l<j) sx(l,j);
    if (i<r) sx(i,r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("INCSEQ.inp","r",stdin);
    freopen("INCSEQ.out","w",stdout);
    cin >> n >> k;
    for (long long i=1; i<=n; i++)
        {
           cin >> a[i];
           val[i]=a[i];
           pos[i]=i;
        }

    sx(1,n);
    long long dem=0,last=val[n];

    for (long long i=1; i<=n; i++)
      {
            if (last!=val[i])
              {
                dem++;
                last=val[i];
              }
            nen[pos[i]]=dem;
      }

    for (long long i=1; i<=n; i++)
    {
        f[i][1]=1;
        for (long long j=2; j<=k; j++)
           f[i][j] = T[j-1].get(nen[i]-1);
        for (long long j=1; j<=k; j++)
           T[j].update(nen[i],f[i][j]);
    }
    long long ans=0;
    for (long long i=1; i<=n; i++)
       ans+=f[i][k];
    cout << ans%5000000;
}
