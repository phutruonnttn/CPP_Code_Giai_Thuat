#include <bits/stdc++.h>

using namespace std;

long m,n,a[100007],b[100007];

bool comp(long a, long b)
{
    return a>b;
}

int main()
{
    freopen("DANCE.inp","r",stdin);
    freopen("DANCE.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
         cin >> a[i];
    for (long j=1; j<=n; j++)
         cin >> b[j];
    sort(a+1,a+m+1,comp);
    sort(b+1,b+n+1,comp);

    long ans=0;
    long j=1,i=1;
    while (i!=m)
    {
        if (j>n) break;
        if (a[i]<=b[j]) j++;
        else
        {
            ans++;
            i++; j++;
        }
    }

    cout << ans;
}
