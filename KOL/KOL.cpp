#include <bits/stdc++.h>

using namespace std;

long long n,m,z,b[130000],dd[130000],t[130000],w;

void build(long node,long L,long R)
{
    if (L==R)
    {
        dd[node]=b[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    dd[node]=max(dd[node*2],dd[node*2+1]);

}

long long get1(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dd[id];
    if ((L>v) || (R<u)) return -1;
    long mid=(L+R) /2 ;
    long long x1=get1(id*2,L,mid,u,v);
    long long x2=get1(id*2+1,mid+1,R,u,v);
    return max(x1,x2)+t[id];
}

void update1(long id, long L, long R, long u, long v, long w)
{
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        t[id]+=w;
        dd[id]+=w;
        return;
    };
    long mid=(L+R) /2;
    update1(id*2,L,mid,u,v,w);
    update1(id*2+1,mid +1,R,u,v,w);
    dd[id]=max(dd[id*2],dd[id*2+1]) +t[id];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("KOL.inp","r",stdin);
    freopen("KOL.out","w",stdout);
    cin >> n >> m >> z;
    memset(b,0,sizeof(b));
    build(1,1,n);
    for (long l=1; l<=z; l++)
    {
        long u,v;
        cin >> u >> v>> w;
        if (get1(1,1,n,u,v-1)+w<=m)
        {
            cout << "T" << endl;
            update1(1,1,n,u,v-1,w);
        }
        else cout << "N" << endl;
    }
}
