#include <bits/stdc++.h>
#define nmax 10007
using namespace std;

long n,a[nmax][nmax],maxl=-1;

bool ktra(long long m)
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MOVE12.inp","r",stdin);
    freopen("MOVE12.out","w",stdout);
    cin >> n;
    memset(a,-1,sizeof(a));
    for (long i=1; i<=n; i++)
    {
        long c,t,dem=0; cin >> c >> t;
        a[i][c]=0;
        for (long j=c-1; j>=1; j--)
         {
           a[i][j]=t*(++dem);
           maxl=max(maxl,a[i][j]);
         }
        dem=0;
        for (long j=c+1; j<=n; j++)
         {
           a[i][j]=t*(++dem);
           maxl=max(maxl,a[i][j]);
         }
    }
    /*for (long i=1; i<=n; i++)
    {
        for (long j=1; j<=n; j++)
           cout << a[i][j] << " ";
        cout << endl;
    }
    cout << maxl;*/
    long long l=0,r=maxl,ans;
    while (l<r)
    {
        long long mid=(l+r)/2;
        if (ktra(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
}
