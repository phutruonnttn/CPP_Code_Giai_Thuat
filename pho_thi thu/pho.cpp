#include <bits/stdc++.h>
#define nmax 100007
#define vc 9999999999

using namespace std;
typedef pair <long long,long long> ii;

long long n,m,ct[nmax],d[nmax],den[nmax],daxoa[nmax],cp[nmax],dd[nmax],s,ss[nmax],uu[nmax],vv[nmax],cur[nmax],h[nmax];
vector <long long> a[nmax],a2[nmax];
vector <ii> a1[nmax];

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

void dijkstra(long long uu)
{
    priority_queue <ii> pq;
    fill(d,d+n+1,vc);
    d[uu]=0;
    pq.push(ii(0,uu));

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
                pq.push(ii(-d[v],v));
            }
        }
    }
}

void dfs(long xp)
{
    for (long i=1; i<=n; i++) dd[i]=cur[i]=0;
    long sn=0,id=0;
    dd[xp]=1;
    h[xp]=0;
    ss[++sn]=xp;
    while (sn)
    {
        long u=ss[sn];
        if (cur[u]<a[u].size())
        {
            long v=a[u][cur[u]++];
            if (dd[v]==0)
            {
                dd[v]=1;
                h[v]=h[u]+1;
                ss[++sn]=v;
            }
        }
        else sn--;
    }
}

void sub1()
{
     dijkstra(ct[1]);
     cout << d[ct[2]];
}

void sub2()
{
    while (1<2)
     {
        bool ok=false;
        for (long i=1; i<=n; i++)
          if (daxoa[i]==0 && den[i]==1 && cp[i]==0)
            {
               den[i]--;
               ok=true;
               daxoa[i]=1;
               for (long j=0; j<a[i].size(); ++j)
                 if (!daxoa[a[i][j]]) den[a[i][j]]--;
            }
         if (!ok) break;
     }
     //for (long i=1; i<=n; i++) if (cp[i]==1) cout << i << " " << den[i] << endl;

     s=0;
     long dl;
     for (long i=1; i<n; ++i)
       if (!daxoa[uu[i]] && !daxoa[vv[i]])
       {
           s++;
           dl=vv[i];
           a2[uu[i]].push_back(vv[i]);
           a2[vv[i]].push_back(uu[i]);
       }
     s*=2;
     dfs(dl);
     long long dmax=-1,dnho;
     for (long i=1; i<=n; i++)
        if (h[i]>dmax)
        {
            dmax=h[i];
            dnho=i;
        }
     dfs(dnho);
     long long t=-1;
     for (long i=1; i<=n; i++) t=max(t,h[i]);
     cout << s-t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("pho.inp","r",stdin);
    freopen("pho.out","w",stdout);
    doc(n); doc(m);
    for (long i=1; i<=m; ++i)
        {
            doc(ct[i]);
            ct[i]++;
            cp[ct[i]]=1;
        }
    for (long i=1; i<n; ++i)
    {
        doc(uu[i]); doc(vv[i]);
        uu[i]++; vv[i]++;
        den[uu[i]]++; den[vv[i]]++;
        a[uu[i]].push_back(vv[i]);
        a[vv[i]].push_back(uu[i]);
        a1[uu[i]].push_back(ii(vv[i],1));
        a1[vv[i]].push_back(ii(uu[i],1));
    }
    if (m==2) sub1();
    else sub2();
}
