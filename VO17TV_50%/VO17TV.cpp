#include <bits/stdc++.h>

using namespace std;

long k,n,ans=-1;
string s[107];
map <string, long> M,M1;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VO17TV.inp","r",stdin);
    freopen("VO17TV.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) cin >> s[i];
    for (long i=1; i<=n; i++)
    {
        M1.clear();
        for (long j=0; j<=s[i].size()-1; j++)
        {
            string tmp="";
            for (long kk=j; kk<=s[i].size()-1; kk++)
            {
                tmp=tmp+s[i][kk];
                if (M1[tmp]==0)
                  {
                    M[tmp]++;
                    M1[tmp]=1;
                    long ss=tmp.size();
                    if (M[tmp]>=k && ss>ans) ans=tmp.size();
                  }
            }
        }
    }
    cout << ans;
}
