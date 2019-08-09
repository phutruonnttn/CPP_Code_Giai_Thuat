#include <bits/stdc++.h>

using namespace std;

long long n,f[10],aa[100000];

string itoa_(long i)
{
    string ss="";
    long dem=0;
    while (i!=0)
    {
        aa[++dem]=i%10;
        i=i/10;
    }
    for (long j=dem; j>=1; j--)
       ss+=(char)aa[j]+48;
    return ss;
}

string mul1(string a, long b)
{
    string c=""; long nho=0;
    for (long i=a.size()-1; i>=0; i--)
     {
         long s=(a[i]-48)*b+nho;
         nho=s/10;
         c=char(s%10 +48) +c;
     }
    if (nho>0) c=itoa_(nho)+c;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("culori.inp","r",stdin);
    freopen("culori.out","w",stdout);
    cin >> n;
    f[1]=5; f[2]=8; f[3]=14; f[4]=24; f[5]=42;
    if (n<=5) cout << f[n];
    else
    {
        string s1="24",s2="42",s3;
        for (long i=6; i<=n; i++)
        {
            s3=mul1(s1,3);
            s1=s2; s2=s3;
        }
        cout << s3;
    }
}
