#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

struct data
{
    long x,y;
};

long long n,m,ans=0,nv[300007];
data canh[300007];
vector <ii> a[300007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TOURIST.inp","r",stdin);
    freopen("TOURIST.out","w",stdout);
    cin >> n >>m;

    for (long i=1; i<=n; i++) cin >> nv[i];
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >> v;
        canh[i].x=u;
        canh[i].y=v;
        a[u].push_back(ii(nv[v],v));
        a[v].push_back(ii(nv[u],u));
        if (a[u].size()>3)
        {
            sort(a[u].begin(),a[u].end());
            a[u].erase(a[u].begin(),a[u].begin()+1);
        }
        if (a[v].size()>3)
        {
            sort(a[v].begin(),a[v].end());
            a[v].erase(a[v].begin(),a[v].begin()+1);
        }
    }

    long long kq[5];
    kq[1]=-1;kq[2]=-1;kq[3]=-1;kq[4]=-1;
    long maxx=-1,vt;
    for (long i=1; i<=n; i++)
        if (maxx<nv[i])
         {
            maxx=nv[i];
            vt=i;
         }
    long long maxdk=-1;
    if (a[vt].size()==0)
    {
        maxdk=nv[vt];
        kq[1]=vt;
    }

    for (long p=1; p<=m; p++)
    {
        long u=canh[p].x,v=canh[p].y;
        long long sum=nv[u]+nv[v];

        long long maxx=0,vtri1=-1;
        for (long i=0; i<a[v].size(); i++)
        {
            long k=a[v][i].second;
            if (k==u) continue;
            if (maxx<nv[k])
            {
                maxx=nv[k];
                vtri1=k;
            }
        }
        sum+=maxx;

        long long maxxx=0,vtri2=-1;
        for (long i=0; i<a[u].size(); i++)
        {
            long k=a[u][i].second;
            if (k==v || k==vtri1) continue;
            if (maxxx<nv[k])
            {
                maxxx=nv[k];
                vtri2=k;
            }
        }
        sum+=maxxx;

        if (sum>ans && sum>maxdk)
        {
            ans=sum;
            kq[1]=vtri1;
            kq[2]=u;
            kq[3]=v;
            kq[4]=vtri2;
        }
    }
    long sl=0;
    for (long i=1; i<=4; i++)
        if (kq[i]!=-1) sl++;
    cout << sl << endl;
    for (long i=1; i<=4; i++)
        if (kq[i]!=-1) cout << kq[i] << " ";
}
