#include <bits/stdc++.h>

using namespace std;

long long f[100000007],t,n,m,k,tmp[50],dem,x[50];
bool xong;

void ktra()
{
    long long sum=0,d=0,ans[100];
    for (long i=1; i<=n; i++)
      if (x[i]==1) {sum+=tmp[i]; ans[++d]=i+m-1;}
    if (sum%k==0 && sum!=0)
    {
        cout << d << " ";
        for (long i=1; i<=d; i++) cout << ans[i] << " ";
        cout << endl;
        xong=true;
    }
}

void try_(long long i)
{
    if (xong) return;
    for (long j=0; j<=1; j++)
    {
        x[i]=j;
        if (i==n) {ktra(); if (xong) return;}
        else try_(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("fibseq.inp","r",stdin);
    freopen("fibseq.out","w",stdout);
    f[1]=1; f[2]=1;
    for (long i=3; i<=1000000; i++)
       f[i]=f[i-1]+f[i-2];
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n >> m >> k;
        xong=false;
        dem=0;
        for (long i=m; i<=m+n-1; i++)
           tmp[++dem]=f[i];
        try_(1);
    }
}
