#include <bits/stdc++.h>

using namespace std;
const long long b=37, m=1000000000+7,m2=m*m;

long n,mm;
string x;
long long h[10000007],s[100000007],a[10000007],aa[10000007];
bool dd[10000007];

long long get(long l, long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STRING.inp","r",stdin);
    freopen("STRING.out","w",stdout);
    cin >> n >> mm;
    cin >> x;

    h[0]=1; h[1]=b;

    long doan=n/mm;

    for (long i=2; i<=n; i++)
        h[i]=(h[i-1]*b) % m;

    s[0]=(x[0]) % m;
    for (long i=1;i<=n-1; i++)
        s[i]=((s[i-1]*b)+x[i]) % m;

    memset(a,0,sizeof(a));

    long dem=0,i=0;
    while (i!=n)
    {
        a[++dem]=get(i,i+doan-1);
        i+=doan;
    }

    /*for (long i=1; i<=mm; i++) cout << a[i]<<" ";
    cout << endl;*/

    memset(dd,true,sizeof(dd));

    for(long i=1; i<=mm; i++)
    {
        string ss;
        cin >> ss;
        long bamss=ss[0];
        for (long j=1; j<=doan-1; j++)
          bamss=(bamss*b+ss[j]) % m;

        //cout << bamss<< endl;

        for (long j=1; j<=mm; j++)
          if (bamss==a[j] && dd[j]==true) {aa[j]=i;dd[j]=false; break;}
    }
    for (long i=1; i<=mm; i++) cout << aa[i] << " ";
}
