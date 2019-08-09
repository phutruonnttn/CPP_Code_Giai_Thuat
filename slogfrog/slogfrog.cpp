#include <bits/stdc++.h>

using namespace std;

long m,n,k,a[100007],ans,maxx=-1;

bool comp(long a, long b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("slogfrog.inp","r",stdin);
    freopen("slogfrog.out","w",stdout);
    cin >> m >> n >> k;
    memset(a,0,sizeof(0));
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
       {
         long w;
         cin >> w;
         maxx=max(maxx,w);
         a[w]++;
       }
     sort(a+1,a+maxx+10,comp);
     for (long i=1; i<=k; i++) ans+=a[i];
     cout << ans;
}
