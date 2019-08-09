#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;
typedef pair <long,long> ii;

long n,d[nmax],vtmax,tr[nmax];
bool dd[nmax];
vector <ii> a[nmax];

void dfs(long u)
{
    dd[u]=false;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i].first;
        if (dd[v])
         {
            d[v]=d[u]+a[u][i].second;
            tr[v]=u;
            dfs(v);
         }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("center_node.inp","r",stdin);
    freopen("center_node.out","w",stdout);
    cin >> n;
    for (long i=1; i<n; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
    for (long i=1; i<=n; i++) dd[i]=true;

    dfs(1);
    for (long i=2; i<=n; i++)
      if (d[i]>d[1])
       {
          d[1]=d[i];
          vtmax=i;
       }

    for (long i=1; i<=n; i++) {d[i]=0; dd[i]=true;tr[i]=0;}
    dfs(vtmax);
    long dau=vtmax,cuoi;
    for (long i=1; i<=n; i++)
      if (d[i]>d[vtmax]) {d[vtmax]=d[i]; cuoi=i;}
    long aa[100007],dem=0;
    while (cuoi!=dau)
    {
        aa[++dem]=cuoi;
        cuoi=tr[cuoi];
    }
    aa[++dem]=dau;

    long ans=1000000008,node,vt;
    for (long j=1;j<=dem; j++)
    {
        for (long i=1; i<=n; i++) {d[i]=0; dd[i]=true;}
        dfs(aa[j]);
        long ans1=-1;
        for (long i=1; i<=n; i++)
           if (ans1<d[i]) ans1=d[i];
        //ans=min(ans,ans1);
        if (ans>ans1)
        {
            ans=ans1;
            node=aa[j];
            vt=j;
        }
    }
    cout << ans;
}
