#include <bits/stdc++.h>

using namespace std;

long t,n,m,a[40][40];
long long f[40][40];

bool ktra(long x, long y)
{
    for (long i=0; i<=n-1; i++) a[1][i]=((x>>i) & 1);
    for (long i=0; i<=n-1; i++) a[2][i]=((y>>i) & 1);
    for (long i=0; i<=n-2; i++)
    {
        long sum=a[1][i]+a[1][i+1]+a[2][i]+a[2][i+1];
        if (sum==0 || sum==4) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("COWGIRL.inp","r",stdin);
    freopen("COWGIRL.out","w",stdout);
    cin >> t;
    while (t!=0)
    {
        cin >> m >> n;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        if (m<n) swap(m,n);
        for (long i=0; i<=(1<<n)-1; i++) f[1][i]=1;
        for (long i=2; i<=m; i++)
           for (long j=0; j<=(1<<n)-1;j++)
             for (long k=0; k<=(1<<n)-1; k++)
               if (ktra(j,k)) f[i][j]+=f[i-1][k];
        long long ans=0;
        for (long i=0; i<=(1<<n)-1; i++) ans+=f[m][i];
        cout << ans << endl;
        t--;
    }
}
