#include <bits/stdc++.h>
#define nmod 1000000000

using namespace std;

struct matrix
{
    long long val[15][15];
};

long n,t,k,b1[15],c1[15];
matrix a,b,c,d;

matrix mul(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= n; u++)
      for (int v = 1; v <= n; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= n; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v]) % nmod;
      }
    return ans;
}

matrix mul1(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= n; u++)
      for (int v = 1; v <= 1; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= n; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v]) % nmod;
      }
    return ans;
}

matrix power(matrix x, long long k)
{
    if (k==1) return x;
    matrix tmp=power(x,k/2);
    tmp=mul(tmp,tmp);
    if (k%2==1) tmp=mul(tmp,x);
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SEQ.inp","r",stdin);
    freopen("SEQ.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n;
        for (long i=1; i<=n; i++) cin >> b1[i];
        for (long i=1; i<=n; i++) cin >> c1[i];
        cin >> k;
        if (k<=n) {cout << b1[k] << '\n'; continue; }
        for (long i=1; i<=n; i++) a.val[1][i]=c1[i];
        for (long i=1; i<=n-1; i++) a.val[i+1][i]=1;
        b=power(a,k-n);
        for (long i=1; i<=n; i++) c.val[i][1]=b1[n-i+1];
        d=mul1(b,c);
        cout << d.val[1][1] << '\n';
    }
}
