#include <bits/stdc++.h>
#define nmax 20007

using namespace std;

string t,p;
long ans=0,dt[20007][20007],dp[nmax],vt[150],kq[2000000];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SUBSTRG.inp","r",stdin);
    freopen("SUBSTRG.out","w",stdout);
    cin >> t;
    cin >> p;
    long n=t.size(), m=p.size();
    for (long i=1; i<=m-1; i++)
    {
        long dem=0; bool ok=false;
        for (long j=i-1; j>=0; j--)
        {
            dem++;
            if (p[j]==p[i]) {ok=true; break;}
        }
        if (ok) dp[i]=dem;
    }

    for (long i=0; i<=n-m; i++)
    {
        for (long j=33; j<=126; j++) vt[j]=-1;
        bool ok=true;
        long dem=-1;
        for (long j=i; j<=i+m-1; j++)
        {
            dem++;
            if (vt[t[j]]==-1)
            {
                if (dp[dem]!=dt[i][dem])
                {
                    ok=false;
                    break;
                }
                vt[t[j]]=0;
            }
            else
            {
                dt[i][dem]=dem-vt[t[j]];
                if (dp[dem]!=dt[i][dem])
                {
                    ok=false;
                    break;
                }
                vt[t[j]]=dem;
            }
        }
        if (ok) kq[++ans]=i;
    }
    cout << ans << endl;
    for (long i=1; i<=ans; i++)
        cout << kq[i]+1 << " ";
}
