#include <bits/stdc++.h>
#define nmod 111539786

using namespace std;

struct matrix
{
    long long val[10][10];
};

long n,t;
matrix a,b,c,d;

matrix mul(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= 2; u++)
      for (int v = 1; v <= 2; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= 2; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v]) % nmod;
      }
    return ans;
}

matrix mul1(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= 2; u++)
      for (int v = 1; v <= 1; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= 2; i++)
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
    freopen("latgach4.inp","r",stdin);
    freopen("latgach4.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n;
        if (n==1) {cout << 1 <<'\n'; continue;}
        if (n==2) {cout << 2 <<'\n'; continue;}
        if (n==3) {cout << 3 <<'\n'; continue;}
        a.val[1][1] = a.val[1][2] = a.val[2][1] = 1;
        a.val[2][2] = 0;
        b=power(a,n-2);
        c.val[1][1]=2; c.val[2][1]=1;
        d=mul1(b,c);
        cout << d.val[1][1] << '\n';
    }
}
