#include <bits/stdc++.h>
#define nmod 10

using namespace std;

struct matrix
{
    long val[1001][1001];//van dung, do phien ban c++ nay gioi han b
};

struct matrix1
{
    long val[1007][5];
};

long t,n;
matrix a,b,c;
matrix1 ans1,ans2,res,v;

void doc(matrix &p)
{
    for (long i=1; i<=n; i++)
      {
         string s; cin >> s;
         for (long j=0; j<=n-1; j++)
            p.val[i][j+1]=s[j]-48;
      }
}

matrix1 mul(matrix p, matrix1 q)
{
    matrix1 ans;
    for (int u = 1; u <= n; u++)
      for (int v = 1; v <= 1; v++)
      {
         ans.val[u][v]=0;
         for (int i = 1; i <= n; i++)
             ans.val[u][v]=(ans.val[u][v]+ p.val[u][i]*q.val[i][v]) % nmod;
      }
    return ans;
}

matrix1 sub(matrix1 p, matrix1 q)
{
    matrix1 ans;
    for (long i=1; i<=n; i++)
       ans.val[i][1]=(p.val[i][1]-q.val[i][1]) % nmod;
    return ans;
}

bool kt(matrix1 q)
{
    for (long i=1; i<=n; i++)
      if (q.val[i][1]!=0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    freopen("VMATRIX.inp","r",stdin);
    freopen("VMATRIX.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n;
        doc(a); doc(b); doc(c);
        bool ok=true;
        for (long k=1; k<=5; k++)
        {
            for (long i=1; i<=n; i++)
               v.val[i][1]=rand()%2;
            ans1=mul(a,mul(b,v));
            ans2=mul(c,v);
            res=sub(ans1,ans2);
            if (!kt(res))
            {
                ok=false;
                break;
            }
        }
        if (ok) cout << "YES" << '\n'; else cout << "NO" << '\n';
    }
}
