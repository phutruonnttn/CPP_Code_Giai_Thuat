#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

struct matrix
{
    long long val[10][10];
};

long long a1,n;
matrix a,b,c,d;

matrix mul(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= 3; u++)
      for (int v = 1; v <= 3; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= 3; i++)
             ans.val[u][v]=(ans.val[u][v]+ (long long)p.val[u][i]*q.val[i][v])%nmod;
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
    freopen("RATEEQUA.inp","r",stdin);
    freopen("RATEEQUA.out","w",stdout);
    cin >> a1 >> n;
    if (n==1) {cout << a1 % nmod; return 0;}
    if (n==2) {cout << (2*a1) % nmod; return 0;}
    if (n==3) {cout << (2*a1+2*a1) % nmod; return 0;}
    if (n==4) {cout << (2*a1+2*a1+3*a1) % nmod; return 0;}
    if (n==5) {cout << (2*a1+2*a1+3*a1+5*a1) % nmod; return 0;}
a1=a1%nmod;
    a.val[1][1] = 2; a.val[1][3] =-1; a.val[2][1] =1; a.val[3][2] =1;
    a.val[1][2] = a.val[2][2] = a.val[2][3] = a.val[3][1] = a.val[3][3] = 0;
    b=power(a,n-3);
    d.val[1][1]=(2*a1+2*a1) % nmod; d.val[2][1]=(2*a1)%nmod; d.val[3][1]=a1%nmod;
    c=mul1(b,d);
    cout << c.val[1][1];
}
