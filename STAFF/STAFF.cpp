#include <bits/stdc++.h>

using namespace std;
typedef pair <long long, long long> ii;

long long n,m,k,t[7],a[100007],tmp[1000007],tinh[1000007];
vector <ii> qh[100007];
bool dd[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STAFF.inp","r",stdin);
    freopen("STAFF.out","w",stdout);
    cin >> n >> m >> k;
    for (long i=1; i<=n; i++) cin >> a[i];
    for (long i=1; i<=m; i++)
     {
         long u,v,w;
         cin >> u >> v >> w;
         qh[u].push_back(ii(v,w));
         qh[v].push_back(ii(u,w));
     }

    for (long i=1; i<=k; i++)
    {
        cin >> t[i];
        for (long j=1; j<=n; j++) tmp[j]=a[j];
        for (long j=1; j<=n; j++) dd[j]=true;
        long long ans=0;
        bool ok=true;
        while (ok)
        {
            ok=false; bool okk=false;
            long dem=0;
            for (long j=1; j<=n; j++)
              if (dd[j] && tmp[j]>t[i])
                {
                    tinh[++dem]=j;
                    dd[j]=false;
                    ok=true;
                    ans++;
                }
            for (long j=1; j<=n; j++)
              if (dd[j]) {okk=true; break;}
            if (!okk) break;
            for (long j=1; j<=dem; j++)
               for (long jj=0; jj<qh[tinh[j]].size(); jj++)
                 tmp[qh[tinh[j]][jj].first]+=qh[tinh[j]][jj].second;
        }
        cout << ans << " ";
    }
}
