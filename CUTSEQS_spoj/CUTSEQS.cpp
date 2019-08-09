#include <bits/stdc++.h>
#define nmax 100007
#define vc 9999999999

using namespace std;
const long long M=1e18, MI=1e5;

long long n,m,a[nmax],f[nmax];

void sinh()
{
    freopen("CUTSEQS.inp","w",stdout);
    srand(time(NULL));
    cout << 100000 << " " << MI+rand()%M << endl;
    for (long i=1; i<=100000; i++)
      cout << rand()%1000000 << " ";
}

int main()
{
    sinh();
    ios_base::sync_with_stdio(0);
    freopen("CUTSEQS.inp","r",stdin);
    freopen("CUTSEQS.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i];
        if (a[i]>m)
        {
            cout << -1;
            return 0;
        }
    }
    f[1]=a[1];
    for (long i=2; i<=n; i++)
    {
        f[i]=vc;
        long long sum=a[i],sm=a[i];
        for (long j=i-1; j>=0; j--)
           if (sum<=m)
           {
               f[i]=min(f[i],f[j]+sm);
               sm=max(sm,a[j]);
               sum+=a[j];
           }
           else break;
    }
    cout << f[n];
}
