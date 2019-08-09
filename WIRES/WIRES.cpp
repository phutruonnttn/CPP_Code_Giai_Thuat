#include <bits/stdc++.h>

using namespace std;

long n,a[1007],f[1007],tr[1007];
vector <long> s[1007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("WIRES.inp","r",stdin);
    freopen("WIRES.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i]; s[i].push_back(a[i]);}
    a[0]=0; a[n+1]=1007;
    f[n+1]=1;
    long dem=0;
    for (long i=n; i>=0; i--)
    {
        long vt,fmax=0;
        for (long j=i+1; j<=n+1; j++)
           if (a[j]>a[i] && f[j]>fmax)
             {
               fmax=f[j];
               vt=j;
             }
        f[i]=f[vt]+1;
        //s[i]=s[i]+s[vt];
        for (long j=0; j<s[vt].size(); j++)
            s[i].push_back(s[vt][j]);
    }
    cout << f[0]-2 << endl;
    for (long i=0; i<=f[0]-3; i++)
       cout << s[0][i] << " ";
}
