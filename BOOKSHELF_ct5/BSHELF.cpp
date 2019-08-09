#include <bits/stdc++.h>
#define nmax 200007
#define vc 999999999999

using namespace std;

long long n,l,h[nmax],w[nmax],f[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BSHELF.inp","r",stdin);
    freopen("BSHELF.out","w",stdout);
    cin >> n >> l;
    for (long i=1; i<=n; i++) {cin >> h[i] >> w[i]; f[i]=vc;}
    f[0]=h[0];
    for (long i=1; i<=n; i++)
    {
       long long rong=0,cur=h[i];
       for (long j=i; j>=1; j--)
          if (rong+w[j]<=l)
          {
             rong+=w[j];
             cur=max(cur,h[j]);
             f[i]=min(f[i],f[j-1]+cur);
          }
          else break;
    }
    cout << f[n];
}
