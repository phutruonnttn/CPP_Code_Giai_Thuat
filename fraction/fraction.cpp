#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    double gt;
    long id;
};

long n,w,b[2*nmax],x[2*nmax];
data a[2*nmax];

bool comp(data q, data p)
{
    if (q.gt!=p.gt) return q.gt < p.gt;
    return q.id > p.id;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("fraction.inp","r",stdin);
    freopen("fraction.out","w",stdout);
    cin >> n >> w;
    long nn=n;
    if (w==0)
    {
        for (long i=1; i<=n; i++)
        {
            long u,v;
            cin >> u >> v;
            a[i].gt=(double) u/v;
            a[i].id=i;
        }
    }
    else
    {
        for (long i=1; i<=n; i++)
        {
            long u,v;
            cin >> u >> v;
            a[i].gt=(double) u/v;
            a[i].id=i;
            a[i+n].gt=(double) v/u;
            a[i+n].id=i;
        }
        nn+=n;
    }
    sort(a+1,a+nn+1,comp);
    //for (long i=1; i<=nn; i++) cout << a[i].gt << " " << a[i].id << endl;

    for (long i=1; i<=nn; i++) b[i]=a[i].id;

    long long res=0;
    for (long i=1; i<=nn; i++)
    {
        if (b[i]>b[x[res]])
        {
            ++res;
            x[res]=i;
        }
        else
        {
            long l=0, r=res;
            while (r-l>1)
            {
                long g=(l+r)/2;
                if (b[x[g]]<b[i]) l=g;
                else r=g;
            }
            x[r]=i;
        }
    }
    cout << res;
}
