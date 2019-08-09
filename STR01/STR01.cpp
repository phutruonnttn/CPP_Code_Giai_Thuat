#include <bits/stdc++.h>

using namespace std;
const long long b=379, m=1000000000+7,m2=m*m;

string t;
long long n,nn;
string ss[1007];
long long h[1000007],s[10000007],hashss[1007];
map <string,long> M;

long long get(long long l, long long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STR01.inp","r",stdin);
    freopen("STR01.out","w",stdout);
    cin >> nn >> n;
    cin >> t;
    for (long i=1; i<=n; i++)
    {
        long bo; cin >> bo;
        cin >> ss[i];
    }

    h[0]=1; h[1]=b;
    for (long i=2; i<=nn; i++)
        h[i]=(h[i-1]*b) % m;
    s[0]=(t[0]) % m;
    for (long i=1;i<=nn-1; i++)
        s[i]=((s[i-1]*b)+t[i]) % m;

    for (long i=1; i<=n; i++)
    {
       hashss[i]=ss[i][0];
       for (long j=1; j<=ss[i].size()-1; j++)
          hashss[i]=(hashss[i]*b+ss[i][j]) % m;
    }

    for (long i=1; i<=n; i++)
     {
         long long ans=0;
         long long dd=ss[i].size();
         for (long j=0; j<=nn-1; j++)
           if (t[j]==ss[i][0])
             if (get(j,j+dd-1)==hashss[i]) ans++;
         cout << ans << endl;
     }
}
