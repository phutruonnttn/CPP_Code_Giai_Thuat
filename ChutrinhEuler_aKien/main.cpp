#include <bits/stdc++.h>
#define nmax 10007
using namespace std;
int n,m,w[nmax];
vector <int> adj[nmax];

void xoa(int x,int y)
{
    vector <int> tmp;
    bool ok=false;

    for (int i=0;i<adj[x].size();i++)
    {
        int v=adj[x][i];
        if (ok || (v!=y)) tmp.push_back(v);
        if (v==y) ok=true;
    }
    adj[x]=tmp;
    //---------------------------------------
    tmp.clear();
    ok=false;
    for (int i=0;i<adj[y].size();i++)
    {
        int v=adj[y][i];
        if (ok || (v!=x)) tmp.push_back(v);
        if (v==x) ok=true;
    }
    adj[y]=tmp;
}
bool cangoback(int x,int y)
{
    bool dd[nmax];
    for (int i=1;i<=n;i++) dd[i]=false;
    queue <int> Q;
    xoa(x,y);
    Q.push(y);
    dd[y]=true;
    while (Q.size()>0)
    {
        int u=Q.front();Q.pop();
        for (int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if (!dd[v])
            {
                dd[v]=true;Q.push(v);
            }
        }
        if (dd[x]) break;
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
    return dd[x];
}
void giai()
{
    vector <int> kq;
    int u=1,next;
    kq.push_back(1);
    do
    {
        next=0;
        for (int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            next=v;
            if (cangoback(u,next)) break;
        }
        if (next!=0)
        {
            xoa(u,next);
            kq.push_back(next);
            u=next;
        }
    }
    while (next!=0);
    cout<<kq.size()-1<<endl;
    for (int i=kq.size()-1;i>=0;i--) cout<<kq[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nkpos.inp","r",stdin);
    freopen("nkpos.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    giai();
}
