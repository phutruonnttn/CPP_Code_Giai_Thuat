#include <bits/stdc++.h>
#define nmax 50007

using namespace std;

long long a,b,l,ans1=0,ans2=0,ans3=0;
int e[nmax],dd1[nmax];

void sangnt(long n)
{
  for (long i=2; i<=n; i++) e[i]=i;
  for (long i=2; i<=int(sqrt(n));i++)
    if (e[i]==i)
    {
        long j=i*i;
        while (j<=n)
        {
           e[j]=i;
           j=j+i;
        }
    }
}

long long euler(long long d, long long n)// dem xem co bao nhieu so tu 1 ->n la so nguyen to cung nhau voi d
{
    long long kq=0, p[20], m=0;
    while (d>1)
    {
        p[++m]=e[d];
        while (d%p[m]==0) d/=p[m];
    }

    //for (long i=1; i<=m; i++) cout << p[i] << " ";cout << endl;

    for (long x=0; x<(1<<m); ++x)
    {
        long long dem=0, tich=1;
        for (long i=0; i<m; ++i)
          if ((x>>i)&1) {++dem; tich*=p[i+1];}
        if (dem>0)
          if (dem%2) kq+=n/tich;
          else kq-=n/tich;
        //cout << x << " " << kq << " " << dem << endl;
    }
    //cout << kq << endl;
    return n-kq;
}

long long euler1(long long d1, long long d2, long long n)
{
    long long kq=0, p[20], m=0;
    memset(dd1,0,sizeof(dd1));
    while (d1>1)
    {
        long long nho=e[d1];
        p[++m]=nho;
        dd1[e[d1]]=1;
        while (d1%nho==0) d1/=nho;
    }
    while (d2>1)
    {
        long long nho=e[d2];
        if (dd1[nho]==0) p[++m]=e[nho];
        while (d2%nho==0) d2/=nho;
    }
    //for (long i=1; i<=m; i++) cout << p[i] << " "; cout << endl;
    for (long x=0; x<(1<<m); ++x)
    {
        long long dem=0, tich=1;
        for (long i=0; i<m; ++i)
          if ((x>>i)&1) {++dem; tich*=p[i+1];}
        if (dem>0)
          if (dem%2) kq+=n/tich; else kq-=n/tich;
    }
    return n-kq;
}

long long f(long long d)
{
    return euler(d,l);
}

long long g(long long d1, long long d2)
{
    return euler1(d1,d2,l);
}

int main()
{
   ios_base::sync_with_stdio(0);
   freopen("VAULTS.inp","r",stdin);
   freopen("VAULTS.out","w",stdout);
   cin >> a >> b >> l;
   sangnt(5000);
   //long x=-1;
   for (long x=-a; x<=b; ++x)
   {
       long long ant,bnt,cnt,knt;
       if (x==-a)
       {
           ant=1;
           bnt=f(b-x);
           cnt=1;
       }
       else if (x==b)
       {
           ant=f(x+a);
           bnt=1;
           cnt=1;
       }
       else
       {
           ant=f(x+a);
           bnt=f(b-x);
           cnt=g(x+a,b-x);
       }
       knt=l-ant-bnt+cnt;
       ans1+=knt; ans3+=cnt; ans2+=l-knt-cnt;
       //cout << ant << " " << bnt << " " << cnt << " " << knt << " " << l-knt-cnt << endl;
   }
   cout << ans1 << '\n' << ans2 << '\n' << ans3;
}
