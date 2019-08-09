#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long, long> ii;

long long a[nmax],n,ans,nut[nmax],mau[nmax],dd[nmax];
priority_queue <ii> q;
vector <long long> adj[nmax];

void dfs(long u, long cr)
{
    dd[u]=1;
    for (long i=0; i<adj[u].size(); i++)
    {
        long v=adj[u][i];
        if (dd[v]==0)
        {
            mau[v]=1-cr;
            dfs(v,1-cr);
        }
    }
}

void sinhtest(long m)
{
    freopen("a.inp","w",stdout);
    cout << m << '\n';
    srand(time(NULL));
	for (long i=1; i<=m; i++)
      cout << rand()%100+1 << " ";
}

int main()
{
    //sinhtest(100000);
    ios_base::sync_with_stdio(0);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      {
          cin >> a[i];
          nut[i]=a[i];
          q.push(ii(a[i],i));
      }
    while (!q.empty())
    {
        if (q.size()==1)
        {
            ans=q.top().first;
            break;
        }
        long long w1=q.top().first, id1=q.top().second;
        q.pop();
        long long w2=q.top().first, id2=q.top().second;
        q.pop();
        adj[id1].push_back(id2);
        adj[id2].push_back(id1);
        q.push(ii(w1-w2,id1));
    }
    mau[1]=1;
    dfs(1,1);
    cout << ans << '\n';
    for (long i=1; i<=n; i++)
       if (mau[i]) cout << nut[i] << " ";
    cout << '\n';
    for (long i=1; i<=n; i++)
       if (!mau[i]) cout << nut[i] << " ";
}
