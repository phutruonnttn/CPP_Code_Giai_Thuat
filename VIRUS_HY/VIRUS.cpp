/*#include <bits/stdc++.h>
#define nmax 10007

using namespace std;

long long n,a[nmax],b[nmax],tt1,tt2,qh[nmax][nmax],ans=0;
vector <long> ad1[nmax],ad2[nmax];

void dfs1(long u,long l)
{
    for (long i=0; i<ad1[u].size(); i++)
    {
        long v=ad1[u][i];
        qh[l][v]=1;
        dfs1(v,l);
    }
}

void dfs2(long u,long l)
{
    for (long i=0; i<ad2[u].size(); i++)
    {
        long v=ad2[u][i];
        if (qh[l][v]==1) ans++;
        dfs2(v,l);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VIRUS.inp","r",stdin);
    freopen("VIRUS.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
       cin >> a[i];
       if (a[i]==0) {tt1=i; continue;}
       ad1[a[i]].push_back(i);
    }
    for (long i=1; i<=n; i++)
    {
       cin >> b[i];
       if (b[i]==0) {tt2=i; continue;}
       ad2[b[i]].push_back(i);
    }
    for (long i=1; i<=n; i++) dfs1(i,i);
    for (long i=1; i<=n; i++) dfs2(i,i);

    cout << ans;
}*/


#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,a[nmax],b[nmax],tt1,tt2,ans=0,in[nmax],out[nmax],x[2*nmax],t[3*nmax],cnt=0;
vector <long> ad1[nmax],ad2[nmax];

void dfs1(long u)
{
    in[u]=++cnt;
    x[cnt]=u;
    for (long i=0; i<ad1[u].size(); i++)
    {
        long v=ad1[u][i];
        dfs1(v);
    }
    out[u]=++cnt;
    x[cnt]=u;
}

long long get(long x)
{
    long long res=0;
    while (x>0)
    {
       res+=t[x];
       x-=(x&-x);
    }
    return res;
}

void update(long x, long d)
{
    while (x<2*nmax)
    {
        t[x]+=d;
        x+=(x&-x);
    }
}

void dfs2(long u)
{
    ans+=get(in[u]);
    update(in[u]+1,1);
    update(out[u],-1);
    for (long i=0; i<ad2[u].size(); i++)
    {
        long v=ad2[u][i];
        dfs2(v);
    }
    update(in[u]+1,-1);
    update(out[u],1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VIRUS.inp","r",stdin);
    freopen("VIRUS.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
       cin >> a[i];
       if (a[i]==0) {tt1=i; continue;}
       ad1[a[i]].push_back(i);
    }
    for (long i=1; i<=n; i++)
    {
       cin >> b[i];
       if (b[i]==0) {tt2=i; continue;}
       ad2[b[i]].push_back(i);
    }
    dfs1(tt1);
    dfs2(tt2);
    cout << ans;
    //for (long i=1; i<=2*n; i++) cout << x[i] << " ";
}
