#include <bits/stdc++.h>
#define nmax 1007

using namespace std;
const long long b=31, m=1000000000+7,m2=m*m;

long long nn,mm,h[nmax],s[nmax][nmax],hashh[nmax][nmax];
char a[nmax][nmax];

long long get(long l1, long r1, long l2, long r2)
{
     return (hashh[l2][r2]-hashh[l1-1][r2]*h[l2-l1+1]-hashh[l2][r1-1]*h[r2-r1+1]+hashh[l1-1][r1-1]*h[r2-r1+1+l2-l1+1]+m2)%m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> nn >> mm;
    for (long i=1; i<=nn; i++)
       for (long j=1; j<=mm; j++)
         cin >> a[i][j];
    h[0]=1; h[1]=b;
    for (long i=2; i<=mm; i++)
        h[i]=(h[i-1]*b) % m;
    for (long i=1; i<=nn; i++)
    {
        s[i][1]=(a[i][1]) % m;
        for (long j=2; j<=mm; j++)
          s[i][j]=((s[i][j-1]*b)+a[i][j]) % m;
    }
    for (long i=1; i<=nn; i++)
       for (long j=1; j<=mm; j++)
          hashh[i][j]=((hashh[i-1][j]*b)+s[i][j])%m;

    cout << get(1,1,2,3) << endl;
    cout << get(5,2,6,4) << endl;
    cout << get(3,3,4,5) << endl;
    cout << get(5,5,6,7) << endl;
}
