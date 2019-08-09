#include <bits/stdc++.h>
#define nmax 707

using namespace std;
typedef pair <long,long> ii;

vector <ii> a[nmax*nmax];
long long n,m,d[nmax*nmax];

void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n*m+1,1e9);
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
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MARIO.inp","r",stdin);
    freopen("MARIO.out","w",stdout);
    cin >> n >> m;
    long dem=0;
    for (long i=1; i<=n; i++)
    {
      dem++;
      for (long j=1; j<=m-1; j++)
      {
          dem++;
          long w; cin >> w;
          a[dem-1].push_back(ii(dem,w));
          a[dem].push_back(ii(dem-1,w));
      }
    }
    for (long i=1; i<=n-1; i++)
      {
          dem=1+(i-1)*m;
          for (long j=1; j<=m; j++)
           {
               long w; cin >> w;
               a[dem].push_back(ii(dem+m,w));
               a[dem+m].push_back(ii(dem,w));
               dem++;
           }
      }
      dijkstra();
      cout << d[n*m];
}
