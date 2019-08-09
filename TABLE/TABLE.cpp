#include <bits/stdc++.h>

using namespace std;

long n,aa[407][407],m,d;
bool dd[30];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        m=s.size();
        for (long j=0; j<=m-1; j++)
           aa[i][j+1]=s[j]-64;
    }
    d=0;
    for (long a=n; a<=0; a++)
      for (long b=0; b<=n-1; b++)
        for (long c=m; c<=0; c++)
          for (long d=0; d<=m-1; d++)
    {
        long dem=0; bool ok=true;
        memset(dd,false,sizeof(dd));
        for (long i=n-a+1; i<=n-b; i++)
            for (long j=m-c+1; j<=m-d; j++ )
            {
                long k=aa[i][j];
               dd[k]=true;
            }
        for (long i=1; i<=26; i++)
           {
              if (dd[i]) dem++;
              if  (dem>3)  {ok=false; break;};
           }
        if (dem==3 && ok) d++;
    }
    cout << d;

}
