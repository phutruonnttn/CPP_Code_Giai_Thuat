#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,dd[nmax],cur[nmax],s[nmax],bd[nmax],kt[nmax];
vector <long> a[nmax];

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

void dfs(long xp)
{
    for (long i=1; i<=n; i++) dd[i]=cur[i]=0;
    long sn=0,id=0;
    dd[xp]=1;
    s[++sn]=xp;
    bd[xp]=++id;
    while (sn)
    {
        long u=s[sn];
        if (cur[u]<a[u].size())
        {
            long v=a[u][cur[u]++];
            if (dd[v]==0)
            {
                dd[v]=1;
                bd[v]=++id;
                s[++sn]=v;
            }
        }
        else
        {
            kt[u]=id;
            sn--;
        }
    }
}

/*void dfs(long u)
{
    dd[u]=1;
    for (long i=0; i<a[u].size(); ++i)
    {
        long v=a[u][i];
        if (dd[v]==0) dfs(v);
    }
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("dfs.inp","r",stdin);
    freopen("dfs.out","w",stdout);
    doc(n);
    for (long i=1; i<n; i++)
    {
        long long u,v;
        doc(u); doc(v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    cout << dd[n];
}
