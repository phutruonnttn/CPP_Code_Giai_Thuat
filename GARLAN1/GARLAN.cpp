#include <bits/stdc++.h>

using namespace std;

long long n,m,a[17][17],f[1<<17][17],sb[17];
string s[17];

int get_bit(long x,long i)
{
    return ((x>>i) & 1);
}

int main()
{
    freopen("GARLAN.inp","r",stdin);
    freopen("GARLAN.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=m; i++)
        cin >> s[i];
    for (long i=1; i<=m; i++)
      for (long j=1; j<=m; j++)
       if (s[i]!=s[j])
        {
           for (long l=0; l<n; l++)
            if (s[i][l]!=s[j][l])
              a[i][j]++;
        }

   memset(sb,0,sizeof(sb));
   for (long i=1; i<=m; i++)
     for (long j=1; j<=n; j++)
       if (s[i][j]=='1') sb[i]++;

   for (long i=0; i<(1 << m); i++)
    for (long j=0; j<m; j++)
      f[i][j+1]=100000000000;
   f[0][0]=0;

   for (long i=1; i<=m; i++)
     f[1<<(i-1)][i]=sb[i];

   long long minn=1000000000;
   for (long x=1; x<(1<<m); x++)
     for (long i=0; i<m; i++)
      {
          if (get_bit(x,i)==0)
          {
            long p=x+(1<<i);
            for (long j=0; j<m; j++)
              if (get_bit(x,j)==1)
                f[p][i+1]=min(f[p][i+1],f[x][j+1]+a[j+1][i+1]);
          }
      }
   for (long i=1; i<=m; i++)
      minn= min(f[(1<<m) -1][i],minn);
   cout << minn;
}
