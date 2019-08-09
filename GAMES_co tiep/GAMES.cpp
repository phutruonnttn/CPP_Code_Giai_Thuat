#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,m,a[nmax],d[4*nmax],w,t[4*nmax];

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
    d[node]=max(d[node*2],d[node*2+1]);
}

void push(long i)
{
    d[i]=t[i*2]=t[i*2+1]=d[i*2]=d[i*2+1]=t[i];
    t[i]=-1;
}

long get(long id,long L,long R,long u,long v)
{
    //if ((L>v) || (R<u)) return -1;
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return -1;
    if (t[id]!=-1) push(id);
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void update(long id, long L, long R, long u, long v)
{
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        t[id]=w;
        d[id]=w;
        return;
    };
    if (t[id]!=-1) push(id);
    long mid=(L+R) /2;
    update(id*2,L,mid,u,v);
    update(id*2+1,mid +1,R,u,v);
    d[id]=max(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GAMES.inp","r",stdin);
    freopen("GAMES.out","w",stdout);
    cin >> n >> m;
    memset(t,-1,sizeof(t));
    for (long i=1; i<=n; i++) cin >> a[i];
    build(1,1,n);
    for (long i=1; i<=m; i++)
    {
         long p,l;
         cin >> p >> l;
         long long ans=get(1,1,n,p,p+l-1)+1;
         cout << ans << '\n';
         w=ans;
         update(1,1,n,p,p+l-1);
    }
}
