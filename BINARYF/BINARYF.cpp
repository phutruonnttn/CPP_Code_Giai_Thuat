#include <bits/stdc++.h>

using namespace std;

long long ans,n;
long f[10] = {0,1,2,4,8,16,32,64,128,256},tong[15];

int main()
{
    freopen("BINARYF.inp","r",stdin);
    freopen("BINARYF.out","w",stdout);
    string s;
    cin >> s;
    n=s.length();
    tong[0]=0;
    for (long i=1; i<=9; i++)
        tong[i]=tong[i-1]+f[i];

    if (s[0]>='2')
    {
        cout << tong[n];
        return 0;
    }
    else
    {
       ans=tong[n-1];//cout << ans << " ";
       for (long i=1; i<=n-2; i++)
       {
           if (s[i]=='1') ans+=1<<(n-i-1);
           if (s[i]>='2')
           {
               ans+=1<<(n-i);
               cout << ans;
               return 0;
           }
       }
    }
    ans++;
    if (s[n-1]>=1) ans++;
    cout << ans;
}
