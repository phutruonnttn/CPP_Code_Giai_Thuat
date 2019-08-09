#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,del,a[nmax];

long long tongchodoi(long long k)
{
    long long res=0;
    for (long i=1; i<=n; i++)
    {
        long long t1=a[i]/k;
        if (a[i]%k!=0)
        {

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0)
    freopen("TRIP.inp","r",stdin);
    freopen("TRIP.out","w",stdout);
    cin >> n >> del;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    cout << tongchodoi(a[1]);
}
