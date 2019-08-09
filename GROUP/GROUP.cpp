#include <bits/stdc++.h>

using namespace std;

long long n,k;
long long a[100007],b[100007],chiso[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GROUP.inp","r",stdin);
    freopen("GROUP.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
        {cin >> a[i]; b[i]=a[i];}

    sort(b+1,b+n+1);

    for (long i=1; i<=n; i++)
        chiso[i]=lower_bound(b+1,b+n+1,a[i])-b-1;

    /*for (long i=1; i<=n; i++)
        cout << chiso[i] << " ";
    cout << endl;*/


    long long ans=-1;

    long long sumt[100007];
    sumt[0]=0;
    for (long i=1; i<=n; i++)
        sumt[i]=sumt[i-1]+chiso[i];
    long long j;

    for (long i=0; i<=n-k;i++)
    {
       if (ans<sumt[i+k]-sumt[i])
       {
         ans=sumt[i+k]-sumt[i];
         j=i+1;
       }
    }
    cout << j;
}
