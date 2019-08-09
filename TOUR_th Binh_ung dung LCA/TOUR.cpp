#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

long long n,h[nmax],par[nmax][27],q,k,s[nmax],bd[nmax],kt[nmax],id=0,dd[nmax],cl[nmax],cur[nmax],ss[nmax];
vector <long> a[nmax];

/*void dfs(long u)
{
   //tinh h(chieu cao) cua tung nut, va par[u][i] la nut cha 2^i cua u
   bd[u]=++id;
   for (long i = 0; i < a[u].size(); i++)
    {
        long v=a[u][i];
        if (v!=par[u][0])
        {
            par[v][0]=u; h[v]=h[u]+1;
            for (long j=1; j<=17; j++)
                par[v][j]=par[par[v][j-1]][j-1];
            dfs(v);
        }
    }
   kt[u]=id;
}*/

// can su dung dfs khu de quy de full
void dfs(int xp)
{
    for(int i=1;i<=n;i++) cl[i]=cur[i]=0;
    int sn=0, id=0;
    cl[xp]=1; ss[++sn]=xp; h[xp]=0; par[xp][0]=0;
    bd[xp]=++id;
    while (sn)
    {
        int u=ss[sn];
        if (cur[u]<a[u].size())
        {
            int v=a[u][cur[u]++];
            if (cl[v]==0)
            {
                cl[v]=1; ss[++sn]=v; h[v]=h[u]+1; par[v][0]=u;
                bd[v]=++id;
            }
        }
        else
        {
            kt[u]=id;
            sn--;
        }
    }
    for(int k=1;k<=17;k++)
       for(int u=1;u<=n;u++) par[u][k]=par[par[u][k-1]][k-1];
}

long LCAs(long u, long v)
{
    //nhay 2 nut ve cung do cao
    if (h[u]<h[v]) swap(u,v);
    long del=h[u]-h[v];
    for (long i=0; i<=17; i++)
        if ((del >> i )& 1) u=par[u][i];
    if (u==v) return u;

    //nhay len dan,neu gap 2 nut cung nhau thi ko nhay, khac nhau moi nhay
    for (long i=17; i>=0 ; i--)
      if (par[u][i]!=par[v][i])
        {
          u=par[u][i];
          v=par[v][i];
        }
    return par[u][0];
}

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

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TOUR.inp","r",stdin);
    freopen("TOUR.out","w",stdout);
    doc(n);
    for (long i=1; i<n; ++i)
     {
        long long u,v;
        doc(u); doc(v);
        a[u].push_back(v);
        a[v].push_back(u);
     }
    dfs(1);
    doc(q);
    while (q--)
    {
        doc(k);
        long sn,nn,hmin=n+1,hm=-1;
        for (long i=1; i<=k; ++i)
          {
              doc(s[i]);
              if (h[s[i]]>hm)
              {
                  hm=h[s[i]];
                  sn=s[i];
              }
              if (h[s[i]]<hmin)
              {
                  hmin=h[s[i]];
                  nn=s[i];
              }
              dd[i]=0;
          }
       long dem=0;
       for (long i=1; i<=k; i++)
        if (bd[s[i]]<=bd[sn] && kt[s[i]]>=kt[sn])
          {
             dd[i]=1;
             dem++;
          }
       if (dem==k) printf("Yes\n");
       else
       {
            long sn1,hm=-1;
            for (long i=1; i<=k; i++)
              if (dd[i]==0 && h[s[i]]>hm)
               {
                   hm=h[s[i]];
                   sn1=s[i];
               }
            for (long i=1; i<=k; i++)
              if (dd[i]==0 && bd[s[i]]<=bd[sn1] && kt[s[i]]>=kt[sn1])
               {
                   dd[i]=1;
                   dem++;
               }
            if (dem!=k) printf("No\n");
            else
            {
                long w1=LCAs(sn,sn1);
                if (bd[w1]<=bd[nn] && kt[w1]>=kt[nn]) printf("Yes\n");
                else printf("No\n");
            }
       }
    }
}
