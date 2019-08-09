#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,k,cha[nmax],ans=0,dd[nmax],tt[nmax],dem=0,d[4*nmax],aa[nmax];
vector <long> a[nmax];

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 0;
    long mid=(L+R)/2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return x1+x2;
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=aa[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=d[id*2]+d[id*2+1];
}

void dfs(long u)
{
    dd[u]=1;
    aa[u]=1;
    update(1,1,n,u);
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i];
        if (dd[v]==0)
        {
            long long ll=1;
            ans+=get(1,1,n,max(v-k,ll),v+k);
            dfs(v);
        }
    }
    aa[u]=0;
    update(1,1,n,u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PERFECT.inp","r",stdin);
    freopen("PERFECT.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n-1; i++)
    {
        long u,v; cin >> u >> v;
        cha[v]=u;
        a[u].push_back(v);
    }
    for (long i=1; i<=n; i++)
      if (cha[i]==0)
       {
          dfs(i);
          break;
       }
    cout << ans;
}
