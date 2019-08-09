#include <bits/stdc++.h>
#define nmax 107
#define smax 1000007

using namespace std;

long long m,n,sum,a[nmax],b[nmax],d[smax],tr[smax];

void truy(long i)
{
    if (i!=0)
    {
        truy(i-a[tr[i]]);
        a[tr[i]]=-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i];
        b[i]=a[i];
        sum+=a[i];
    }
    d[0]=1;
    for (long i=1; i<=n; i++)
    {
        for (long j=sum/2-a[i]; j>=0; j--)
          if (d[j]==1 && d[j+a[i]]==0)
          {
              d[j+a[i]]=1;
              tr[j+a[i]]=i;
          }
    }
    m=sum/2;
    while (d[m]==0) m--;
    cout << sum-2*m << '\n';
    truy(m);
    for (long i=1; i<=n; i++)
       if (a[i]>=0) cout << a[i] << " ";
    cout << '\n';
    for (long i=1; i<=n; i++)
       if (a[i]<0) cout << b[i] << " ";
}
