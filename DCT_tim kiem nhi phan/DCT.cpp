#include <bits/stdc++.h>
#define nmax 40007

using namespace std;

long n,a[nmax],d[nmax],x[nmax],a1[nmax],tr[nmax];
vector <long> v;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dct.inp","r",stdin);
    freopen("dct.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i]; a1[i]=a[i];}
    v.assign(a + 1, a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;

    long res=0;
    for (long i=1; i<=n; i++)
    {
        if (a[i]>a[x[res]])
        {
            d[i]=++res;
            x[res]=i;
            tr[i]=x[res-1];
        }
        else
        {
            long l=0, r=res;
            while (r-l>1)
            {
                long g=(l+r)/2;
                if (a[x[g]]<a[i]) l=g;
                else r=g;
            }
            d[i]=r; x[r]=i; tr[i]=x[l];
        }
    }
    long dem=0,b[nmax];
    cout << res << endl;
    res=x[res];
    while (tr[res]!=0)
    {
        b[++dem]=a1[res];
        res=tr[res];
    }
    b[++dem]=a1[res];
    for (long i=dem; i>=1; i--) cout << b[i] << " ";
}
