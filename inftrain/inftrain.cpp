#include <bits/stdc++.h>
#define nmax 300007

using namespace std;
typedef pair <long long,long long> ii;
typedef pair <long long, ii> ii2;

struct data
{
    long long a,b,id;
};

long long m,n,s[nmax],c[nmax],kq[nmax],dem;
data hk[nmax];
priority_queue <ii> pq;
ii2 event[nmax];
bool dd[nmax];

bool comp(data q, data p)
{
    if (q.a!=p.a) q.a < p.a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("inftrain.inp","r",stdin);
    freopen("inftrain.out","w",stdout);
    cin >> n >> m;
    dem=0;
    for (long i=1; i<=n; i++) cin >> s[i] >> c[i];
    for (long i=1; i<=m; i++)
    {
        cin >> hk[i].a >> hk[i].b;
        hk[i].id=i;
        event[++dem]=make_pair(hk[i].a,make_pair(i,1));
        event[++dem]=make_pair(hk[i].b,make_pair(i,-1));
    }
    sort(event+1,event+dem+1);
    //cout << event[1].first << " " <<event[1].second.first << " " << event[1].second.second << endl;

    if (n==1)
    {
       memset(dd,false,sizeof(dd));
       long long t=0,ans=0;
       for (long i=1; i<=dem; i++)
       {
           if (event[i].first>s[1] && event[i].second.second==1) continue;
           if (event[i].first>s[1] && event[i].second.second==-1) continue;
           if (event[i].second.second==-1)
           {
               if (dd[event[i].second.first])
               {t--; ans++;
               kq[event[i].second.first]=1;}
           }
           else
           {
              if (t<c[1])
              {
                 t++;
                 pq.push(ii(event[i].second.first,hk[event[i].second.first].b));
                 dd[event[i].second.first]=true;
              }
              else
              {
                 long long tmp=pq.top().second, vt=pq.top().first;
                 if (tmp>hk[event[i].second.first].b)
                 {
                   dd[vt]=false;
                   dd[event[i].second.first]=true;
                   pq.pop();
                   pq.push(ii(event[i].second.first,hk[event[i].second.first].b));
                 }
               }

            }
       }
       cout << ans << endl;
       for (long i=1; i<=m; i++) cout << kq[i] << endl;
    }
}
