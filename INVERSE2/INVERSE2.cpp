#include <bits/stdc++.h>
#define maxn 10000007

using namespace std;

long long n,a[maxn],t[maxn];
vector <long> v;

long long get(long long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&(-x));
    }
    return res;
}

void update(long long x, long long d)
{
    while (x<=n)
    {
        t[x]+=d;
        x+=(x&(-x));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("INVERSE2.inp","r",stdin);
    freopen("INVERSE2.out","w",stdout);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> a[i];

    v.assign(a + 1, a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;

    long long res=0;

    for (long i=n; i>=1; i--)
    {
        res+=get(a[i]-1);
        update(a[i],1);
    }
    cout << res;
}
