#include <bits/stdc++.h>

using namespace std;

long long k,n;
long f[10000007],d[40000007];

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 100;
    long mid=(L+R) /2 ;
    long x1=get(id*2,L,mid,u,v);
    long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=f[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=min(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LSPITO.inp","r",stdin);
    freopen("LSPITO.out","w",stdout);
    //memset(f,0,sizeof(f));
    f[0]=0;        n=1000000;
    for (long i=1; i<=1000000; i++)
    {
        long minn=f[i-1];
        /*for (long j=1; j<=trunc(sqrt(i));j++)
            {minn=min(f[i-1],f[i-j]); if (minn==0) break;}*/
        minn=min(minn,get(1,1,n,i-trunc(sqrt(i)),i-1));
        f[i]=1-minn;
        update(1,1,n,i);
        //f[i]=1-minn;
    }
    while (1<2)
    {
        k=-1; cin >> k;
        if (k==-1) break;
        if (f[k]==1) cout << "Conan" << endl; else cout << "Thu Uyen" << endl;
    }
}
