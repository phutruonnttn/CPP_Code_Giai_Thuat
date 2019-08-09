#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,a[nmax],b[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SHUFFLE.inp","r",stdin);
    freopen("SHUFFLE.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    for (long j=1; j<=n; j++) cin >> b[j];
    long long d=1,c=0,tong1=0,tong2=0;
    for (long i=1; i<=n; i++)
    {
        tong1+=a[i]*727;
        tong2+=b[i]*727;
        c++;
        if (tong1==tong2)
          {
                tong1=0; tong2=0;
                cout << d << "-" << c << " ";
                d=i+1;
          }
    }
}
