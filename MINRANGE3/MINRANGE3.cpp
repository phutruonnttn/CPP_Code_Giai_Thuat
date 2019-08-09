#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100000],d[400007],t[400007],w;

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

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2)+t[id];
}

void update(long id, long L, long R, long u, long v,long w)
{
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        t[id]+=w;
        d[id]+=w;
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,u,v,w);
    update(id*2+1,mid +1,R,u,v,w);
    d[id]=min(d[id*2],d[id*2+1]) +t[id];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MINRANGE3.inp","r",stdin);
    freopen("MINRANGE3.out","w",stdout);
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
              cin >> w;
              update(1,1,n,x2,x3,w);
          }
          else
          {
            cout << get(1,1,n,x2,x3) <<endl;
          }
      }
}
