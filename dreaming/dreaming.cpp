#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef  pair <long,long> ii;

struct data
{
    long node,dai;
};

long n,m,l,d[nmax],vtmax,tr[nmax],node,xet[nmax];
data tinh[nmax];
bool dd[nmax],dd1[nmax];
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

void dfs1(long u)
{
    dd1[u]=false;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i].first;
        if (dd1[v]) dfs1(v);
    }
}

bool comp(data p, data q)
{
    if (p.dai!=q.dai) return p.dai > q.dai;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dreaming.inp","r",stdin);
    freopen("dreaming.out","w",stdout);
    cin >> n >> m >> l;
    for (long i=1; i<=m; i++)
    {
        long u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }

    if (n-m==1)
    {
      for (long i=0; i<=n-1; i++) {d[i]=0; dd[i]=true;}
      dfs(0);
      long vtmax=0;
      for (long i=0; i<=n-1; i++)
      if (d[i]>d[0])
       {
          d[0]=d[i];
          vtmax=i;
       }

       for (long i=0; i<=n-1; i++) {d[i]=0; dd[i]=true;}
       dfs(vtmax);
       for (long i=0; i<=n-1; i++)
         if (d[i]>d[vtmax]) d[vtmax]=d[i];

       cout << d[vtmax]; return 0;
    }

    for (long i=0; i<=n-1; i++) {dd[i]=true; dd1[i]=true;}

    long demx=0,demt=0;
    for (long i=0; i<=n-1; i++)
       if (dd1[i]) {xet[++demx]=i; dfs1(i);}

    for (long ii=1; ii<=demx; ii++)
     {
      long tt=xet[ii];
      for (long i=0; i<=n-1; i++) {dd[i]=true; d[i]=0; tr[i]=0;}
      dfs(tt); vtmax=tt;
      for (long i=0; i<=n-1; i++)
       if (d[i]>d[1])
        {
          d[1]=d[i];
          vtmax=i;
        }
      long ans=1000000008;
      if (vtmax==tt) {node=tt; ans=0;}
      else
      {
       for (long i=0; i<=n-1; i++) {d[i]=0; dd[i]=true;tr[i]=0;}
       dfs(vtmax);
       long dau=vtmax,cuoi;
       for (long i=0; i<=n-1; i++)
          if (d[i]>d[vtmax]) {d[vtmax]=d[i]; cuoi=i;}
       long aa[100007],dem=0;
       while (cuoi!=dau)
        {
           aa[++dem]=cuoi;
           cuoi=tr[cuoi];
        }
        aa[++dem]=dau;
           for (long j=1;j<=dem; j++)
            {
            for (long i=0; i<=n-1; i++) {d[i]=0; dd[i]=true;}
            dfs(aa[j]);
            long ans1=-1;
            for (long i=0; i<=n-1; i++)
                if (ans1<d[i]) ans1=d[i];
            if (ans>ans1)
              {
                ans=ans1;
                node=aa[j];
              }
            }
      }
      tinh[++demt].node=node;
      tinh[demt].dai=ans;
    }

    sort(tinh+1,tinh+demt+1,comp);
    for (long i=2; i<=demt; i++)
    {
        long u=tinh[1].node, v=tinh[i].node;
        a[u].push_back(ii(v,l));
        a[v].push_back(ii(u,l));
    }
    for (long i=0; i<=n-1; i++) {d[i]=0; dd[i]=true;}
    dfs(0);
    long vtmax=0;
    for (long i=0; i<=n-1; i++)
      if (d[i]>d[0])
       {
          d[0]=d[i];
          vtmax=i;
       }

    for (long i=0; i<=n-1; i++) {d[i]=0; dd[i]=true;}
    dfs(vtmax);
    for (long i=0; i<=n-1; i++)
      if (d[i]>d[vtmax]) d[vtmax]=d[i];

    cout << d[vtmax];
}
