#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long long,long long> ii;

long long n,m,p[nmax],d[nmax],tr[nmax],sl[nmax],ans1=1e10,ans2=-1,d1[nmax],dn[nmax];
vector <ii> a[nmax];
bool dd[nmax],danhdau[nmax];

void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n+1,1e10);
    d[1]=0;
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

void dijkstra1()
{
    priority_queue <ii> pq;
    fill(d1,d1+n+1,1e10);
    d1[1]=0;
    pq.push(ii(0,1));

    long long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d1[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long long v=a[u][i].first;
            long long wv=a[u][i].second;
            if (d1[v]>d1[u]+wv)
            {
                d1[v]=d1[u]+wv;
                pq.push(ii(-d1[v],v));
            }
        }
    }
}

void dijkstran()
{
    priority_queue <ii> pq;
    fill(dn,dn+n+1,1e10);
    dn[n]=0;
    pq.push(ii(0,n));

    long long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=dn[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long long v=a[u][i].first;
            long long wv=a[u][i].second;
            if (dn[v]>dn[u]+wv)
            {
                dn[v]=dn[u]+wv;
                pq.push(ii(-dn[v],v));
            }
        }
    }
}

void dfs3(long u,long sum,long dodai)
{
    if (u==n && dodai==ans1 && sum>ans2) ans2=sum;
    dd[u]=false;
    for (long i=0; i<a[u].size(); i++)
    {
        long long v=a[u][i].first;
        if (!danhdau[v]) continue;
        if (dd[v]) dfs3(v,sum+p[v],dodai+a[u][i].second);
    }
    dd[u]=true;
}

void sub3()
{
    dijkstra1(); dijkstran();
    memset(dd,true,sizeof(dd));
    memset(danhdau,false,sizeof(danhdau));
    for (long i=1; i<=n; i++)
      if (d1[i]+dn[i]==d1[n]) danhdau[i]=true;
    dfs3(1,p[1],0);
    cout << ans1 << " " << ans2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VO17PHD.inp","r",stdin);
    freopen("VO17PHD.out","w",stdout);
    cin >> n;
    bool ok=true;
    for (long i=1; i<=n; i++)
    {
        cin >> p[i];
        if (p[i]!=0) ok=false;
    }
    cin >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v,c;
        cin >> u >> v >> c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }
    if (ok)
    {
       dijkstra();
       if (d[n]==1e10) cout << "impossible";
       else
        {
            cout << d[n] << " " << 0;
        }
       return 0;
    }
    memset(sl,0,sizeof(sl));
    sl[1]=1;
    dijkstra();
    if (sl[n]==1)
    {
        cout << d[n] << " ";
        long long ans=0,nn=n;
        while (nn!=1)
        {
            ans+=p[nn];
            nn=tr[nn];
        }
        ans+=p[1];
        cout << ans;
        return 0;
    }
    if (d[n]==1e10)
    {
        cout << "impossible";
        return 0;
    }
    long long nn=n;
    ans1=d[n]; ans2=0;
    while (nn!=1)
    {
        ans2+=p[nn];
        nn=tr[nn];
    }
    ans2+=p[1];
    sub3();
}
