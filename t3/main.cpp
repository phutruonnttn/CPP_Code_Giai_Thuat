#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
const long long b=727, m=1e9+7, m2=m*m;

string x,y;
long long h[nmax],hashx[nmax],hashy;

long long get(long l, long r)
{
    return (hashx[r]-hashx[l-1]*h[r-l+1]+m2) % m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("t3.inp","r",stdin);
    freopen("t3.out","w",stdout);
    cin >> x >> y;
    long n=x.size();
    h[0]=1; h[1]=b;
    for (long i=2; i<=n; i++) h[i]=(h[i-1]*b) % m;
    hashx[0]=(x[0]) % m;
    for (long i=1; i<=n-1; i++)
       hashx[i]=(hashx[i-1]*b +x[i]) % m;
    hashy=(y[0]) % m;
    for (long i=1; i<y.size(); i++) hashy=(hashy*b+y[i]) % m;
    long long dem=0,n2=y.size();
    for (long i=0; i<=n-n2; i++)
      if (get(i,i+n2-1)==hashy) {/*cout << i << " " << i+n2-1 << endl;*/ dem++;}
     cout << dem << endl;
}




