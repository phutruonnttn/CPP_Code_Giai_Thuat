#include <bits/stdc++.h>

using namespace std;
long n,t[60007],r[60007],f[60007],truyvet[60007];

int main()
{
    freopen("NKTICK.inp","r",stdin);
    freopen("NKTICK.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> t[i];
    for (long i=1; i<=n-1; i++)
        cin >> r[i];
    f[1]=t[1]; f[0]=0;
    memset(truyvet,0,sizeof(truyvet));
    for (long i=2;i<=n;i++)
    {
       f[i] = min(f[i - 2] + r[i - 1], f[i - 1] + t[i]);

    }
    cout << f[n] << endl;
    long dem=0;
    while (n>0)
    {
        if (f[n]==f[n-2]+r[n-1]) {truyvet[++dem]=n;n=n-2;}
        else  n=n-1;
    }
    for (long i=dem; i>=1; i--)
        cout << truyvet[i] << " ";
}

