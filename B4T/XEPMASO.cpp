#include <bits/stdc++.h>

using namespace std;

struct data
{
    long long dt,ms;
};

long long n;
data a[100007];

bool comp(data a, data b)
{
    if (a.dt!=b.dt) return a.dt > b.dt;
    return a.ms < b.ms;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("XEPMASO.inp","r",stdin);
    freopen("XEPMASO.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
       cin >> a[i].ms >> a[i].dt;
    sort(a+1,a+n+1,comp);
    for (long i=1; i<=n; i++)
        cout << a[i].ms << " " << a[i].dt << endl;
}
