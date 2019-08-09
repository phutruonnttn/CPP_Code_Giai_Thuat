#include <bits/stdc++.h>

using namespace std;

long n,a[10007],b[10007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PERMUTATIONGEN.inp","r",stdin);
    freopen("PERMUTATIONGEN.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    long vt=-1;
    for (long i=n; i>=2; i--)
      if (a[i-1]<a[i])
       {
           vt=i-1;
           break;
       }
    if (vt==-1)
    {
        cout << -1;
        return 0;
    }
    long dem=0;
    for (long i=vt; i<=n; i++)
       b[++dem]=a[i];
    sort(b+1,b+dem+1);
    /*for (long i=1;i<=dem;i++) cout << b[i] << " "; cout << endl;
    cout << a[vt];*/
    long doi;
    for (long i=1; i<=dem; i++)
        if (b[i]>a[vt])
         {
            doi=b[i];
            b[i]=-1;
            break;
         }
    //for (long i=1;i<=dem;i++) cout << b[i] << " "; cout << endl;
    //cout << a[vt];
    a[vt]=doi;
    long chay=1;
    for (long i=vt+1; i<=n; i++)
    {
        if (b[chay]==-1) chay++;
        a[i]=b[chay];
        chay++;
    }
    for (long i=1;i<=n;i++) cout << a[i] << " ";
}
