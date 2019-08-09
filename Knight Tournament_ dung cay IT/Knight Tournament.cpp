#include <bits/stdc++.h>
#define nmax 300007

using namespace std;

long n,m,l[nmax],r[nmax],x[nmax],kq[nmax],d[4*nmax],t[4*nmax],ww;

void push(long i)
{
    d[i]=t[i*2]=t[i*2+1]=d[i*2]=d[i*2+1]=t[i];
    t[i]=-1;
}

long get(long id,long L,long R,long u,long v)
{
    if ((L>v) || (R<u)) return 10000000000;
    if ((L>=u) && (R<=v)) return d[id];
    if (t[id]!=-1) push(id);
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void update(long id, long L, long R, long u, long v)
{
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        t[id]=ww;
        d[id]=ww;
        return;
    };
    if (t[id]!=-1) push(id);
    long mid=(L+R) /2;
    update(id*2,L,mid,u,v);
    update(id*2+1,mid +1,R,u,v);
    d[id]=min(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Knight Tournament.inp","r",stdin);
    freopen("Knight Tournament.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++) cin >> l[i] >> r[i] >> x[i];
    for (long i=m; i>=1; i--)
    {
        /*for (long j=l[i]; j<=r[i]; j++)
            if (j!=x[i])
              kq[j]=x[i];*/
        ww=x[i];
        if (l[i]<x[i] && x[i]<r[i])
        {
            update(1,1,n,l[i],x[i]-1);
            update(1,1,n,x[i]+1,r[i]);
        }
        else
        if (l[i]>x[i] || x[i]>r[i]) update(1,1,n,l[i],r[i]);
        else
        if (l[i]==x[i]) update(1,1,n,l[i]+1,r[i]);
        else update(1,1,n,l[i],r[i]-1);
    }
    for (long i=1; i<=n; i++)
        cout << get(1,1,n,i,i) << " ";
}
