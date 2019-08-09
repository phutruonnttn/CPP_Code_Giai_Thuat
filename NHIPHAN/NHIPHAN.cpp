#include <bits/stdc++.h>

using namespace std;

struct data
{
    string ss; long long ww;
};

string s[1007];
long x[50],n,m,dem=0;
data a[1007];

void ktra()
{
    for (long i=1; i<=n; i++)
        cout << x[i];
    cout<<1 << endl;
}

void sinh(long i)
{
    for (long j=0; j<=1; j++)
    {
     if (j==0)
     {
         x[i]=j;
         if (i==n) ktra();
         else sinh(i+1);
     }

     if (x[i-1]==0 && j==1)
     {
         x[i]=j;
         if (i==n) ktra();
         else sinh(i+1);
     }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NHIPHAN.inp","r",stdin);
    freopen("NHIPHAN.out","w",stdout);
    cin >> n >> m;
    sinh(1);
}
