#include<bits/stdc++.h>
#define nmax 40000
using namespace std;
int n,m,stp,cnt,r;
bool freee[nmax];
int s[nmax],number[nmax],low[nmax],tp[nmax],a[10005][10005],b[10005][10005],bacra[nmax],bacvao[nmax];
vector <int> adj[nmax];
void dfs(int u)
{
    low[u] = number[u]=++cnt;
    freee[u]=false;
    r++;
    s[r]=u;
    for (int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if (freee[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(tp[v]==0)
              low[u]=min(low[u],number[v]);
    }
    if (low[u]==number[u])
    {
        tp[u]=++stp;
        while (s[r]!=u)
        {
            tp[s[r]]=stp;
            r--;
        }
        r--;
    }
}
int main()
{
    freopen("onearc.inp","r",stdin);
    freopen("onearc.out","w",stdout);
    cin>>n>>m;
    for (int k=1;k<=m;k++)
       {
           int i,j;
           cin>>i>>j;
           adj[i].push_back(j);
           a[i][j]=1;
       }
    memset(freee,true,sizeof(freee));
    memset(tp,0,sizeof(tp));
    cnt=0;
    r=0;
    stp=0;
    for (int i=1;i<=n;i++)
          if (freee[i]) dfs(i);
    for (int i=1;i<=stp;i++)
         for (int j=1;j<=stp;j++) b[i][j]=0;
    for (int i=1;i<n;i++)
            for (int j=i+1;j<=n;j++)
            if ((tp[i]!=tp[j]))
            {
                if (a[i][j]==1) b[tp[j]][tp[i]]=1;
                if (a[j][i]==1) b[tp[i]][tp[j]]=1;

            }
    memset(bacra,0,sizeof(bacra));
    memset(bacvao,0,sizeof(bacvao));
    for (int i=1;i<=stp;i++)
    {
        int s1=0,s2=0;
        for (int j=1;j<=n;j++)
           {
                if (b[i][j]==1) s1++;
                if (b[j][i]==1) s2++;
           }

     bacvao[i]=s2;
     bacra[i]=s1;
    }
    int u,v;
    int cc=0,ccc=0;
    for (int i=1;i<=stp;i++)
    {
        if (bacra[i]==0) {v=i;cc++;}
        if (bacvao[i]==0) {u=i;ccc++;}
    }
    if ((cc>1)||(ccc>1)) cout<<"NO";
          else
    {
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
        {
            if ((tp[i]==u)&&(tp[j]==v) &&(a[i][j]==0)) {cout<<i<<" "<<j;return 0;}
        }
    }
}
