#include <bits/stdc++.h>

using namespace std;

long te,m,n,a[507][507],l[3][57][57],s[507][507],l2[3][507][507][3][3];

long tinh(long x, long y, long u, long v)
{
    return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
}

long play(long p, long r, long c)
{
   if (r==0 || c==0) return 0;
   if (l[p][r][c]!=-1) return l[p][r][c];
   long res=0;
   //xoa dong
   for (long i=r-1; i>=0; i--)
     if ((tinh(i+1,1,r,c)%2==0) && play(1-p,i,c)==0)
      {
         res=1;
         break;
      }
   if (res==1)
   {
       l[p][r][c]=res;
       return res;
   }
   //xoa cot
   for (long i=c-1; i>=0; i--)
     if ((tinh(1,i+1,r,c)%2==0) && play(1-p,r,i)==0)
     {
         res=1;
         break;
     }
   l[p][r][c]=res;
   return res;
}

long play2(long p, long r, long c, long s, long t)
{
   if (r==0 || c==0) return 0;
   if (l2[p][r][c][s][t]!=-1) return l2[p][r][c][s][t];
   long res=0;
   if (s==0) //dang chon dong
   {
       if ((t+tinh(r,1,r,c))% 2==0)
        if (play2(1-p,r-1,c,0,0)==0 && play2(1-p,r-1,c,1,0)==0) res=1;
       if (play2(p,r-1,c,s,(t+tinh(r,1,r,c))%2)==1) res=1;
   }
   if (res==1)
   {
       l2[p][r][c][s][t]=res;
       return res;
   }
   if (s==1) //dang chon cot
   {
       if ((t+tinh(1,c,r,c))% 2==0)
        if (play2(1-p,r,c-1,0,0)==0 && play2(1-p,r,c-1,1,0)==0) res=1;
       if (play2(p,r,c-1,s,(t+tinh(1,c,r,c))%2)==1) res=1;
   }
   l2[p][r][c][s][t]=res;
   return res;
}

void sub1()
{
    memset(l,-1,sizeof(l));
    if (play(0,m,n)==1) cout << "TRUE" << '\n'; else cout << "FALSE" << '\n';
}

void sub2()
{
    memset(l2,-1,sizeof(l2));
    if (play2(0,m,n,0,0)==1 || play2(0,m,n,1,0)==1) cout << "TRUE" << '\n'; else cout << "FALSE" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("parigame.inp","r",stdin);
    freopen("parigame.out","w",stdout);
    cin >> te;
    for (long tt=1; tt<=te; tt++)
    {
        cin >> m >> n;
        for (long i=1; i<=m; i++)
          for (long j=1; j<=n; j++)
            cin >> a[i][j];
        memset(s,0,sizeof(s));
        for (long i=1; i<=m; i++)
          for (long j=1; j<=n; j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        /*if (n<=50 && m<=50) sub1();
        else*/ sub2();
    }
}
