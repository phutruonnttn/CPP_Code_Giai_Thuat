#include<bits/stdc++.h>
#define nmax 1000007

using namespace std;

struct data
{
    long long u,v,dd,id;
};

long long xa,ya,xb,yb,q,n,x[nmax],y[nmax],u,v,da[nmax],db[nmax],ans[nmax],t[3*nmax],rmax=0;
data a[nmax];

bool cmp(data p,data q)
{
    if (p.u!=q.u) return p.u<q.u;
    if (p.v!=q.v) return p.v<q.v;
    return p.dd<q.dd;
}

long long calc(long long x,long long y,long long a,long long b)
{
    long long ans=(x-a)*(x-a)+(y-b)*(y-b);
    return ceil(sqrt(ans));
}

long long get(long long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&(-x));
    }
    return res;
}

void update(long long x)
{
    while (x<rmax+1)
    {
        t[x]++;
        x+=(x&(-x));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nuclear.inp","r",stdin);
    freopen("nuclear.out","w",stdout);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> x[i] >> y[i];
    cin >> xa >> ya >> xb >> yb >> q;

    for (long long i=1; i<=n; i++)
    {
        long long r1=calc(xa,ya,x[i],y[i]);
        long long r2=calc(xb,yb,x[i],y[i]);
        a[i]={r1,r2,0,i};
        da[r1]++; db[r2]++;
        rmax=max(rmax,max(r1,r2));
    }
    for(long long i=1; i<=q; i++)
    {
        cin >> x[i] >> y[i];
        rmax=max(rmax,max(x[i],y[i]));
        a[n+i]={x[i],y[i],1,i};
    }

    for(long long i=1; i<=rmax; i++)
    {
        da[i]+=da[i-1];
        db[i]+=db[i-1];
    }

    sort(a+1,a+n+q+1,cmp);

    for (long long i=1; i<=n+q; i++)
    {
        if (a[i].dd==1)
        {
            long long res=0;
            res+=da[a[i].u]+db[a[i].v]-get(a[i].v);
            ans[a[i].id]=res;
        }
        else update(a[i].v);
    }

    for (long long i=1; i<=q; i++) cout << ans[i] << endl;
}
