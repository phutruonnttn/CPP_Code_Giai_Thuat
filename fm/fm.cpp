#include <bits/stdc++.h>
#define maxn 1000007

using namespace std;

long n,m,a[maxn],p[2000007];

void sub1()
{
    for (long i=1; i<=n; i++)
    {
        for (long j=i; j<=n; j++)
           if (a[i]==a[j]) p[a[i]+a[j]]++;
           else p[a[i]+a[j]]+=2;
    }
    long long ans=0;
    for (long i=1; i<=m; i++) ans+=p[i];
    //cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("fm.inp","r",stdin);
    freopen("fm.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    if (n<=10000) sub1();
}
