#include <bits/stdc++.h>

using namespace std;
const long long bi=77, m=1000000000+7,m2=m*m;

string s1,s2;
long long a[1000007],b[1000007],n1,n2,sum[1000007];
long long h[1000007],hash1[1000007],hash2[1000007];

long long get1(long l, long r)
{
    if (l>r) return 0;
    return ((hash1[r]-hash1[l-1]*h[r-l+1]+m2) % m);
}

long long mu(long k)
{
    long long res=1;
    for (long i=1; i<=k; i++) res*=10;
    return res;
}

long long get2(long l, long r)
{
    if (l>r) return 0;
    return ((hash2[r]-hash2[l-1]*h[r-l+1]+m2) % m);
}

bool kt(long u,long v)
{
    if (get1(1,u-1)!=get2(1,u-1)) return false;
    if (get1(n1-(n2-v)+1,n1)!=get2(v+1,n2)) return false;
    long long l=u, r=n1-(n2-v),k1=0,k2=0,dem=-1;
    char xx[107];
    k1=sum[r]-sum[l-1];
    for (long i=v; i>=u; i--) xx[++dem]=s2[i];
    for (long i=0; i<=dem; i++)
       k2=k2+(xx[i]-48)*mu(i);
    if (k1==k2) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PASSWORD.inp","r",stdin);
    freopen("PASSWORD.out","w",stdout);
    cin >> s1 >> s2;
    n1=s1.size(); n2=s2.size();
    s1='*'+s1; s2='*'+s2;
    for (long i=1; i<=n1; i++) a[i]=s1[i]-48;
    for (long i=1; i<=n2; i++) b[i]=s2[i]-48;

    for (long i=1; i<=n1; i++) sum[i]=sum[i-1]+a[i];

    h[0]=1; h[1]=bi;
    for (long i=2; i<=max(n1,n2)+8; i++)
        h[i]=(h[i-1]*bi) % m;

    hash1[1]=(s1[1]) % m;
    for (long i=2; i<=n1; i++)
        hash1[i]=((hash1[i-1]*bi)+s1[i]) % m;

    hash2[1]=(s2[1]) % m;
    for (long i=2;i<=n2; i++)
        hash2[i]=((hash2[i-1]*bi)+s2[i]) % m;

    for (long i=1; i<=n2; i++)
       for (long k=0; k<=15; k++)
         if (s2[i]!='0')
         {
            long long j=i+k;
            if (j>n2) continue;
            if (kt(i,j))
              {
                  cout << i << " " << n1-(n2-j) << '\n';
                  return 0;
              }
         }
}
