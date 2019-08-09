#include <bits/stdc++.h>
#define nmax 100007
#define mmax 200007
#define vc 9999999999

using namespace std;
typedef pair <long, long> ii;

long long n,m,dd[nmax],kq[nmax],ui[mmax],vi[mmax],wi[mmax],d[nmax],tr[nmax];
vector <ii> a[nmax],a1[nmax];

void doc(long long &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;
    if (ktAm) n=-n;
}

void dfs(long long u, long long wm)
{
    dd[u]=1;
    for (long i=0; i<a[u].size(); ++i)
    {
        long long v=a[u][i].first;
        long long wv=a[u][i].second;
        if (wv>=wm && dd[v]==0) dfs(v,wm);
    }
}

bool kt(long long h)
{
    memset(dd,0,sizeof(dd));
    dfs(1,h);
    if (dd[n]==1) return true;
    return false;
}

void dijkstra()
{
    priority_queue <ii> pq;
    fill(d,d+n+1,vc);
    d[1]=0;
    pq.push(ii(0,1));

    long long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a1[u].size();i++)
        {
            long long v=a1[u][i].first;
            long long wv=a1[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("transpo.inp","r",stdin);
    freopen("transpo.out","w",stdout);
    doc(n); doc(m);
    for (long i=1; i<=m; ++i)
    {
        doc(ui[i]); doc(vi[i]); doc(wi[i]);
        a[ui[i]].push_back(ii(vi[i],wi[i]));
        a[vi[i]].push_back(ii(ui[i],wi[i]));
    }
    long long l=1, r=10000001,ans=100000000;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (kt(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans << '\n';
    for (long i=1; i<=m; i++)
      if (wi[i]>=ans)
       {
           a1[ui[i]].push_back(ii(vi[i],1));
           a1[vi[i]].push_back(ii(ui[i],1));
       }
    dijkstra();
    cout << d[n]+1 << '\n';
    long long y=n, x=1, dem=0;
    while (y!=x)
    {
        kq[++dem]=y;
        y=tr[y];
    }
    kq[++dem]=x;
    for (long i=dem; i>=1; i--)
        cout << kq[i] << " ";
}
