#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long dd[nmax],nb,ip[nmax],a[nmax][nmax],ma[nmax],b[nmax],t[nmax],iq[nmax],n,m,start,fi;
queue <long> qu;

void ktaoBFS()
{
    while (!qu.empty()) qu.pop();
    qu.push(start); fi=0;
    memset(iq,0,sizeof(iq));
    iq[start]=1;
    memset(t,0,sizeof(t));
    for (long i=1; i<=n; i++) b[i]=i;
}

long long timnut(long p, long q)
{
    memset(ip,0,sizeof(ip));
    while (true)
    {
        p=b[p];
        ip[p]=1;
        if (p==start) break;
        p=t[ma[p]];
    }
    while (true)
    {
        q=b[q];
        if (ip[q]) break;
        q=t[ma[q]];
    }
    return q;
}

void reset(long x)
{
    long v=x;
    while (b[v]!=nb)
    {
        long u=ma[v];
        dd[b[v]]=1;
        dd[b[u]]=2;
        v=t[u];
        if (b[v]!=nb) t[v]=u;
    }
}

void blossom(long p, long q)
{
    memset(dd,0,sizeof(dd));
    nb=timnut(p,q);
    reset(p); reset(q);
    if (b[p]!=nb) t[p]=q;
    if (b[q]!=nb) t[q]=p;
    for (long i=1; i<=n; i++)
      if (dd[b[i]]) b[i]=nb;
    for (long i=1; i<=n; i++)
      if (!iq[i] && b[i]==nb)
      {
         qu.push(i);
         iq[i]=1;
      }
}

void duongmo()
{
    ktaoBFS();
    while (!qu.empty())
    {
        long u=qu.front();
        qu.pop();
        for (long v=1; v<=n; v++)
           if (a[u][v] && ma[u]!=v && b[u]!=b[v])
             if ((v==start || ma[v]!=0) && t[ma[v]]!=0)
               blossom(u,v);
           else
              if (t[v]==0)
                if (ma[v]==0)
                  {
                      t[v]=u;
                      fi=v;
                      return ;
                  }
                else
                  {
                     t[v]=u;
                     qu.push(ma[v]);
                     iq[ma[v]]=1;
                  }
    }
}

void noirong()
{
    while (fi!=0)
    {
        long v=t[fi];
        long next=ma[v];
        ma[v]=fi;
        ma[fi]=v;
        fi=next;
    }
}

void solve()
{
    for (long u=1; u<=n; u++)
        if (ma[u]==0)
         {
            start=u;
            duongmo();
            if (fi!=0) noirong();
         }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("gmatch.inp","r",stdin);
    freopen("gmatch.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        a[u][v]=1;
        a[v][u]=1;
    }
    solve();
    for (long u=1; u<=n; u++)
      if (ma[u]>u)
       cout << u << " " << ma[u] << '\n';
}
