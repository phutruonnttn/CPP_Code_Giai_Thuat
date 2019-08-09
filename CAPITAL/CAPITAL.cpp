#include <bits/stdc++.h>
#define nmax 3000007

using namespace std;

struct data
{
    long long a,b;
};

long long n,m,cnt=0,num[nmax],low[nmax],dkhop=0,dcau=0,out[nmax],cau[nmax],lt[nmax];
vector <long long> adj[nmax];
data kt[nmax];
int dd[nmax];

bool cmp(data q, data p)
{
    if (q.a!=p.a) return q.a < p.a;
    return q.b < p.b;
}

void dfs(long u,long p)
{
    long dem=0;
    num[u]=low[u]=++cnt;
    for (long i=0;i<adj[u].size();i++)
    {
        long v=adj[u][i];
        if (v==p) continue;
        if (num[v]==0)
        {
            dem++;
            dfs(v,u);
            if (low[v]>num[u])
            {
                dcau++;
                cau[u]++;
                cau[v]++;
            }
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u],num[v]);
    }
}

void dfskt(long u, long k)
{
    dd[u]=1;
    for (long i=0; i<adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (dd[v]==0 && v!=k) dfskt(v,k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CAPITAL.inp","r",stdin);
    freopen("CAPITAL.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=m;i++)
    {
        /*long long x,y;
        cin>>x>>y;
        out[x]++;
        out[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);*/
        cin >> kt[i].a >> kt[i].b;
        if (kt[i].a>kt[i].b) swap(kt[i].a,kt[i].b);
    }
    long long dem=0;
    sort(kt+1,kt+m+1,cmp);
    for (long long i=1;i<=m;i++)
    {
        if (kt[i].a==kt[i-1].a && kt[i].b==kt[i-1].b) continue;
        dem++;
        long long x=kt[i].a,y=kt[i].b;
        out[x]++;
        out[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //cout <<dem ;
    memset(num,0,sizeof(num));
    for (long long i=1;i<=n;i++)
      if (num[i]==0) dfs(i,0);

    for (long i=1; i<=n; i++)
        lt[i]=min(cau[i]+1,out[i]);

    long ans=lt[1], vt=1;
    for (long i=2; i<=n; i++)
       if (ans<lt[i])
       {
          ans=lt[i];
          vt=i;
       }
    //cout << ans << " " << vt;
    ans=0;
    for (long i=1; i<=n; i++)
      if (dd[i]==0 && i!=vt)
        {
          ans++;
          dfskt(i,vt);
        }
     cout << ans << " " << vt;
}
