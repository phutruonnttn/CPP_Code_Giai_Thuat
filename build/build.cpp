#include <bits/stdc++.h>
#define nmax 1e10+7
using namespace std;
typedef pair <long long,long long> ii;

long long n,m,p,d[1007],dem[1007],adj[1007][1007],u1[1000007],v1[1000007],w1[1000007];
vector <ii> a[1007];
bool ok=true;

void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n+1,nmax);
    d[1]=0;
    dem[1]++;
    pq.push(ii(0,1));

    long long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long long v=a[u][i].first;
            long long wv=a[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                pq.push(ii(-d[v],v));
                dem[v]++;
                if (dem[v]==n)
                {
                    ok=false;
                    return ;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("build.inp","r",stdin);
    freopen("build.out","w",stdout);
    cin >> n >> m >> p;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        adj[i][j]=1e9+7;
    memset(dem,0,sizeof(0));
    for (long i=1; i<=n-1; i++)
    {
        long u=i+1, v=i;
        adj[u][v]=0;
    }
    for (long i=1; i<=m; i++)
    {
        long long u,v,w;
        cin >> u >> v >> w;
        adj[u][v]=min(adj[u][v],w);
    }
    for (long i=1; i<=p; i++)
    {
        long long u,v,w;
        cin >> u >> v >> w;
        adj[v][u]=min(adj[v][u],-w);
    }
    long demm=0;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        if (adj[i][j]!=1e9+7)
          {a[i].push_back(ii(j,adj[i][j]));
           u1[++demm]=i;
           v1[demm]=j;
           w1[demm]=adj[i][j];}

    dijkstra();
    if (!ok) cout << -1;
    else if (d[n]==nmax) cout <<-2;
    else cout << d[n];

    /*fill(d,d+n+1,1e10+7);
    d[1]=0;
    long change=1;
    for (long i=1; i<=n; i++)           //Thuat toan Forbell Man
    {
        change=0;
        for (long j=1; j<=demm; j++)
           if (d[u1[j]]+w1[j]<d[v1[j]])
           {
               d[v1[j]]=d[u1[j]]+w1[j];
               change=1;
           }
    }
    if (change==1) cout << -2;
    else if (d[n]==nmax) cout <<-1;
    else cout << d[n];*/
}
