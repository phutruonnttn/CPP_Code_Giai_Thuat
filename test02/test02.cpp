#include <bits/stdc++.h>

using namespace std;

long n,m,x[20][20];
bool dd[500];

void ktra()
{
    for (long i=1; i<=n; i++)
    {
        for (long j=1; j<=n; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void try_(long i, long j)
{
    for (long k=1; k<=n; k++)
      {
        x[i][j]=k;
        if (i==n && j<n) try_(1,j+1);
        else
        if (i==n && j==n) ktra();
        else try_(i+1,j);
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("test02.inp","r",stdin);
    freopen("test02.out","w",stdout);
    cin >> n;
    try_(1,1);
}
