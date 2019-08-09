#include <bits/stdc++.h>
#define mmax 10007
using namespace std;
struct canh
{
    int x,y,w;
};
canh a[mmax];
long long sum,kq,tg[20][20],n,x[20],xkq[20],f,r,m;
bool dd[20];

void update()
{
    if (sum<kq)
    {
        kq=sum;
        for (int i=1;i<=n;i++) xkq[i]=x[i];
    }
}
void try_(int u)
{
    if (dd[u]==true)
    {
        if (u<n) try_(u+1);
        else update();
        return;
    }
    dd[u]=true;
    for (int v=u+1;v<=n;v++)
    if (dd[v]==false)
    {
        x[u]=v;x[v]=u;
        sum-=((r-f)*tg[u][v]);
        dd[v]=true;
        if (u==n) update();
        else try_(u+1);
        x[u]=0;x[v]=0;
        dd[v]=false;
        sum+=((r-f)*tg[u][v]);
    }
    dd[u]=false;
}
int main()
{
    freopen("friends.inp","r",stdin);
    freopen("friends.out","w",stdout);
    sum=0;
    memset(tg,0,sizeof(tg));
    cin>>f>>r>>n>>m;
    for (int i=1;i<=m;i++) {int x,y,w;cin>>x>>y>>w;tg[x][y]+=w;sum+=(r*w);tg[y][x]+=w;}

    //------------------------------------------------------------
    kq=round(1e9);
    memset(dd,false,sizeof(dd));
    try_(1);
    cout<<kq<<endl;
    for (int i=1;i<=n;i++)
        if (i<xkq[i])
        cout<<i<<" "<<xkq[i]<<endl;
}
