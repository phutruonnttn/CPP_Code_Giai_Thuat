#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1000000],d[4000007],w,t[4000007];

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=a[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=d[node*2]+d[node*2+1];
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

void sinhtest()
{
    freopen("SUMRANGE2.inp","w",stdout);
    srand(time(NULL));
    cout << 10 <<" " << 5 << endl;
    for (long i=1; i<=10; i++)
       cout << rand()%10 << " ";
    cout << endl;
    for (long i=1; i<=5; i++)
    {
        long tip=rand()%2;
        if (tip==0)
        {
            long ll=10,k=5+rand()%5;
            cout << 1 << " " << 1+rand()%5 << " " << 1+min(ll,k) << " " << rand()%10 << endl;
        }
        else
        {
            long ll=10,k=5+rand()%5;
            cout << 2 << " " << 1+rand()%5 << " " << 1+min(ll,k) << endl;
        }
    }
}

void trau()
{
    for (long i=1; i<=m; i++)
    {
        long tip;
        cin >> tip;
        if (tip==1)
        {
            long u,v,w; cin >> u >> v >> w;
            for (long j=u; j<=v; j++)
               a[j]=w;
        }
        else
        {
            long u,v; cin >> u >> v;
            long long sum=0;
            for (long j=u; j<=v; j++)
               sum+=a[j];
            cout << sum << endl;
        }
    }
}

int main()
{
    //sinhtest();
    ios_base::sync_with_stdio(0);
    freopen("SUMRANGE2.inp","r",stdin);
    freopen("SUMRANGE2.out","w",stdout);
    memset(t,0,sizeof(t));
    cin >> n >> m;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    //trau();
    build(1,1,n);
    for (long i=1; i<=m; i++)
      {
          long long x1,x2,x3;
          cin >> x1 >> x2 >> x3;
          if (x1==1)
          {
              cin >> w;
              update(1,1,n,x2,x3,w);
          }
          else
          {
            cout << get(1,1,n,x2,x3) <<endl;
          }
      }
}
