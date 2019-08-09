#include <bits/stdc++.h>

using namespace std;

struct data
{
    long w,id;
};

data a[5007];
long n,b[5007];
bool ktras1=true,ktras2=true;

bool comp(data m, data n)
{
    return m.w<n.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VODIVIDE.inp","r",stdin);
    freopen("VODIVIDE.out","w",stdout);
    cin >> n; if (n>20) ktras2=false;
    for (long i=1; i<=n; i++) {cin >> a[i].w; a[i].id=i;}
    for (long i=1; i<=n; i++) {cin >> b[i]; if (a[i].w!=b[i]) ktras1=false;};
    if (ktras1)
    {
        long long ans=0,j=1;
        sort(a+1,a+n+1,comp);
        for (long i=1; i<=n; i++)
          if (i%2==1) ans+=a[i].w;
        cout<< ans << endl;
        while (j<=n)
        {
            cout << a[j].id << " ";
            j++;
            cout << a[j].id << endl;
            j++;
        }
    }
    else
    if (ktras2)
    {

    }
}
