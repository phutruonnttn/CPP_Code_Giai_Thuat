#include <bits/stdc++.h>
#define nmax 1000007
#define vc 9999999999

using namespace std;

struct data
{
    long long id,gt;
};

long long n,a[nmax],aa[nmax],ans=0,dmin[4*nmax],amin[nmax],dmax[4*nmax],amax[nmax];
data thu[nmax];

void doc(long long &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;
    if (ktAm) n=-n;
}

void sub1()
{
    long long dem=0;
    while (dem!=n)
    {
        long long vtm=0,t=-1,g,p=-1;
        for (long i=1; i<=n; i++)
           if (aa[i]>vtm)
           {
                vtm=aa[i];
                g=i;
                if (i>1) t=i-1;
                if (i<n) p=i+1;
           }
        dem++;
        ans+=aa[g];
        aa[g]=0;
        if (t!=-1) ans+=aa[t];
        if (p!=-1) ans+=aa[p];
    }
    cout << ans << endl;
}


void buildmin(long node,long L,long R)
{
    if (L==R)
    {
        dmin[node]=amin[L];
        return;
    };
    long mid=(L+R) /2;
    buildmin(node*2,L,mid);
    buildmin(node*2+1,mid+1,R);
    dmin[node]=min(dmin[node*2],dmin[node*2+1]);
}

long long getmin(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dmin[id];
    if ((L>v) || (R<u)) return vc;
    long mid=(L+R) /2 ;
    long long x1=getmin(id*2,L,mid,u,v);
    long long x2=getmin(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void updatemin(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        dmin[id]=amin[x];
        return;
    };
    long mid=(L+R) /2;
    updatemin(id*2,L,mid,x);
    updatemin(id*2+1,mid +1,R,x);
    dmin[id]=min(dmin[id*2],dmin[id*2+1]);
}

void buildmax(long node,long L,long R)
{
    if (L==R)
    {
        dmax[node]=amax[L];
        return;
    };
    long mid=(L+R) /2;
    buildmax(node*2,L,mid);
    buildmax(node*2+1,mid+1,R);
    dmax[node]=max(dmax[node*2],dmax[node*2+1]);
}

long long getmax(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dmax[id];
    if ((L>v) || (R<u)) return -vc;
    long mid=(L+R) /2 ;
    long long x1=getmax(id*2,L,mid,u,v);
    long long x2=getmax(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void updatemax(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        dmax[id]=amax[x];
        return;
    };
    long mid=(L+R) /2;
    updatemax(id*2,L,mid,x);
    updatemax(id*2+1,mid +1,R,x);
    dmax[id]=max(dmax[id*2],dmax[id*2+1]);
}

bool cmp(data q, data p)
{
    if (q.gt!=p.gt) return q.gt > p.gt;
    return q.id < p.id;
}

long long tinh(long long x)
{
     long long res=0;
     res+=a[x];
     if (x>1)
     {
         long long vt=getmax(1,1,n,1,x-1);
         res+=a[vt];
     }
     if (x<n)
     {
         long long vt=getmin(1,1,n,x+1,n);
         if (vt!=vc) res+=a[vt];
     }
     amin[x]=vc;
     updatemin(1,1,n,x);
     amax[x]=0;
     updatemax(1,1,n,x);
     return res;
}

void sub2()
{
    ans=0;
    sort(thu+1,thu+n+1,cmp);
    for (long i=1; i<=n; i++)
    {
        amin[i]=i;
        amax[i]=i;
    }
    buildmax(1,1,n);
    buildmin(1,1,n);
    //for (long i=1; i<=n; i++) ans+=tinh(thu[i].id);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bird.inp","r",stdin);
    freopen("bird.out","w",stdout);
    doc(n);
    for (long i=1; i<=n; ++i)
    {
        doc(a[i]);
        aa[i]=a[i];
        thu[i].gt=a[i];
        thu[i].id=i;
    }
    /*if (n<=1000)sub1();
    else */sub2();
}
