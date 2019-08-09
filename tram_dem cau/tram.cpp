#include <bits/stdc++.h>
#define nmax 100007
using namespace std;
const long long b=643;

long long n,m,cnt=0,num[nmax],low[nmax],dcau=0;
vector <long long> adj[nmax];
map <long long,long long> M1;

void dfs(long long u,long long p)
{
    long long dem=0;
    num[u]=low[u]=++cnt;
    for (long long i=0;i<adj[u].size();i++)
    {
        long long v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dem++;
            dfs(v,u);
            if (low[v]>num[u])
            {
                /*cout<<u<<" "<<v<<endl;*/ dcau++;
                long long kt1=((u*b+v)*b+u)*b, kt2=((v*b+u)*b+v)*b;
                if (M1[kt1]==111 || M1[kt2]==111) dcau--;
            }
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("tram.inp","r",stdin);
    freopen("tram.out","w",stdout);
    cin>>n;
    for (long long i=1;i<=n-1;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> m;
    long long demm=0;
    for (long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        long long kt=((x*b+y)*b+x)*b;
        M1[kt]=111;
        kt=((y*b+x)*b+y)*b;
        M1[kt]=111;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(num,0,sizeof(num));

    for (long long i=1;i<=n;i++)
    if (num[i]==0) dfs(i,0);

    cout<<dcau;
}
