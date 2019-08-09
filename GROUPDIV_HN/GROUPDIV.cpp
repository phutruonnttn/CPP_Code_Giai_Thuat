#include <bits/stdc++.h>
#define nmax 300007

using namespace std;

long long n;
int mau[nmax],dd[nmax];
vector <long> a[nmax];
bool ok=true;

void dfs(long u)
{
   if (!ok) return ;

   dd[u]=1;

   long dem=0;
   for (long i=0; i<a[u].size(); i++)
   {
       long v=a[u][i];
       if (mau[v]==mau[u]) dem++;
       if (dd[v]==0)
         if (mau[v]==-1) mau[v]=1-mau[u];
   }
   if (dem>1) ok=false;

   if (!ok) return ;

   for (long i=0; i<a[u].size(); i++)
   {
       long v=a[u][i];
       if (dd[v]==0)
       {
           if (mau[v]==-1) mau[v]=1-mau[u];
           dfs(v);
           if (!ok) return ;
       }
   }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GROUPDIV.inp","r",stdin);
    freopen("GROUPDIV.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        long sl;
        cin >> sl;
        for (long j=1; j<=sl; j++)
        {
            long u;
            cin >> u;
            a[i].push_back(u);
        }
    }
    for (long i=1; i<=n; i++) mau[i]=-1;
    mau[1]=0;
    dfs(1);
    if (!ok) cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        for (long i=1; i<=n; i++)
           if (mau[i]==0) cout << i << " "; cout << '\n';
        for (long i=1; i<=n; i++)
           if (mau[i]!=0) cout << i << " ";
    }
}
