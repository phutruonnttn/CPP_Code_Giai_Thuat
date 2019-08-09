#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

long long n,a[nmax][nmax];
double kq[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("PAIRSUMS.inp","r",stdin);
    freopen("PAIRSUMS.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
       for (long j=1; j<=n; j++)
          cin >> a[i][j];
    if (n==2)
    {
        cout << 1 << " " << a[1][2]-1;
        return 0;
    }
    kq[1]=(double)(a[1][3]+a[1][2]-a[2][3])/2;
    for (long i=2; i<=n; i++) kq[i]=a[1][i]-kq[1];
    for (long i=1; i<=n; i++) cout << kq[i] << " ";
}
