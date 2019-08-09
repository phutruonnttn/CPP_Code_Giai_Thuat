#include <bits/stdc++.h>
using namespace std;
long n;
string res, f[4007][107];

void chuanhoa(string &a,string &b)
{
    while (a.size() < b.size()) a='0'+a;
    while (a.size() > b.size()) b='0'+b;
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
   if (nho>0) c='1'+c;
   return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("pbcdem.inp","r",stdin);
    freopen("pbcdem.out","w",stdout);
    cin >> n;
    res="0";
    for (int i=0; i<=n+2; i++)
        for (int j=0; j<=100; j++)
            f[i][j]='0';
    f[0][0]="1";
    for (int i=1; i<=n; i++) f[i][1]="1";
    for (int i=1; i<=n; i++)
        for (int j=2; j*(j+1)<=2*i; j++)
        {
            f[i][j]=add(f[i-j][j],f[i-j][j-1]);
        }
    for (int j=3; j*(j-1)<=2*n; j++) res=add(f[n][j],f[n][j-1]);
    cout << res;
    return 0;
}
