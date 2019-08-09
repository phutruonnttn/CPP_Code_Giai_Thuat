#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long a,b,l;
};

long long n,ans=0,vtc=0,t,f[nmax],kt[nmax],d1[4*nmax],aa[nmax],bb[nmax],d2[4*nmax];
data tg[nmax];

bool cmp(data q, data p)
{
    if (q.b!=p.b) return q.b < p.b;
    return q.l < p.l;
}

long long get1(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d1[id];
    if ((L>v) || (R<u)) return -100000000007;
    long mid=(L+R) /2 ;
    long long x1=get1(id*2,L,mid,u,v);
    long long x2=get1(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void update1(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d1[id]=aa[x];
        return;
    };
    long mid=(L+R) /2;
    update1(id*2,L,mid,x);
    update1(id*2+1,mid +1,R,x);
    d1[id]=max(d1[id*2],d1[id*2+1]);
}

long long get2(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d2[id];
    if ((L>v) || (R<u)) return -100000000007;
    long mid=(L+R) /2 ;
    long long x1=get2(id*2,L,mid,u,v);
    long long x2=get2(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void update2(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d2[id]=bb[x];
        return;
    };
    long mid=(L+R) /2;
    update2(id*2,L,mid,x);
    update2(id*2+1,mid +1,R,x);
    d2[id]=max(d2[id*2],d2[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("WORKING.inp","r",stdin);
    freopen("WORKING.out","w",stdout);
    cin >> n;
    tg[n+1].a=0; tg[n+1].b=0; tg[n+1].l=0;
    for (long i=1; i<=n; i++) {cin >> tg[i].a >> tg[i].b; tg[i].l=tg[i].b-tg[i].a;}
    n++;
    sort(tg+1,tg+n+1,cmp);

    /*for (long i=1; i<=n; i++)
       for (long j=i-1; j>=1; j--)
       {
         if (tg[j].b>tg[i].a) t=f[j]+tg[i].l-2*(tg[j].b-tg[i].a);
         else t=f[j]+tg[i].l;
         f[i]=max(f[i],t);
       }
    for (long i=1; i<=n; i++) ans=max(ans,f[i]);
    cout << ans;*/

    for (long i=1; i<=n; i++) kt[i]=tg[i].b;

    for (long i=1; i<=n; i++)
       {
         long k=upper_bound(kt+1,kt+n+1,tg[i].a)-kt-1;
         f[i]=max(f[i],get1(1,1,n,1,k)+tg[i].l);
         f[i]=max(f[i],tg[i].a+tg[i].b+get2(1,1,n,k+1,i-1));
         aa[i]=f[i];
         update1(1,1,n,i);
         bb[i]=f[i]-2*tg[i].b;
         update2(1,1,n,i);
       }
    for (long i=1; i<=n; i++) ans=max(ans,f[i]);
    cout << ans;
}
