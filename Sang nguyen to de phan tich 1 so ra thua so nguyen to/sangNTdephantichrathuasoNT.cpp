#include <bits/stdc++.h>

using namespace std;

long long n,q,ans,dd[1000007],a[10000007];
long nt[1000007];

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
    freopen("b.inp","r",stdin);
    freopen("b.out","w",stdout);
    cin >> q;
    sangnt(1000000);
    memset(dd,true,sizeof(dd));
    for (long i=1; i<=q; i++)
    {
        cin >> n;
        ans=1; long d=0;
        while (n>1)
        {
            long p=nt[n];
            if (dd[p])
            {
                dd[p]=false;
                a[++d]=p;
            }
            //ans*=nt[n];
            n=n/p;
        }
        //cout << d << endl;
        for (long j=1; j<=d; j++)
        {
            dd[a[j]]=true;
            ans*=a[j];
        }
        cout << ans << '\n';
    }
}
