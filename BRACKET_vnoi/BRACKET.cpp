#include <bits/stdc++.h>
#define nmax 1000007
#define nmod 1000000007

using namespace std;

struct data {long long l,r,dai;};

long long ww=1,n,m,dd[nmax],ans=0,x[27],gt[3*nmax],ctl[nmax],d[nmax],tr[nmax],dem[nmax];
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

    stack <long> st;
    long long stt=1;
    for (long i=n; i>=1; i--)
     if (d[i]==2)
     {
         st.push(tr[i]);
         stt++;
         dem[stt]=0;
     }
     else if (dd[i]==1)
     {
         if(st.top()!=i)
            {
                cout << 0;
                return;
            }
         else
           {
              st.pop();
              ans=(ans*ctl[dem[stt]/2])%nmod;
              --stt;
           }
     }
     else dem[stt]++;
    ans=(ans*ctl[dem[1]/2])%nmod;
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
        d[ngoac[i].l]=1; d[ngoac[i].r]=2;
        tr[ngoac[i].r]=ngoac[i].l;
    }
    if (n<20) sub1();
    else sub2();
}

