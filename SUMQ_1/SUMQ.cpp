#include <bits/stdc++.h>

using namespace std;

long n,m,a[15007],d[4*15007];

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
    d[node]=d[node*2]+d[node*2+1];

}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 0;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return x1+x2;
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
    d[id]=d[id*2]+d[id*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SUMQ.inp","r",stdin);
    freopen("SUMQ.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    build(1,1,n);
    for (long i=1; i<=m; i++)
      {
          long long x1,x2,x3;
          cin >> x1 >> x2 >> x3;
          if (x1==1)
          {
              cout << get(1,1,n,x2,x3) << endl;
          }
          else
          {
             a[x2]=a[x2]-x3;
             update(1,1,n,x2);
          }
      }
}
