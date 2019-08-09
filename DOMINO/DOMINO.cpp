#include <bits/stdc++.h>
#define nmax 57

using namespace std;
typedef pair <long, long> ii;

struct data
{
    long long tr,du;
};

long long n,sum=0,x[nmax],ans=99999999,kq[nmax],dem=0,tong[507],demd[507];
vector <ii> tr[507];
data quan[nmax];

bool cmp(data q, data p)
{
    if (q.tr!=p.tr) return q.tr > p.tr;
    return q.du < p.du;
}

void kt()
{
    long long tinh=0,d1=0;
    for (long i=1; i<=n; i++)
      if (x[i]==0) tinh+=quan[i].tr;
      else
      {
          d1++;
          tinh+=quan[i].du;
      }
    if (ans==abs(sum-tinh*2))
      if (d1<dem)
      {
        dem=0;
        for (long i=1; i<=n; i++)
          if (x[i]==1) kq[++dem]=i;
      }
    if (ans>abs(sum-tinh*2))
    {
        ans=abs(sum-tinh*2);
        dem=0;
        for (long i=1; i<=n; i++)
          if (x[i]==1) kq[++dem]=i;
    }
}

void tryy(long i)
{
    for (long j=0; j<=1; j++)
    {
        x[i]=j;
        if (i==n) kt();
        else tryy(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DOMINO.inp","r",stdin);
    freopen("DOMINO.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> quan[i].tr; sum+=quan[i].tr;}
    for (long i=1; i<=n; i++) {cin >> quan[i].du; sum+=quan[i].du;}
    if (n<=20)
    {
        tryy(1);
        cout << ans << " " << dem << '\n';
        for (long i=1; i<=dem; i++) cout << kq[i] << " ";
        return 0;
    }
    tong[quan[1].tr]=1;
    tong[quan[1].du]=1;
    for (long i=2; i<=n; i++)
    {
        for (long j=500; j>=0; j--)
          if (tong[j]>0)
          {
              tong[j+quan[i].tr]=max(tong[j+quan[i].tr],tong[j]+1);
              tong[j+quan[i].du]=max(tong[j+quan[i].du],tong[j]+1);
          }
    }
    long long vv;
    for (long i=1; i<=500; i++)
        if (tong[i]==n)
        {
           if (ans>abs(sum-2*i))
           {
               ans=abs(sum-2*i);
               vv=i;
           }
        }
    cout << ans << '\n';
    memset(tong,0,sizeof(0));
    tong[quan[1].tr]=1;
    tr[quan[1].tr].push_back(ii(1,1));
    if (tong[quan[1].du]!=1)
    {
       tong[quan[1].du]=1;
       demd[quan[1].du]=1;
       tr[quan[1].du].push_back(ii(1,2));
    }
    for (long i=2; i<=n; i++)
    {
        for (long j=500; j>=0; j--)
          if (tong[j]>0)
          {
              /*if (tong[j]+1==tong[j+quan[i].tr] && demd[j]<demd[j+quan[i].tr])
              {
                  tong[j+quan[i].tr]=tong[j]+1;
                  demd[j+quan[i].tr]=demd[j];
                  tr[j+quan[i].tr]=tr[j];
                  tr[j+quan[i].tr].push_back(ii(i,1));
              }*/
              if (tong[j]+1>tong[j+quan[i].tr])
              {
                  tong[j+quan[i].tr]=tong[j]+1;
                  demd[j+quan[i].tr]=demd[j];
                  tr[j+quan[i].tr]=tr[j];
                  tr[j+quan[i].tr].push_back(ii(i,1));
              }
              //tong[j+quan[i].tr]=max(tong[j+quan[i].tr],tong[j]+1);
              //----------------------------------------------------
              /*if (tong[j]+1==tong[j+quan[i].du] && demd[j]+1<demd[j+quan[i].du])
              {
                  tong[j+quan[i].du]=tong[j]+1;
                  demd[j+quan[i].du]=demd[j]+1;
                  tr[j+quan[i].du]=tr[j];
                  tr[j+quan[i].du].push_back(ii(i,2));
              }*/
              if (tong[j]+1>tong[j+quan[i].du])
              {
                  tong[j+quan[i].du]=tong[j]+1;
                  demd[j+quan[i].du]=demd[j]+1;
                  tr[j+quan[i].du]=tr[j];
                  tr[j+quan[i].du].push_back(ii(i,2));
              }
              //tong[j+quan[i].du]=max(tong[j+quan[i].du],tong[j]+1);
          }
    }
    /*cout << tr[vv].size() << endl;
    for (long i=0; i<tr[vv].size(); i++) cout << tr[vv][i].first << " " << tr[vv][i].second << endl;*/
}
