#include <bits/stdc++.h>

using namespace std;

struct matrix
{
    long long val[10][10];
};

long long n,m;
matrix a,b,c,d;

matrix mul(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= 3; u++)
      for (int v = 1; v <= 3; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= 3; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v])%m;
      }
    return ans;
}

matrix mul1(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= 3; u++)
      for (int v = 1; v <= 1; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= 3; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v])%m;
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
    freopen("LOCO.inp","r",stdin);
    freopen("LOCO.out","w",stdout);
    cin >> n >> m;
    if (n==1) {cout << 1 % m; return 0;}
    if (n==2) {cout << 2 % m; return 0;}
    if (n==3) {cout << 4 % m; return 0;}
    if (n==4) {cout << 7 % m; return 0;}

    a.val[1][1] = a.val[1][2] = a.val[1][3] = a.val[2][1] = a.val[3][2] = 1;
    a.val[2][2] = a.val[2][3] = a.val[3][1] = a.val[3][3] = 0;
    b=power(a,n-3);

    d.val[1][1] =4; d.val[2][1] =2; d.val[3][1] =1;

    c=mul1(b,d);
    cout << c.val[1][1];
}
