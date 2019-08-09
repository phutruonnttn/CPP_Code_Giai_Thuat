#include <bits/stdc++.h>

using namespace std;
const long long b=727, m=1000000000+7,m2=m*m;

string x,y;
long long h[1000007],s[10000007];

long long get(long l, long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("countstring.inp","r",stdin);
    freopen("countstring.out","w",stdout);
    cin >> x >> y;
    h[0]=1; h[1]=b;
    long n=x.size();
    for (long i=2; i<=n; i++)
        h[i]=(h[i-1]*b) % m;
    s[0]=(x[0]) % m;
    for (long i=1;i<=n-1; i++)
        s[i]=((s[i-1]*b)+x[i]) % m;
    long long bamy=y[0];
    for (long i=1; i<=y.size()-1; i++)
        bamy=(bamy*b+y[i]) % m;
    long long dem=0,n2=y.size();
    for (long i=0; i<=n-n2; i++)
      if (get(i,i+n2-1)==bamy) {/*cout << i << " " << i+n2-1 << endl;*/ dem++;}
     cout << dem << endl;
     cout << bamy;
}
