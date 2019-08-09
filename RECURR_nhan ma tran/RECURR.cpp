#include <bits/stdc++.h>
#define dmax 57

using namespace std;

struct matrix
{
    long val[57][57];
};

long long t,n,d,b[dmax],f[dmax],kq[dmax];
matrix m1,m2,m3,m4;

matrix mul(matrix p, matrix q)
{
    matrix ans;
    for (int u = 1; u <= d; u++)
      for (int v = 1; v <= d; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= d; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v])%3;
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
    freopen("RECURR.inp","r",stdin);
    freopen("RECURR.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n >> d;

        for (long i=1; i<=d; i++)
          for (long j=1; j<=d; j++) m1.val[i][j]=0;
        for (long i=1; i<=d-1; i++) m1.val[i][i+1]=1;
        for (long i=1; i<=d-1; i++) m1.val[d][i]=-1;
        m1.val[d][d]=1;
        m2=power(m1,n-1);


        cout << m2.val[1][1] << " " << m2.val[1][2] << endl;
        cout << m2.val[2][1] << " " << m2.val[2][2] << endl;

        for (long i=1; i<=d; i++) cin >> b[i];
        long dem=0;
        for (long i=d; i>=1; i--) f[++dem]=b[i];
        for (long i=1; i<=d; i++) m3.val[i][1]=f[i];
        m4=mul(m2,m3);
        dem=0;
        for (long i=d; i>=1; i--) kq[++dem]=m4.val[i][1];
        for (long i=1; i<=dem; i++) cout << kq[i] << " "; cout << '\n';
    }
}
