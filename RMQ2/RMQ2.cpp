#include <bits/stdc++.h>
#define vc 10000000000

using namespace std;

long long m,n,q;
long long a[5007][5007],d[507][20007];

void build(long long chiso,long long node,long long L,long long R)
{
    if (L==R)
    {
        d[chiso][node]=a[chiso][L];
        return;
    };
    long long mid=(L+R) /2;
    build(chiso,node*2,L,mid);
    build(chiso,node*2+1,mid+1,R);
    d[chiso][node]=min(d[chiso][node*2],d[chiso][node*2+1]);

}


long long get(long long chiso,long long id,long long L,long long R,long long u,long long v)
{
    if ((L>=u) && (R<=v)) return d[chiso][id];
    if ((L>v) || (R<u)) return vc;
    long long mid=(L+R) /2 ;
    long long x1=get(chiso,id*2,L,mid,u,v);
    long long x2=get(chiso,id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RMQ2.inp","r",stdin);
    freopen("RMQ2.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++)
        for (long j=1; j<=n; j++)
          cin >> a[i][j];

    for (long i=1; i<=n; i++)
       build(i,1,1,n);

    cin >> q;
    for (long i=1; i<=q; i++)
    {
        long long x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long ans=get(x1,1,1,n,y1,y2);
        for (long j=x1; j<=x2; j++)
           ans=min(ans,get(j,1,1,n,y1,y2));
        cout << ans << endl;
    }
}
