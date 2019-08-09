#include <bits/stdc++.h>
using namespace std;

struct data
{
    long long x,y;
};

typedef pair <long long,double> ii;
typedef pair <double,long> iii;

vector <ii> a[50007];
data diem[1007];
long long n,w;
double d[5007],M;
bool dd[1007][1007];

void dijkstra()
{
    priority_queue <iii> pq;
    fill(d,d+n+1,1e10);
    d[1]=0;
    pq.push(iii(0,1));

    long long u; double du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=0;i<a[u].size();i++)
        {
            long long v=a[u][i].first;
            double wv=a[u][i].second;
            if (d[v]>d[u]+wv)
            {
                d[v]=(double)d[u]+(double)wv;
                pq.push(iii(-d[v],v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PWRFAIL.inp","r",stdin);
    freopen("PWRFAIL.out","w",stdout);
    cin>>n>>w;
    cin >> M;
    for (long i=1;i<=n; i++)
    {
        cin >> diem[i].x >>diem[i].y;
    }
    memset(dd,false,sizeof(dd));
    for (long i=1; i<=w; i++)
    {
        long long u,v;
        cin >> u >>v;
        dd[u][v]=true;
        dd[v][u]=true;
        a[u].push_back(ii(v,0));
        a[v].push_back(ii(u,0));
    }

    for (long i=1; i<=n-1; i++)
      for (long j=i+1; j<=n; j++)
       if (!dd[i][j])
       {
          double dodai=(double)sqrt((diem[i].x-diem[j].x)*(diem[i].x-diem[j].x)+(diem[i].y-diem[j].y)*(diem[i].y-diem[j].y));
          if (dodai<=M) {a[i].push_back(ii(j,dodai)); a[j].push_back(ii(i,dodai));/*cout <<i << " " <<j << " " << dodai<< endl;*/}

       }

    dijkstra();
    if (d[n]==1e10) cout<<-1;
    else cout <<(long long)(d[n]*1000);
}
