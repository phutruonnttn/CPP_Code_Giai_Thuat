#include <bits/stdc++.h>
#define nmax 200007
#define vc 9999999999

using namespace std;

struct data
{
    long long x,l,h;
};

long long n,d[4*nmax],t[4*nmax],dn[20*nmax],tn[20*nmax];
data sk[nmax];

bool cmp(data q, data p)
{
    if (q.x!=p.x) return q.x < p.x;
    return q.l < p.l;
}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return vc;
    long mid=(L+R)/2 ;
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

long getn(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dn[id];
    if ((L>v) || (R<u)) return vc;
    long mid=(L+R)/2 ;
    long long x1=getn(id*2,L,mid,u,v);
    long long x2=getn(id*2+1,mid+1,R,u,v);
    return min(x1,x2)+tn[id];
}

void updaten(long id, long L, long R, long u, long v,long w)
{
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        tn[id]+=w;
        dn[id]+=w;
        return;
    };
    long mid=(L+R) /2;
    updaten(id*2,L,mid,u,v,w);
    updaten(id*2+1,mid +1,R,u,v,w);
    dn[id]=min(dn[id*2],dn[id*2+1]) +tn[id];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FENCE.inp","r",stdin);
    freopen("FENCE.out","w",stdout);
    cin >> n;
    long long dem=0,hmax=-1;
    for (long i=1; i<=n; ++i)
    {
        long long xx,ww,hh;
        cin >> xx >> ww >> hh;
        hmax=max(hmax,hh);
        ++dem;
        sk[dem].x=xx; sk[dem].l=2; sk[dem].h=hh;
        ++dem;
        sk[dem].x=xx+ww; sk[dem].l=1; sk[dem].h=hh;
    }
    sort(sk+1,sk+dem+1,cmp);

    long long db=0;
    for (long i=1; i<=dem; i++)
    {
        if (sk[i].l==2) update(1,1,hmax,1,sk[i].h,1);
        else
        {
            if (get(1,1,hmax,1,sk[i].h)==1) db++;
            else update(1,1,hmax,1,sk[i].h,-1);
        }
    }
    cout << db;
}
