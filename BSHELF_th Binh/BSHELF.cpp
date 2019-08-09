#include <bits/stdc++.h>
#define nmax 100007
#define vc 999999999999

using namespace std;

struct data1
{
    long long gt,id;
};

long long n,l,h[nmax],w[nmax],f[nmax],dh[4*nmax],truoc[nmax],s[nmax];
data1 df[4*nmax],tv,aa[nmax];

void build(long node,long L,long R)
{
    if (L==R)
    {
        dh[node]=h[L];
        return;
    };
    long mid=(L+R)/2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    dh[node]=max(dh[node*2],dh[node*2+1]);
}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dh[id];
    if ((L>v) || (R<u)) return -1;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

bool kt(long long r1, long l1)
{
    if (s[r1]-s[l1-1]<=l) return true;
    return false;
}

void buildf(long node,long L,long R)
{
    if (L==R)
    {
        df[node].gt=aa[L].gt;
        df[node].id=aa[L].id;
        return;
    };
    long mid=(L+R) /2;
    buildf(node*2,L,mid);
    buildf(node*2+1,mid+1,R);
    if (df[node*2].gt<=df[node*2+1].gt) df[node]=df[node*2];
    else df[node]=df[node*2+1];
}

data1 getf(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return df[id];
    if ((L>v) || (R<u)) return tv;
    long mid=(L+R)/2 ;
    data1 x1=getf(id*2,L,mid,u,v);
    data1 x2=getf(id*2+1,mid+1,R,u,v);
    if (x1.gt<=x2.gt) return x1;
    else return x2;
}

void updatef(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        df[id].gt=aa[x].gt;
        df[id].id=aa[x].id;
        return;
    };
    long mid=(L+R) /2;
    updatef(id*2,L,mid,x);
    updatef(id*2+1,mid +1,R,x);
    if (df[id*2].gt<=df[id*2+1].gt) df[id]=df[id*2];
    else df[id]=df[id*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BSHELF.inp","r",stdin);
    freopen("BSHELF.out","w",stdout);
    cin >> n >> l;
    for (long i=1; i<=n; i++) {cin >> h[i] >> w[i]; f[i]=vc; s[i]=s[i-1]+w[i];}
    build(1,1,n);
    f[0]=h[0];
    tv.gt=vc; tv.id=vc;
    for (long i=1; i<=n; i++)
    {
        aa[i].gt=vc;
        aa[i].id=i;
    }
    buildf(1,1,n);
    truoc[1]=1;
    for (long i=2; i<=n; i++)
    {
        long long l=1, r=i, res;
        while (l<=r)
        {
            long long mid=(l+r)/2;
            if (kt(i,mid))
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        truoc[i]=res;
    }

    f[1]=h[1];
    aa[1].gt=h[1];
    updatef(1,1,n,1);
    for (long i=2; i<=n; i++)
    {
       data1 cc=getf(1,1,n,truoc[i],i);
       f[i]=f[cc.id-1]+get(1,1,n,cc.id,i);
       f[i]=min(f[i],f[i-1]+h[i]);
       aa[i].gt=f[i];
       updatef(1,1,n,i);
       //cout <<get(1,1,n,cc.id,i-1)<< " " << h[i] <<" "<< cc.gt << " " << cc.id<< " "<< f[i] << endl;
    }
    cout << f[n];
}
