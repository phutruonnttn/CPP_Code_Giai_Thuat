#include <bits/stdc++.h>
#define nmax 10007
#define nmod 1000000007

using namespace std;
typedef pair <long,long> ii;

long long n,z[nmax],s[nmax],ss[nmax][nmax],dd[nmax],kt[nmax];
vector <ii> a[nmax];

long long muhai(long long m)
{
    long long res=1;
    for (long i=1; i<=m; i++) res=(res*2)%nmod;
    return res;
}

void dfs(long long u)
{
    dd[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
        long long v=a[u][i].first;
        long long w=a[u][i].second;
        if (dd[v]==0)
        {
            if (w==-1)
              {if (kt[u]==0) kt[v]=1;
               else kt[v]=0;}
            else
            {
               if (kt[u]==0) kt[v]=0;
               else kt[v]=1;
            }
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BINARY.inp","r",stdin);
    freopen("BINARY.out","w",stdout);
    cin >> n;

    for (long i=1; i<=n; i++)
    {
        cin >> z[i];
        if (n<i+z[i]-1)
        {
            cout << 0;
            return 0;
        }
    }

    if (z[1]>0)
    {
        cout << 0;
        return 0;
    }

    for (long i=2; i<=n; i++)
    if (z[i]==-1) continue;
    else
    {
      for (long j=1; j<=z[i]; j++)
      {
          if (ss[j][i+j-1]>=0)
          {
              ss[j][i+j-1]=1;
              ss[i+j-1][j]=1;
              a[j].push_back(ii(i+j-1,1));
              a[i+j-1].push_back(ii(j,1));
          }
          else
          {
              cout << 0;
              return 0;
          }
      }
      if (ss[z[i]+1][i+z[i]]<=0)
      {
          ss[z[i]+1][i+z[i]]=-1;
          ss[i+z[i]][z[i]+1]=-1;
          a[z[i]+1].push_back(ii(i+z[i],-1));
          a[i+z[i]].push_back(ii(z[i]+1,-1));
      }
      else
      {
          cout << 0;
          return 0;
      }
    }
    long long dem=0;
    for (long i=1; i<=n; i++)
      if (dd[i]==0)
      {
         dem++;
         kt[i]=0;
         dfs(i);
      }

    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
      {
          if (ss[i][j]==0) continue;
          if (kt[i]==kt[j] && ss[i][j]==-1)
          {
              cout <<0;
              return 0;
          }
          if (kt[i]!=kt[j] && ss[i][j]==1)
          {
              cout <<0;
              return 0;
          }
      }

    cout << muhai(dem);
}
