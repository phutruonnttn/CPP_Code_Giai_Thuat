#include <bits/stdc++.h>
#define vc 9999999999
#define nmax 100007

using namespace std;
typedef pair <long long,long long> ii;

vector <ii> a[nmax],a1[nmax];
long long x,y,ans,n,m,k,s1,s2,t,nu[nmax],nv[nmax],w1[nmax],w2[nmax],tr[nmax],d[nmax],res[nmax],d2[nmax],kq[nmax];
map <ii,long> M;
int kt[10000][10000];

void dijkstra1(long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,vc);
    d[uu]=0;
    pq.push(ii(0,uu));

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
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

void dijkstra2(long uu)
{
    priority_queue <ii> pq;
    fill(d2,d2+n+1,vc);
    d2[uu]=0;
    pq.push(ii(0,uu));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d2[u]) continue;
        for (long i=0;i<a1[u].size();i++)
        {
            long v=a1[u][i].first;
            long wv=a1[u][i].second;
            if (d2[v]>d2[u]+wv)
            {
                d2[v]=d2[u]+wv;
                pq.push(ii(-d2[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("HACK.inp","r",stdin);
    freopen("HACK.out","w",stdout);
    cin >> n >> m >> k >> s1 >> s2 >> t;
    for (long i=1; i<=m; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a1[u].push_back(ii(v,w));
    }
    for (long i=1; i<=k; i++)
    {
        cin >> nu[i] >> nv[i] >> w1[i] >> w2[i];
        a[nu[i]].push_back(ii(nv[i],min(w1[i],w2[i])));
    }
    dijkstra1(s1);
  if (d[t]!=vc)
  {
    x=s1,y=t;
    ans=0;
    while (y!=x)
    {
        kq[++ans]=y;
        y=tr[y];
    }
    kq[++ans]=x;
    for (long i=ans; i>=2; i--) kt[kq[i]][kq[i-1]]=1;
        //M[ii(kq[i],kq[i-1])]=1;
  }
    for (long i=1; i<=k; i++)
       //if (M[ii(nu[i],nv[i])]==1)
       if (kt[nu[i]][nv[i]]==1)
           {
               a1[nu[i]].push_back(ii(nv[i],min(w1[i],w2[i])));
               res[i]=min(w1[i],w2[i]);
           }
       else
       {
           a1[nu[i]].push_back(ii(nv[i],max(w1[i],w2[i])));
           res[i]=max(w1[i],w2[i]);
       }
    dijkstra2(s2);
    if (d2[t]<d[t]) cout << "LOSE";
    else if (d2[t]>d[t])
    {
        cout << "WIN" << '\n';
        for (long i=1; i<=k; i++) cout << res[i] << " ";
    }
    else
    {
        cout << "DRAW" << '\n';
        for (long i=1; i<=k; i++) cout << res[i] << " ";
    }
}
