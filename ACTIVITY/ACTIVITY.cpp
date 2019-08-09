#include <bits/stdc++.h>

using namespace std;

long long t,a,b,n,m,k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ACTIVITY.inp","r",stdin);
    freopen("ACTIVITY.out","w",stdout);
    cin >> t;
    for (long i=1; i<=t; i++)
    {
        cin >> m >> n >> k >> a >> b;
        long long kk=min(m/a,n/b);
        long long thu=m-a*kk+n-b*kk;
        if (thu>=k) cout << kk << endl;
        else
        {
           while (thu<k)
           {
            kk--;
            thu=m-a*kk+n-b*kk;
           }
           cout << kk << endl;
        }
    }
}
