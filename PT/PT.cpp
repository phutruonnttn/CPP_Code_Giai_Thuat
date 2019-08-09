#include <bits/stdc++.h>

using namespace std;

long long k,n,ts[100007],haimu[100],bamu[100];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PT.inp","r",stdin);
    freopen("PT.out","w",stdout);
    cin >> k;
    haimu[0]=1;
    for (long i=1; i<=55; i++)
       haimu[i]=haimu[i-1]*2;
    bamu[0]=1;
    for (long i=1; i<=35; i++)
       bamu[i]=bamu[i-1]*3;
    long long dem=0;
    for (long i=0; i<=55; i++)
      for (long j=0; j<=35; j++)
        if (haimu[i]*bamu[j]>1)
             ts[++dem]=haimu[i]*bamu[j];
    sort(ts+1,ts+dem+1);
    //for (long i=1; i<=dem; i++) cout << ts[i] << endl;
    for (long i=1; i<=k; i++)
    {
        cin >> n;

    }
}
