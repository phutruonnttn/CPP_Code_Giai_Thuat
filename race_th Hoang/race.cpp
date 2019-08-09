#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long,long> ii;

struct data
{
    long long w,id;
};

long long n,d[4*nmax],a1[nmax],b1[nmax],dd1[nmax],dd2[nmax],hs;
data a[nmax],b[nmax];
vector <ii> kq,kq1;

bool cmp(data q, data p)
{
    return q.w < p.w;
}

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=a1[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=max(d[node*2],d[node*2+1]);

}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return -10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=a1[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=max(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("race.inp","r",stdin);
    freopen("race.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i].w; a[i].id=i;}
    for (long i=1; i<=n; i++) {cin >> b[i].w; b[i].id=i;}
    sort(a+1,a+n+1,cmp); sort(b+1,b+n+1,cmp);

    for (long i=1; i<=n; i++) {a1[i]=i; b1[i]=b[i].w;}
    build(1,1,n);

    long long diem1=0,diem2=0;
    for (long i=n; i>=1; i--)
    {
        long j=lower_bound(b1+1,b1+n+1,a[i].w)-b1-1;
        //if (a[i].w!=b[j].w) j--;
        if (j>=1) j=get(1,1,n,1,j);
        if (j!=0)
        {
            dd1[j]=1;
            a1[j]=0;
            update(1,1,n,j);
            diem1++;
            dd2[i]=1;
            kq.push_back(ii(a[i].id,b[j].id));
        }
    }

    for (long i=1; i<=n; i++)
        if (dd2[i]==0)
        {
            long j=get(1,1,n,1,n);
            if (a[i].w>b[j].w) diem1++;
            else if (a[i].w<b[j].w) diem2++;
            a1[j]=0;
            update(1,1,n,j);
            kq.push_back(ii(a[i].id,b[j].id));
        }
    //cout << diem1<< " " << diem2 << endl; cout << endl;
    hs=abs(diem1-diem2);
    //------------------------------------------------
    for (long i=1; i<=n; i++) {a1[i]=i; b1[i]=b[i].w;dd1[i]=0;dd2[i]=0;}
    build(1,1,n);

    diem1=0,diem2=0;
    for (long i=n; i>=1; i--)
    {
        long j=lower_bound(b1+1,b1+n+1,a[i].w)-b1;
        if (a[i].w!=b[j].w) j--;
        if (j>=1) j=get(1,1,n,1,j);
        if (j!=0)
        {
            dd1[j]=1;
            a1[j]=0;
            update(1,1,n,j);
            if (a[i].w>b[j].w) diem1++;
            dd2[i]=1;
            kq1.push_back(ii(a[i].id,b[j].id));
        }
    }

    for (long i=1; i<=n; i++)
        if (dd2[i]==0)
        {
            long j=get(1,1,n,1,n);
            if (a[i].w>b[j].w) diem1++;
            else if (a[i].w<b[j].w) diem2++;
            a1[j]=0;
            update(1,1,n,j);
            kq1.push_back(ii(a[i].id,b[j].id));
        }
    //------------------------------------------------
    if (hs<abs(diem1-diem2)) kq=kq1;
    for (long i=0; i<kq.size(); i++) cout << kq[i].first << " " << kq[i].second <<endl;
}
