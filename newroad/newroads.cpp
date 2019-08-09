#include <bits/stdc++.h>
using namespace std;
long n,m,top,li[10007],kq,dem,vung[10007];
bool dd[10007],a[10007][10007];
vector <long> adj1[500007],adj2[500007];
void number(long u)
{
    dd[u]=true;
    for (long i=0;i<adj1[u].size();i++)
    {
        long v=adj1[u][i];
        if (dd[v]==false) number(v);
    }
    li[++top]=u;
}
void dfs(long u)
{
    dd[u]=true;
    vung[u]=dem;
    for (long i=0;i<adj2[u].size();i++)
    {
        long v=adj2[u][i];
        if (dd[v]==false) dfs(v);
    }
}
int main()
{
    freopen("newroads.inp","r",stdin);
    freopen("newroads.out","w",stdout);
    cin>>n>>m;
    memset(a,false,sizeof(a));
    for (long i=1;i<=m;i++)
    {
        long x,y;
        cin>>x>>y;
        a[x][y]=true;
        adj1[x].push_back(y);
        adj2[y].push_back(x);
    }
    //-------------------------------
    memset(dd,false,sizeof(dd));
    top=0;
    for (long i=1;i<=n;i++)
        if (dd[i]==false) number(i);
    //-------------------------------
    memset(dd,false,sizeof(dd));
    kq=0;dem=0;
    for (long i=n;i>=1;i--)
        if (dd[li[i]]==false)
        {
            dem++;dfs(li[i]);
        }
    for (long i=1;i<n;i++)
        for (long j=i+1;j<=n;j++)
        if (vung[i]==vung[j])
        {
            if (a[i][j]==false) kq++;
            if (a[j][i]==false) kq++;
        }
    cout<<kq<<endl;
    //cout<<dem;
}

