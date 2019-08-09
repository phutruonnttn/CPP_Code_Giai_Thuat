#include <bits/stdc++.h>
#define nmax 100007
#define vc 9999999999

using namespace std;

long long n,a[nmax],f[nmax],w[nmax],t[35][4*nmax],ans1,xx[10],rb,demt[35];
vector <long long> v;

void batbit(long k,long long &x)
{
    x=x|(1<<k);
}

long getbit(long k, long x)
{
    return ((x>>k)&1);
}

bool kt(long q, long p)
{
    for (long i=0; i<=4; i++)
    {
        long u=getbit(i,q), v=getbit(i,p);
        if (u&&v==1) return false;
    }
    return true;
}

long long get(long id,long x)
{
    long long res=-1;
    while (x>0)
    {
       res=max(res,t[id][x]);
       x-=(x&-x);
    }
    return res;
}

void update(long id, long x, long d)
{
    while (x<=nmax)
    {
        t[id][x]=d;
        x+=(x&-x);
    }
}

void gn()
{
    long long ll=0;
    for (long i=0; i<=4; i++) if (xx[i]) batbit(i,ll);
    if (demt[ll]!=0) ans1=max(ans1,get(ll,rb-1));
    /*if (rb==w[5])
    {
        cout << ans1 << ":";
        for (long i=0; i<=4; i++) cout << xx[i] << "";
        cout << endl;
    }*/
}

void tryy(long x,long i)
{
    for (long j=0; j<=1; ++j)
    {
        if (getbit(i,x)==1 && j==1)
        {
            if (i==4) gn();
            else tryy(x,i+1);
            break;
        }
        xx[i]=j;
        if (i==4) gn();
        else tryy(x,i+1);
    }
}

long long tinh(long x)
{
    ans1=0;
    tryy(x,0);
    return ans1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("COPRIME.inp","r",stdin);
    freopen("COPRIME.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; ++i)
    {
        long long u; cin >> u;
        w[i]=u;
        if (u%2==0)
        {
            batbit(0,a[i]);
            while (u%2==0) u/=2;
        }
        if (u%3==0)
        {
            batbit(1,a[i]);
            while (u%3==0) u/=3;
        }
        if (u%5==0)
        {
            batbit(2,a[i]);
            while (u%5==0) u/=5;
        }
        if (u%7==0)
        {
            batbit(3,a[i]);
            while (u%7==0) u/=7;
        }
        if (u%11==0)
        {
            batbit(4,a[i]);
            while (u%11==0) u/=11;
        }
    }

    v.assign(w + 1, w + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long long i=1;i<=n;i++)
         w[i]=lower_bound(v.begin(),v.end(),w[i])-v.begin()+1;

    f[1]=1;
    update(a[1],w[1],1);
    demt[a[1]]++;
    for (long i=2; i<=n; ++i)
    {
        rb=w[i];
        demt[a[i]]++;
        f[i]=tinh(a[i])+1;
        update(a[i],w[i],f[i]);
    }
    /*{
        f[i]=-1;
        for (long j=1; j<i; ++j)
          if (w[i]>w[j] && kt(a[i],a[j]))
             f[i]=max(f[i],f[j]);
        f[i]++;
    }*/
    long long ans=-1;
    for (long i=1; i<=n; ++i) ans=max(ans,f[i]);
    cout << ans;
}
