#include <bits/stdc++.h>
#define nmax 2007

using namespace std;
const long long b=21, m=1000000000+7,m2=m*m;

long long r,c,nn,mm,h[nmax],ss,s[nmax][nmax],hashh[nmax][nmax];

long long get(long l1, long r1, long l2, long r2)
{
     return (hashh[l2][r2]-hashh[l1-1][r2]*h[l2-l1+1]-hashh[l2][r1-1]*h[r2-r1+1]+hashh[l1-1][r1-1]*h[r2-r1+1+l2-l1+1]+m2)%m;
}

int main()
{
     ios_base::sync_with_stdio(0);
     freopen("paint.inp","r",stdin);
     freopen("paint.out","w",stdout);
     cin >> r >> c >> nn >> mm;

     h[0]=1; h[1]=b;
     for (long i=2; i<=max(mm,nn); i++)
        h[i]=(h[i-1]*b) % m;

     for (long i=1; i<=r; i++)
     {
         string s1;
         cin >> s1;
         long long tmp=0;
         for (long j=0; j<c; j++)
           if (s1[j]=='o') tmp=(tmp*b+3)%m;
           else tmp=(tmp*b+7)%m;
         ss=(ss*b+tmp)%m;
     }
     for (long i=1; i<=nn; i++)
     {
        string s1;
        cin >> s1;
        s1='*'+s1;
        if (s1[1]=='o') s[i][1]=3%m;
        else s[i][1]=7%m;
        for (long j=2; j<=mm; j++)
          if (s1[j]=='o') s[i][j]=((s[i][j-1]*b)+3) % m;
          else s[i][j]=((s[i][j-1]*b)+7) % m;
     }
     for (long i=1; i<=nn; i++)
       for (long j=1; j<=mm; j++)
          hashh[i][j]=((hashh[i-1][j]*b)+s[i][j])%m;
     long long ans=0;
     for (long i=1; i<=nn-r+1; i++)
        for (long j=1; j<=mm-c+1; j++)
          if (ss==get(i,j,i+r-1,j+c-1)) ans++;
     cout << ans << endl;
     //cout << ss << endl;
     //cout << get(7,7,10,10);
}
