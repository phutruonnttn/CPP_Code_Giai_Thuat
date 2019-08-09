#include <bits/stdc++.h>
#define nmax 77

using namespace std;

long long n,k,c[nmax][nmax],a[nmax];

long long sohieu()
{
    long long res=0;
    for (long i=1; i<=k; i++)
      for (long j=a[i-1]+1; j<=a[i]-1; j++)
        res+=c[n-j][k-i];
    return res+1;
}

void tim(long long t)
{
    for (long i=1; i<=k; i++)
       for (long j=a[i-1]+1; j<=n; j++)
         if (t>c[n-j][k-i]) t-= c[n-j][k-i];
         else {a[i]=j; break;}
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ckn.inp","r",stdin);
    freopen("ckn.out","w",stdout);
    cin >> n >> k;

    c[0][0]=1;
    for (long i=1; i<=n; i++)
    {
        c[i][0]=c[i][i]=1;
        for (long j=1; j<=i-1; j++)
           c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    cout << c[n][k] << '\n';
    long long tv;
    while (cin>>tv)
    {
        if (tv==1)
        {
            for (long i=1; i<=k; i++)
               cin >> a[i];
            cout << sohieu() << '\n';
        }
        else
        {
            long long l; cin >> l;
            tim(l);
            for (long i=1; i<=k; i++) cout << a[i] << " ";
            cout << '\n';
        }
    }
}
