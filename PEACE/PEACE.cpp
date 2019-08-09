#include <bits/stdc++.h>
#define nmax 100007
using namespace std;
typedef pair <long, long> ii;

long n,m,h[nmax],par[10007][10007],d[nmax],tr[nmax];
vector <long> adj[nmax];
vector <ii> ad[nmax];

void dijkstra(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[uu]=0;
    pq.push(ii(0,uu));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<ad[u].size();i++)
        {
            long v=ad[u][i].first;
            long wv=ad[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

void dfs(long u)
{
  for (long i = 0; i < adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (v!=par[u][0])
        {
            par[v][0]=u; h[v]=h[u]+1;
            for (long j=1; j<=17; j++)
                par[v][j]=par[par[v][j-1]][j-1];
            dfs(v);
        }
    }
}

long LCAs(long u, long v)
{
    if (h[u]<h[v]) swap(u,v);
    long del=h[u]-h[v];
    for (long i=0; i<=17; i++)
        if ((del >> i )& 1) u=par[u][i];
    if (u==v) return u;

    for (long i=17; i>=0 ; i--)
        if (par[u][i]!=par[v][i])
         {
           u=par[u][i];
           v=par[v][i];
         }
    return par[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PEACE.inp","r",stdin);
    freopen("PEACE.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n-1; i++)
     {
        long u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ad[u].push_back(ii(v,1));
        ad[v].push_back(ii(u,1));
     }
    dfs(1);
    for (long i=1; i<=m; i++)
    {
        long a,b,c; cin >> a >> b >> c;
        long cm=LCAs(a,b),cc=LCAs(a,c),mc=LCAs(b,c);
        dijkstra(b);
        long tv=c,truyvet[nmax],dtv=0;
        while (tv!=b)
        {
            truyvet[++dtv]=tv;
            tv=tr[tv];
        }
        truyvet[++dtv]=b;

        //for (long j=dtv; j>=1; j--) cout << truyvet[j] << " "; cout << endl;

        long rb=d[c],xet[5],dem=0;
        dijkstra(cm);
        if (d[c]<=rb) xet[++dem]=cm;

        bool ok=false;
        for (long j=1; j<=dtv; j++)
          if (truyvet[j]==xet[dem]) {ok=true; break;}
        if (!ok) dem--;

        dijkstra(cc);
        if (d[c]<=rb) xet[++dem]=cc;

        ok=false;
        for (long j=1; j<=dtv; j++)
          if (truyvet[j]==xet[dem]) {ok=true; break;}
        if (!ok) dem--;

        dijkstra(mc);
        if (d[c]<=rb) xet[++dem]=mc;

        ok=false;
        for (long j=1; j<=dtv; j++)
          if (truyvet[j]==xet[dem]) {ok=true; break;}
        if (!ok) dem--;

        if (dem==0)
        {
            cout << b << endl;
            continue;
        }
        if (dem==1)
        {
            cout << xet[1] << endl;
            continue;
        }
        else
        {
            dijkstra(a);
            long ans=d[xet[1]],vtri=xet[1];
            for (long j=2; j<=dem;j++)
                if (d[xet[j]]<ans)
                 {
                    ans=d[xet[j]];
                    vtri=xet[j];
                 }
            cout << vtri << endl;
            continue;
        }
    }
}
