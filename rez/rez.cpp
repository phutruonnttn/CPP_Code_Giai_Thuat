#include <bits/stdc++.h>
#define nmax 200007

using namespace std;
typedef pair <long,long> ii;

long long n,f[nmax],ans=-1,t[nmax];
ii a[nmax];

bool comp(data a, data b)
{
    return a.bd < b.bd;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("REZ.inp","r",stdin);
    freopen("REZ.out","w",stdout);
    cin >> n ;
    for (long i=1; i<=n; i++)
      {cin >> a[i].bd >> a[i].kt; a[i].tg=a[i].kt-a[i].bd;}

    for (long i=1; i<=n; i++)
    {
        long j=upper_bound(a+1,a+i,make_pair(a[i]))
    }
}
