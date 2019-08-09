#include <bits/stdc++.h>
#define nmax 15007
#define vc 9999999999

using namespace std;

long long n,k,a[nmax],a1[nmax],a2[nmax],dmax[4*nmax],l=0,r=0,ans,f[nmax],g[nmax],s[nmax],truoc[nmax],dmin[4*nmax];

bool kt(long long r1, long l1, long long ll)
{
    if (s[r1]-s[l1-1]<=ll) return true;
    return false;
}

void build1(long node,long L,long R)
{
    if (L==R)
    {
        dmin[node]=a1[L];
        return;
    };
    long mid=(L+R) /2;
    build1(node*2,L,mid);
    build1(node*2+1,mid+1,R);
    dmin[node]=min(dmin[node*2],dmin[node*2+1]);
}

long get1(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dmin[id];
    if ((L>v) || (R<u)) return vc;
    long mid=(L+R) /2 ;
    long long x1=get1(id*2,L,mid,u,v);
    long long x2=get1(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void update1(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        dmin[id]=a1[x];
        return;
    };
    long mid=(L+R) /2;
    update1(id*2,L,mid,x);
    update1(id*2+1,mid +1,R,x);
    dmin[id]=min(dmin[id*2],dmin[id*2+1]);
}

void build2(long node,long L,long R)
{
    if (L==R)
    {
        dmax[node]=a2[L];
        return;
    };
    long mid=(L+R) /2;
    build2(node*2,L,mid);
    build2(node*2+1,mid+1,R);
    dmax[node]=max(dmax[node*2],dmax[node*2+1]);
}

long get2(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dmax[id];
    if ((L>v) || (R<u)) return -vc;
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
        dmax[id]=a2[x];
        return;
    };
    long mid=(L+R) /2;
    update2(id*2,L,mid,x);
    update2(id*2+1,mid +1,R,x);
    dmax[id]=max(dmax[id*2],dmax[id*2+1]);
}

bool kt(long long h)
{
    //for (long i=1; i<=n; i++) if (a[i]>h) return false;

    for (long i=1; i<=n; i++)
    {
        a1[i]=0; a2[i]=0;
    }
    build1(1,1,n); build2(1,1,n);
    f[1]=1;
    a1[1]=1; update1(1,1,n,1);
    g[1]=1;
    a2[1]=1; update2(1,1,n,1);
    truoc[1]=1;
    for (long i=2; i<=n; i++)
    {
        long long l=1, r=i, res;
        while (l<=r)
        {
            long long mid=(l+r)/2;
            if (kt(i,mid,h))
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        truoc[i]=res;

    }
for (long i=1; i<=n; i++) cout << truoc[i] << " "; cout << endl;
    for (long i=2; i<=n; i++)
    {
        /*f[i]=vc;
        long sum=a[i];
        for (long j=i-1; j>=1; j--)
           if (sum<=h)
           {
               f[i]=min(f[i],f[j]);
               sum+=a[j];
           }
        f[i]++;*/
        f[i]=get1(1,1,n,truoc[i]-1,i-1)+1;
        a1[i]=f[i];
        update1(1,1,n,i);
    }
    for (long i=2; i<=n; i++)
    {
        /*g[i]=-vc;
        long sum=a[i];
        for (long j=i-1; j>=1; j--)
           if (sum<=h)
           {
               g[i]=max(g[i],g[j]);
               sum+=a[j];
           }
        g[i]++;*/
        g[i]=get2(1,1,n,truoc[i]-1,i-1)+1;
        a2[i]=g[i];
        update2(1,1,n,i);
    }
    if (f[n]<=k && k<=g[n]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("QBSEGPAR.inp","r",stdin);
    freopen("QBSEGPAR.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) {cin >> a[i];s[i]=s[i-1]+a[i];}
    l=-1e9; r=1e9;
    /*while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }*/
    cout << kt(1);
}
