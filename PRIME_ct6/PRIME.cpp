#include <bits/stdc++.h>
#define nmax 1000007
#define xmax 100007

using namespace std;

long long n,m,f[xmax],dd[xmax],a[nmax],tong[xmax];
long nt[xmax];

void sangnt(long n)
{
  for (long i=2; i<=n; i++) nt[i]=i;
  for (long i=2; i<=int(sqrt(n));i++)
    if (nt[i]==i)
    {
        long j=i*i;
        while (j<=n)
        {
           nt[j]=i;
           j=j+i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PRIME.inp","r",stdin);
    freopen("PRIME.out","w",stdout);
    cin >> n;
    sangnt(100000);
    memset(dd,true,sizeof(dd));
    for (long i=1; i<=n; i++)
    {
        long x;
        cin >> x;
        long d=0;
        while (x>1)
        {
            long p=nt[x];
            if (dd[p])
            {
                dd[p]=false;
                a[++d]=p;
            }
            x=x/p;
        }
        for (long j=1; j<=d; j++)
        {
            f[a[j]]++;
            dd[a[j]]=true;
        }
    }
    for (long i=1; i<=100000; i++) tong[i]=tong[i-1]+f[i];
    cin >> m;
    for (long i=1; i<=m; i++)
    {
        long long l,r,ll=100000;
        cin >> l >> r;
        cout << tong[min(ll,r)]-tong[l-1] << '\n';
    }
}
