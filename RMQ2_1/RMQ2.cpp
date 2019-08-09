#include <bits/stdc++.h>

using namespace std;

const int N=5e2+2;
int m,n,q,MAX;
int a[N][N],f[N][N*4],g[N*4][N*4];

int IT(int x, int l, int r, int note)
{
    MAX=max(MAX,note);
    if ( l == r )
    {
        f[x][note]=a[l][x];
        return f[x][note];
    }
    int mid=(l+r)/2;
    int h=IT(x,l,mid,note*2);
    int k=IT(x,mid+1,r,note*2+1);
    f[x][note]=min(h,k);
    return f[x][note];
}

int IntervalTree(int note, int l, int r, int node)
{
    if ( l == r )
    {
        g[note][node]=f[l][note];
        return g[note][node];
    }
    int mid=(l+r)/2;
    int h=IntervalTree(note,l,mid,node*2);
    int k=IntervalTree(note,mid+1,r,node*2+1);
    g[note][node]=min(h,k);
    return min(h,k);
}

int get(int note, int u, int v, int l, int r, int node)
{
    if ( v < l || r < u ) return LONG_MAX;
    if ( u <= l && r <= v ) return g[note][node];
    int mid=(l+r)/2;
    int h=get(note,u,v,l,mid,node*2);
    int k=get(note,u,v,mid+1,r,node*2+1);
    return min(h,k);
}

int getIT(int x, int y, int u, int v, int l, int r, int note)
{
    if ( y < l || r < x ) return LONG_MAX;
    if ( x <= l && r <= y ) return get(note,u,v,1,n,1);
    int mid=(l+r)/2;
    int h=getIT(x,y,u,v,l,mid,note*2);
    int k=getIT(x,y,u,v,mid+1,r,note*2+1);
    return min(h,k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RMQ2.inp","r",stdin);
    freopen("RMQ2.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    cin>>q;
    for(int i=1;i<=n;i++)
        IT(i,1,m,1);
    for(int i=1;i<=MAX;i++)
        IntervalTree(i,1,n,1);
    while(q--)
    {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        cout<<getIT(x,u,y,v,1,m,1)<<endl;
    }
}
