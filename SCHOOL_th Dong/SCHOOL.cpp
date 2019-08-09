#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long, long> ii;

long long m,n,k,d1[nmax],dn[nmax],dk[nmax];
vector <ii> a1[nmax],ak[nmax],an[nmax];

void dijkstra1()
{
    priority_queue <ii> pq;
    fill(d1,d1+n+1,1e9);
    d1[1]=0;
    pq.push(ii(0,1));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d1[u]) continue;
        for (long i=0;i<a1[u].size();i++)
        {
            long v=a1[u][i].first;
            long wv=a1[u][i].second;
            if (d1[v]>d1[u]+wv)
            {
                d1[v]=d1[u]+wv;
                pq.push(ii(-d1[v],v));
            }
        }
    }
}

void dijkstrak()
{
    priority_queue <ii> pq;
    fill(dk,dk+n+1,1e9);
    dk[k]=0;
    pq.push(ii(0,k));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=dk[u]) continue;
        for (long i=0;i<ak[u].size();i++)
        {
            long v=ak[u][i].first;
            long wv=ak[u][i].second;
            if (dk[v]>dk[u]+wv)
            {
                dk[v]=dk[u]+wv;
                pq.push(ii(-dk[v],v));
            }
        }
    }
}

void dijkstran()
{
    priority_queue <ii> pq;
    fill(dn,dn+n+1,1e9);
    dn[n]=0;
    pq.push(ii(0,n));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=dn[u]) continue;
        for (long i=0;i<an[u].size();i++)
        {
            long v=an[u][i].first;
            long wv=an[u][i].second;
            if (dn[v]>dn[u]+wv)
            {
                dn[v]=dn[u]+wv;
                pq.push(ii(-dn[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SCHOOL.inp","r",stdin);
    freopen("SCHOOL.out","w",stdout);
    cin >> n >> m >> k;
    for (long i=1; i<=m; i++)
    {
        long u,v,w1,w2;
        cin >> u >> v >> w1 >> w2;
        a1[u].push_back(ii(v,w2));
        ak[v].push_back(ii(u,w1));
        an[v].push_back(ii(u,w2));
    }
    dijkstra1();
    dijkstrak();
    dijkstran();
    long long ans=99999999999;
    for (long i=1; i<=n; i++)
       if (d1[i]+dk[i]<60) ans=min(ans,d1[i]+dn[i]);
    cout << ans;
}
