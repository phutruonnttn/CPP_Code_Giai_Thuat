#include <bits/stdc++.h>
#define nmax 15007

using namespace std;

long long n,dd[nmax],mau[nmax],ans1=0,ans2=0;
string s;
vector <long long> a[nmax];

void dfs(long u)
{
    dd[u]=1;
    if (a[u].size()==1)
    {
        long v=a[u][0];
        if (mau[u]==1) mau[v]=2;
        else if (mau[u]==0) mau[v]=2;
        else mau[v]=0;
        if (dd[v]==0) dfs(v);
    }
    else if (a[u].size()==2)
    {
        long v1=a[u][0], v2=a[u][1];
        if (mau[u]==1)
        {
            mau[v1]=0; mau[v2]=2;
            if (dd[v1]==0) dfs(v1);
            if (dd[v2]==0) dfs(v2);
        }
        else
        {
          if (a[v1].size()==0 && a[v2].size()==0)
          {
            if (mau[u]==1)
            {
                mau[v1]=0;
                mau[v2]=2;
                if (dd[v1]==0) dfs(v1);
                if (dd[v2]==0) dfs(v2);
            }
            else
            {
                mau[v1]=1;
                mau[v2]=2-mau[u];
                if (dd[v1]==0) dfs(v1);
                if (dd[v2]==0) dfs(v2);
            }
          }
          else if (a[v1].size()==0)
          {
              mau[v1]=2-mau[u];
              mau[v2]=1;
              if (dd[v1]==0) dfs(v1);
              if (dd[v2]==0) dfs(v2);
          }
          else if (a[v2].size()==0)
          {
              mau[v2]=2-mau[u];
              mau[v1]=1;
              if (dd[v1]==0) dfs(v1);
              if (dd[v2]==0) dfs(v2);
          }
          else
          {
              mau[v1]=2-mau[u];
              mau[v2]=1;
              if (dd[v1]==0) dfs(v1);
              if (dd[v2]==0) dfs(v2);
          }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TRO.inp","r",stdin);
    freopen("TRO.out","w",stdout);
    cin >> s;
    n=s.size();
    s='*'+s;
    long i;
    for (i=1; i<=n; i++)
    {
       if (s[i]=='1')
       {
           for (long j=i+1; j<=n; j++)
             if (dd[j]==0)
               {
                   a[i].push_back(j);
                   dd[j]=1;
                   break;
               }
       }
       else if (s[i]=='2')
       {
           long dem=0;
           for (long j=i+1; j<=n; j++)
             if (dd[j]==0)
               {
                   a[i].push_back(j);
                   dd[j]=1;
                   dem++;
                   if (dem==2) break;
               }
       }
    }
    //0: den
    //1: do
    //2: trang
    memset(dd,0,sizeof(dd));
    mau[1]=0;
    dfs(1);
    for (long i=1; i<=n; i++) //cout << mau[i] << " ";
       if (mau[i]==1) ans2++;
    cout << ans1 << " " << ans2;
}
