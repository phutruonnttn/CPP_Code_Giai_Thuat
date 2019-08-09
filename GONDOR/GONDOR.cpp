#include <bits/stdc++.h>
#define nmax 107

using namespace std;
typedef pair <long, double> ii;
const double pe=0.01;
vector <ii> a[nmax];
vector <long> ke[nmax];
long n,s[nmax],x[nmax],y[nmax];
double d[nmax];

void dijkstra()
{
    fill(d,d+n+1,1e15+7);
    priority_queue <ii> pq;
    d[1]=0;
    pq.push(ii(0,1));

    long u; double du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (abs(du-d[u])>pe) continue;
        for (long i=0; i<a[u].size(); i++)
        {
            long v=a[u][i].first;
            double wv=a[u][i].second;
            if (s[u]<=0) break;
            if (d[v]>d[u]) --s[u];
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
    freopen("GONDOR.inp","r",stdin);
    freopen("GONDOR.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> x[i] >> y[i] >> s[i];
        for (long j=1; j<n; j++)
        {
            long u; cin >> u;
            ke[i].push_back(u);
        }
    }
    for (long i=1; i<=n; i++)
    {
        for (long j=0; j<ke[i].size(); j++)
        {
            long v=ke[i][j];
            double dis=sqrt((x[i]-x[v])*(x[i]-x[v])+(y[i]-y[v])*(y[i]-y[v]));
            a[i].push_back(ii(v,dis));
        }
    }
    dijkstra();
    for (long i=1; i<=n; i++)
       cout << fixed << setprecision(5) << d[i] << '\n';
}
