#include <bits/stdc++.h>
#define nmax 1007
#define oo 999999999

using namespace std;

long long m,n,k,a[nmax][nmax],x,y,u,v,s[nmax][nmax],ans;

long long sum(long x, long y, long u, long v)
{
     return s[u][v]+s[x-1][y-1]-s[x-1][v]-s[u][y-1];
}

long long tinh(long x, long y, long u, long v)
{
    long long tmp=sum(x,y,u,v), chot=tmp/2;
    ans=oo;
    //chat theo hang
    long l=x, r=u-1;
    while (l<=r)
    {
        long mid=(l+r)/2;
        if (sum(x,y,mid,v)>=chot) r=mid-1;
        else l=mid+1;
    }
    ans=min(ans,min(abs(tmp-2*sum(x,y,l,v)),abs(tmp-2*sum(x,y,r,v))));
    //chat theo cot
    l=y, r=v-1;
    while (l<=r)
    {
        long mid=(l+r)/2;
        if (sum(x,y,u,mid)>=chot) r=mid-1;
        else l=mid+1;
    }
    ans=min(ans,min(abs(tmp-2*sum(x,y,u,l)),abs(tmp-2*sum(x,y,u,r))));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MINCUT.inp","r",stdin);
    freopen("MINCUT.out","w",stdout);
    cin >> m >> n >> k;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
          cin >> a[i][j];

    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
         s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];

    for (long i=1; i<=k; i++)
    {
        cin >> x >> y >> u >> v;
        cout << tinh(x,y,u,v) << '\n';
    }
}
