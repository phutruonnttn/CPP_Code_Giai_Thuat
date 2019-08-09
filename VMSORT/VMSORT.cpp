#include <bits/stdc++.h>

using namespace std;

long k,n,dem=0; string s;
map <string,int> M;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VMSORT.inp","r",stdin);
    freopen("VMSORT.out","w",stdout);
    cin >> k;
    for (long i=1; i<=k; i++)
    {
        cin >> n;
        for (long j=1; j<=n; j++)
        {
            cin >> s;
            if (M[s]!=81) dem++;
            M[s]=81;
        }
    }
    cout << dem;
}
