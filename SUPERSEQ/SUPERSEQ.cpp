#include <bits/stdc++.h>
#define nmod 666013

using namespace std;

struct matrix
{
    long long val[107][107];
};

long long n,h,k;
matrix a,b,c,d;

matrix mul(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= h+1; u++)
      for (int v = 1; v <= h+1; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= h+1; i++)
             ans.val[u][v]=(ans.val[u][v]+ (long long)p.val[u][i]*q.val[i][v]) % nmod;
      }
    return ans;
}

matrix mul1(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= h+1; u++)
      for (int v = 1; v <= 1; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= h+1; i++)
             ans.val[u][v]=(ans.val[u][v]+ (long long)p.val[u][i]*q.val[i][v]) % nmod;
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
    freopen("SUPERSEQ.inp","r",stdin);
    freopen("SUPERSEQ.out","w",stdout);
    cin >> n >> h >> k;
    for (long i=1; i<=h+1; i++)
    {
        for (long j=max((long long)1,i-k); j<=min(i+k,h+1); j++)
           a.val[i][j]=1;
    }
    b=power(a,n-1);
    d.val[1][1]=1;
    c=mul1(b,d);
    cout << c.val[h+1][1];
}
