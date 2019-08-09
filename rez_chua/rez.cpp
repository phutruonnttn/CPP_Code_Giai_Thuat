/*#include<bits/stdc++.h>
#define nmax 100005
using namespace std;
int n;
long long f[2*nmax],t[2*nmax];
typedef pair<long long,long long> ii;
ii a[2*nmax];
vector <long long> p;
long long get(int x)
{
   long long kq=0;
   while (x>0)
   {
       kq=max(kq,t[x]);
       x-=( x & (-x));
   }
   return kq;
}
void update(int x,long long d)
{
    while (x<=2*nmax)
    {
        t[x]=max(t[x],d);
        x+= (x & (-x));
    }
}
int main()
{
    freopen("rez.inp","r",stdin);
    freopen("rez.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n;i++)
       {
           long long  u,v;
           cin>>u>>v;
           a[i].first=u;
           a[i].second=v;
           p.push_back(u);
           p.push_back(v);
       }
    sort(a+1,a+n+1);
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin());

    long long res=0;
    for (int i=1;i<=n;i++)
    {
        int c=lower_bound(p.begin(),p.end(),a[i].first)-p.begin();
        f[i]=get(c) + a[i].second-a[i].first;
        res=max(res,f[i]);
        int q=lower_bound(p.begin(),p.end(),a[i].second)-p.begin();
        update(q,f[i]);
    }
   cout<<res;
}
*/ //SU DUNG CAY BIT

#include<bits/stdc++.h>
#define nmax 100005
using namespace std;
int n;
typedef pair<long long ,long long> ii;
ii a[nmax];
long long f[nmax],fmaxx[nmax];
int main()
{
    freopen("rez.inp","r",stdin);
    freopen("rez.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[i].first=v;
        a[i].second=u;
    }
    sort(a+1,a+n+1);
    f[1]=a[1].first-a[1].second;
    fmaxx[1]=f[1];
    long long res=f[1];
    for (int i=2;i<=n;i++)
    {
        ii p;
        p.first=a[i].second;
        p.second=999999999;
        int j= upper_bound(a+1,a+i,p)-a-1;
        f[i]=fmaxx[j]+ a[i].first-a[i].second;
        fmaxx[i]=max(fmaxx[i-1],f[i]);
        res=max(res,f[i]);
    }
    cout<<res;

}
