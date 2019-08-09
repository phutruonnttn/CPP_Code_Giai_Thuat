#include <bits/stdc++.h>

using namespace std;

struct data
{
    long long id, l, r;
};

long long n,m,k,t[200007],roirac[200007],srr=0;
data a[100007],b[100007];
pair <pair <long, long>, long> l[200007];

bool comp(data p, data q)
{
    if (p.id!=q.id) return p.id < q.id;
    if (p.l!=q.l) return p.l < q.l;
    if (p.r!=q.r) return p.r < q.r;
}

long get(long x)
{
    long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&(-x));
    }
    return res;
}

void update(long x, long d)
{
    while (x<=200007)
    {
        t[x]+=d;
        x+=(x&(-x));
    }
}

long rr(long x)
{
    return lower_bound(roirac+1,roirac+srr+1,x)-roirac;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    cin >> n >> m;
    cin >> k; long long da=0, db=0;
    for (long i=1; i<=k; i++)
    {
        long long u,v; char s;
        cin >> u >> v >> s;
        roirac[++srr]=v;
        if (s=='N') a[++da] = {v,u,n};
        if (s=='S') a[++da] = {v,1,u};
        if (s=='W') b[++db] = {u,1,v};
        if (s=='E') b[++db] = {u,v,m};
    }

    //roirac[++srr]=1;
    //roirac[++srr]=n;
    sort(roirac+1,roirac+srr+1);

    sort(a+1, a+da+1, comp);
    sort(b+1, b+db+1, comp);

    long long top=1;
    for (long i=2; i<=da; i++)
        if (a[i].id==a[top].id && a[i].l<=a[top].r) a[top].r=max(a[top].r,a[i].r);
        else a[++top]=a[i];
    da=top;

    top=1;
    for (long i=2; i<=db; i++)
        if (b[i].id==b[top].id && b[i].l<=b[top].r) b[top].r=max(b[top].r,b[i].r);
        else b[++top]=b[i];
    db=top;

    long long ans=0;
    for (long i=1;i<=da;i++)
        ans+=(a[i].r-a[i].l+1);
    for (long i=1;i<=db;i++)
        ans+=(b[i].r-b[i].l+1);

    /*for (long i=1; i<=da; i++)
      for (long j=1; j<=db; j++)
         {
              long long x=b[j].id, y=a[i].id;
              if (a[i].l<=x && x<=a[i].r && b[j].l<=y && b[j].r>=y) ans--;
         }*/

    long sl=0;
    for (long i=1; i<=da; i++)
    {
        l[++sl]=make_pair(make_pair(a[i].l,a[i].id),1);
        l[++sl]=make_pair(make_pair(a[i].r+1,a[i].id),-1);
    }
    sort(l+1,l+sl+1);

    long j=1;
    for (long i=1; i<=db; i++)
    {
        while (l[j].first.first<=b[i].id)
        {
            update(rr(l[j].first.second),l[j].second);
            j++;
        }
        ans-=get(rr(b[i].r))-get(rr(b[i].l)-1);
    }
    cout << ans;
}
