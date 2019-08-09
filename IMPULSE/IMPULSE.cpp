#include <bits/stdc++.h>

using namespace std;

long long n,f[207][7],t,a[207];

void stt(long long t)
{
    long c=0,x=0,n=200;
    for (long i=1; i<=n; i++)
    {
        if (t>0)
        {
           for (long j=0; j<=3-c; j++)
             x+=f[n-i][j];
        }
        if (t>x)
        {
            t-=x;
            a[i]=1;
            c++;
        }
        else a[i]=0;
    }
    for (long i=1; i<=n; i++) cout << a[i];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("IMPULSE.inp","r",stdin);
    freopen("IMPULSE.out","w",stdout);
    cin >> n;
    f[0][0]=1;
    for (long i=1; i<=200; i++) {f[i][0]=1; f[i][1]=1;}
    f[2][2]=1;

    for (long i=3; i<=200; i++)
      for (long j=2; j<=5; j++)
        f[i][j]=f[i-1][j]+f[i-1][j-1];

    for (long i=1; i<=n; i++)
    {
        cin >> t;
        stt(t);
    }
}
