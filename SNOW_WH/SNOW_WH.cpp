#include <bits/stdc++.h>
#define nmax 300007

using namespace std;

long long n,m,vt[nmax],a[nmax],d1[4*nmax],d2[4*nmax];

void build1(long node,long L,long R)
{
    if (L==R)
    {
        d1[node]=a[L];
        return;
    };
    long mid=(L+R)/2;
    build1(node*2,L,mid);
    build1(node*2+1,mid+1,R);
    d1[node]=min(d1[node*2],d1[node*2+1]);
}

void build2(long node,long L,long R)
{
    if (L==R)
    {
        d2[node]=a[L];
        return;
    };
    long mid=(L+R)/2;
    build2(node*2,L,mid);
    build2(node*2+1,mid+1,R);
    d2[node]=max(d2[node*2],d2[node*2+1]);
}

long get1(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d1[id];
    if ((L>v) || (R<u)) return 10000000000;
    long mid=(L+R)/2 ;
    long x1=get1(id*2,L,mid,u,v);
    long x2=get1(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

long get2(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d2[id];
    if ((L>v) || (R<u)) return -10000000000;
    long mid=(L+R)/2 ;
    long x1=get2(id*2,L,mid,u,v);
    long x2=get2(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void update1(long id,long L,long R,long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d1[id]=a[x];
        return;
    };
    long mid=(L+R)/2;
    update1(id*2,L,mid,x);
    update1(id*2+1,mid +1,R,x);
    d1[id]=min(d1[id*2],d1[id*2+1]);
}

void update2(long id, long L,long R,long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d2[id]=a[x];
        return;
    };
    long mid=(L+R)/2;
    update2(id*2,L,mid,x);
    update2(id*2+1,mid +1,R,x);
    d2[id]=max(d2[id*2],d2[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("SNOW_WH.inp","r",stdin);
    freopen("SNOW_WH.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) {cin >> vt[i]; a[vt[i]]=i;}
    //a[i] la vi tri phan tu co do cao la i
    build1(1,1,n);
    build2(1,1,n);
    for (long i=1; i<=m; i++)
    {
        long z,x,y;
        cin >> z >> x >> y;
        if (z==1)
        {
            long u=a[vt[x]];
            a[vt[x]]=a[vt[y]];
            update1(1,1,n,vt[x]);
            update2(1,1,n,vt[x]);
            a[vt[y]]=u;
            update1(1,1,n,vt[y]);
            update2(1,1,n,vt[y]);
            u=vt[x];
            vt[x]=vt[y];
            vt[y]=u;
            //for (long i=1; i<=n; i++) cout << a[i] << " ";
        }
        else
        {
          if (y-x==get2(1,1,n,x,y)-get1(1,1,n,x,y)) cout << "YES" << '\n';
          else cout << "NO" << '\n';
        }
    }
}
