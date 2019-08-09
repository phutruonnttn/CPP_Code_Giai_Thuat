#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long long m,n;
string s,s1,s2,f[nmax][nmax][5],ans,sum[nmax][nmax][5];

void chuanhoa(string &a,string &b)
{
    while (a.size() < b.size()) a="0"+a;
    while (a.size() > b.size()) b="0"+b;
}

string add(string a,string b)
{
   string c=""; long nho=0;
   chuanhoa(a,b);
   for (long i=a.size()-1; i>=0; i--)
    {
        long x=a[i]-48;
        long y=b[i]-48;
        long s=x+y+nho;
        nho=s/10;
        c=char(s%10 +48) +c;
     }
   if (nho>0) c="1"+c;
   return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("BRIDGE.in","r",stdin);
    freopen("BRIDGE.out","w",stdout);
    cin >> s >> s1 >> s2;
    m=s.size(); n=s1.size();
    s='*'+s; s1='*'+s1; s2='*'+s2;

    for (long i=1; i<=n; i++)
    {
        if (s1[i]==s[1]) f[1][i][0]='1';
        if (s2[i]==s[1]) f[1][i][1]='1';
    }

    for (long j=1; j<=n; j++)
        sum[1][j][0]=add(sum[1][j-1][0],f[1][j][0]);
    for (long j=1; j<=n; j++)
        sum[1][j][1]=add(sum[1][j-1][1],f[1][j][1]);

    for (long i=2; i<=m; i++)
    {
       for (long j=1; j<=n; j++)
         for (long k=0; k<=1; k++)
          {
              if (k==0)
                if (s1[j]==s[i]) f[i][j][k]=sum[i-1][j-1][1-k];
              if (k==1)
                 if (s2[j]==s[i]) f[i][j][k]=sum[i-1][j-1][1-k];
          }
        for (long j=1; j<=n; j++)
          sum[i][j][0]=add(sum[i][j-1][0],f[i][j][0]);
        for (long j=1; j<=n; j++)
          sum[i][j][1]=add(sum[i][j-1][1],f[i][j][1]);
    }
    ans='0';
    for (long i=1; i<=n; i++)
      ans=add(ans,add(f[m][i][0],f[m][i][1]));
    cout << ans;
}
