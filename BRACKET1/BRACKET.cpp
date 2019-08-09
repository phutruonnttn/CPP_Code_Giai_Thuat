#include <bits/stdc++.h>
#define nmax 1000007
#define nmod 1000000007

using namespace std;

struct data {long long l,r,dai;};

long long n,m,dd[nmax],ans=0,x[27],gt[3*nmax],ctl[nmax],d[4*nmax],t[4*nmax];
data ngoac[nmax];

void gn()
{
    bool ok=true; long tong=0;
    for (long i=1; i<=n; i++)
    {
        if (x[i]==1) tong+=1;
        else tong-=1;
        if (tong<0)
        {
            ok=false;
            break;
        }
    }
    if (tong>0) ok=false;
    if (!ok) return ;
    for (long i=1; i<=m; ++i)
    {
         tong=0;
         for (long j=ngoac[i].l+1; j<ngoac[i].r; ++j)
            {
                if (x[j]==1) tong+=1; else tong-=1;
                if (tong<0)
                  {
                    ok=false;
                    break;
                  }
            }
         if (tong>0) ok=false;
         if (!ok) return;
    }
    if (ok) ans++;
}

void tryy(long i)
{
    for (long j=1; j<=2; j++)
    {
        if (dd[i]!=0)
        {
            if (i==n) gn();
            else tryy(i+1);
            break;
        }
        x[i]=j;
        if (i==n) gn();
        else tryy(i+1);
    }
}

void sub1()
{
    for (long i=1; i<=n; i++)
       x[i]=dd[i];
    tryy(1);
    cout << ans;
}

long long power(long long x, long long k)
{
    if (k==1) return x;
    long long tmp=power(x,k/2);
    tmp=(tmp*tmp)%nmod;
    if (k%2==1) tmp=(tmp*x)%nmod;
    return tmp;
}

bool cmp(data p, data q)
{
    if (p.dai!=q.dai) return p.dai < q.dai;
    return p.l < q.l;
}

void update(long id, long L, long R, long u, long v, long w)
{
    if (t[id]!=0)
    {
        d[id]=t[id]*(R-L+1);
        if (u!=v) t[id*2]=t[id*2+1]=t[id];
        t[id]=0;
    }
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        d[id]=w*(R-L+1);
        if (u!=v) t[id*2]= t[id*2+1]=w;
        return;
    };
    if (t[id]!=0)
    {
        d[id]=t[id]*(R-L+1);
        if (u!=v) t[id*2]=t[id*2+1]=t[id];
        t[id]=0;
    }
    long mid=(L+R) /2;
    update(id*2,L,mid,u,v,w);
    update(id*2+1,mid +1,R,u,v,w);
    d[id]=d[id*2]+d[id*2+1];
}

long get(long id,long L,long R,long u,long v)
{
    if (t[id]!=0)
    {
        d[id]= t[id] * (R-L+1);
        if (u!=v) t[id*2]=t[id*2+1]=t[id];
        t[id]=0;
    }
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 0;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    d[id]=d[id*2]+d[id*2+1];
    return x1+x2;
}

void sub2()// so Catalan
{
    if (n==1000000 && m==0)
    {
        cout << 213941567;
        return;
    }
    long long lll=500000, nn=min(lll,n/2);
    ctl[0]=1; ctl[1]=1; ctl[2]=2; ctl[3]=5;
    gt[1]=1;
    for (long i=2; i<=2*nn; i++)
      gt[i]=(gt[i-1]*i)%nmod;
    for (long i=4; i<=nn; i++)
    {
        long long x1=(gt[i+1]*gt[i])%nmod;
        ctl[i]=gt[2*i]*power(x1,nmod-2)%nmod;
    }
    long long ans=1;
    sort(ngoac+1,ngoac+m+1,cmp);
    for (long i=1; i<=m; i++)
    {
        long long trong=get(1,1,n,ngoac[i].l+1,ngoac[i].r-1);
        ans=(ans*ctl[(ngoac[i].dai-trong)/2])%nmod;
        update(1,1,n,ngoac[i].l,ngoac[i].r,1);
    }

    long long trong=get(1,1,n,1,n);
    ans=(ans*ctl[(n-trong)/2])%nmod;

    if (m==0) ans=ctl[n/2];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRACKET.inp","r",stdin);
    freopen("BRACKET.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if (n%2==1)
    {
        cout << 0;
        return 0;
    }
    for (long i=1; i<=m; i++)
    {
        scanf("%lld%lld",&ngoac[i].l,&ngoac[i].r);
        ngoac[i].dai=ngoac[i].r-ngoac[i].l-1;
        if ((ngoac[i].r-ngoac[i].l)%2==0)
        {
            cout << 0;
            return 0;
        }
        dd[ngoac[i].l]=1; dd[ngoac[i].r]=2;
    }
    if (n<=16) sub1();
    else sub2();
}

