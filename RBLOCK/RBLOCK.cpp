#include <bits/stdc++.h>
#define vc 10000000000

using namespace std;

long n,m,d[50007],tr[50007],sl[50007],duongdi[50007],k;
typedef pair <long,long> ii;
vector <ii> a[50007];

void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[1]=0;
    pq.push(ii(0,1));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long v=a[u][i].first;
            long wv=a[u][i].second;
            if (d[v]==d[u]+wv) sl[v]=sl[v]+sl[u];
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                sl[v]=sl[u];
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RBLOCK.inp","r",stdin);
    freopen("RBLOCK.out","w",stdout);
    cin >> n >> m; k=n;

    memset(sl,0,sizeof(sl));
    sl[1]=1;

    for (long i=1;i<=m;i++)
    {
        long u,v,w;
        cin >>u>>v>>w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    };
    dijkstra();
    long ans1=d[n];
    long ans=0;

    long dd=0;
    while (k!=1)
    {
        duongdi[++dd]=k;
        k=tr[k];
    }
    duongdi[++dd]=1;

    for (long i=1; i<=dd-1; i++)
     {
         long u=duongdi[i], v=duongdi[i+1],csu,csv;
         for (long j=0; j<=a[u].size(); j++)
         {
             long uu=a[u][j].first;
             if (uu==v)
             {
                 csu=j;
                 break;
             }
         }

         for (long j=0; j<=a[v].size(); j++)
         {
             long vv=a[v][j].first;
             if (vv==u)
             {
                 csv=j;
                 break;
             }
         }
         a[u][csu].second*=2;
         a[v][csv].second*=2;

         dijkstra();
         ans=max(ans,d[n]-ans1);


         a[u][csu].second/=2;
         a[v][csv].second/=2;
     }
     cout << ans;
}
