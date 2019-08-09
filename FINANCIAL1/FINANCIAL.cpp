#include <bits/stdc++.h>

using namespace std;

long n,k,a[100007],d[400007],f[100007];

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=a[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=min(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FINANCIAL.inp","r",stdin);
    freopen("FINANCIAL.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
        cin >> a[i];

}
