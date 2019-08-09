#include <bits/stdc++.h>

using namespace std;

long long n,t,k,a[100007],d[400007];

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=a[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=min(d[node*2],d[node*2+1]);

}

long long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MINK.inp","r",stdin);
    freopen("MINK.out","w",stdout);
    cin>> t;
    for (long l=1; l<=t; l++)
    {
        cin >> n >> k;
        for (long i=1; i<=n; i++) cin >> a[i];
        build(1,1,n);
        for (long i=1;i<=n-k+1; i++)
            cout << get(1,1,n,i,i+k-1)<< " ";
        cout << endl;
    }
}
