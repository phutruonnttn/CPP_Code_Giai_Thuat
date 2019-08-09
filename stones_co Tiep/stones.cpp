#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

struct data
{
    long long gt,id;
};

long long n,m;
priority_queue <long long> lt[nmax];
data d[4*nmax],tv,a[nmax];

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node].gt=a[L].gt;
        d[node].id=a[L].id;
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    if (d[node*2].gt>=d[node*2+1].gt) d[node]=d[node*2];
    else d[node]=d[node*2+1];
}

data get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return tv;
    long mid=(L+R) /2 ;
    data x1=get(id*2,L,mid,u,v);
    data x2=get(id*2+1,mid+1,R,u,v);
    if (x1.gt>=x2.gt) return x1;
    else return x2;
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id].gt=a[x].gt;
        d[id].id=a[x].id;
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    if (d[id*2].gt>=d[id*2+1].gt) d[id]=d[id*2];
    else d[id]=d[id*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("stones.inp","r",stdin);
    freopen("stones.out","w",stdout);
    cin >> n >> m;
    tv.gt=-1; tv.id=-1;
    for (long i=1; i<=m; i++)
    {
        a[i].gt=0;
        a[i].id=i;
    }
    build(1,1,m);
    for (long i=1; i<=n; i++)
    {
        long long type,t,w;
        cin >> type;
        if (type==1)
        {
            cin >> t >> w;
            long long truoc;
            if (!lt[t].empty()) truoc=-lt[t].top();
            else truoc=-1;
            lt[t].push(-w);
            a[t].gt=-lt[t].top();
            if (a[t].gt!=truoc) update(1,1,m,t);
        }
        else
        {
            data ans=get(1,1,m,1,m);
            cout << ans.gt << '\n';
            lt[ans.id].pop();
            a[ans.id].gt=-lt[ans.id].top();
            update(1,1,m,ans.id);
        }
    }
}
