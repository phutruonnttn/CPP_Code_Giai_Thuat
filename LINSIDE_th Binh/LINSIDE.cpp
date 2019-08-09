#include <bits/stdc++.h>
#define nmax 100007
#define xmax 1000007

using namespace std;

struct data
{
    long long a,b;
};

struct data1
{
    long long gt,id;
};

long long n,f[nmax],tr[nmax];
data doan[nmax];
data1 d[4*xmax],tv,aa[4*xmax];

bool cmp(data q, data p)
{
    if (q.b!=p.b) return q.b < p.b;
    return q.a > p.a;
}

data1 get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return tv;
    long mid=(L+R) /2 ;
    data1 x1=get(id*2,L,mid,u,v);
    data1 x2=get(id*2+1,mid+1,R,u,v);
    if (x1.gt>=x2.gt) return x1;
    else return x2;
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id].gt=aa[x].gt;
        d[id].id=aa[x].id;
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    if (d[id*2].gt>=d[id*2+1].gt) d[id]=d[id*2];
    else d[id]=d[id*2+1];
}

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

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LINSIDE.inp","r",stdin);
    freopen("LINSIDE.out","w",stdout);
    doc(n);
    for (long i=1; i<=n; i++) {doc(doan[i].a); doc(doan[i].b); f[i]=1;}
    sort(doan+1,doan+n+1,cmp);

    tv.gt=-1; tv.id=-1;

    aa[doan[1].a].gt=f[1];
    aa[doan[1].a].id=1;
    update(1,1,xmax,doan[1].a);
    for (long i=2; i<=n; i++)
     {
         data1 pq=get(1,1,xmax,doan[i].a,xmax);
         f[i]=pq.gt+1;
         tr[i]=pq.id;
         aa[doan[i].a].gt=f[i];
         aa[doan[i].a].id=i;
         update(1,1,xmax,doan[i].a);
     }

    long long ans=-1,vtt;
    for (long i=1; i<=n; i++)
      if (f[i]>ans)
      {
          ans=f[i];
          vtt=i;
      }
    cout << ans << '\n';
    while (vtt!=0)
    {
        cout << doan[vtt].a << " " << doan[vtt].b << '\n';
        vtt=tr[vtt];
    }
}
