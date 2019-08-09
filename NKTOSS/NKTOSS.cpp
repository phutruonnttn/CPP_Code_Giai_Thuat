#include <bits/stdc++.h>

using namespace std;

long n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKTOSS.inp","r",stdin);
    freopen("NKTOSS.out","w",stdout);
    cin >> n >> k;
    long d,dem=0;
    for (long i=1; i<=(1<< n); i++)
    {
        if ((i>>0)&1==1) d=1; else d=0;

        for (long j=0; j<=n-1;j++) cout << ((i>>j) & 1);
        cout << endl;

        for (long j=1; j<=n-1; j++)
        {
            if (d==k) {dem++; cout << i << endl; break;};
            if (((i >> j) & 1)==1 && ((i >> (j-1)) & 1)==1) d++;
            else
              if (((i >> j) & 1)==0) d=0;
                else
                  if (((i >> j) & 1)==1 && ((i >> (j-1)) & 1)==0) d=1;
            //if (d==k) {dem++; cout << i << endl; break;};
        }
    }
    cout << dem;
}
