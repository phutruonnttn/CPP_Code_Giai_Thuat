#include <bits/stdc++.h>

using namespace std;

long long a,b,n;
long long kh[100007],skh[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LOTTERY.inp","r",stdin);
    freopen("LOTTERY.out","w",stdout);
    cin >> n >> a >> b;
    for (long i=1; i<=n; i++)
        {
          cin >> kh[i];
          skh[i]=kh[i];
        }
    sort(kh+1,kh+n+1);
    long long minn=kh[1],dem=1,mindem=10000000000;
    kh[n+1]=kh[n]+1;
    for (long i=1; i<=n; i++)
    {
        if (kh[i]==kh[i+1]) dem++;
        else
        {
            if (mindem>dem)
            {
                mindem=dem;
                minn=kh[i];
            };
            dem=1;
        }
    }
    cout << n*a-mindem*b << " " << mindem << endl;
    for (long i=1; i<=n; i++)
        if (skh[i]==minn) cout << i << " " ;
}
