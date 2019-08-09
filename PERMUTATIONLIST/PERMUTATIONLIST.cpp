#include <bits/stdc++.h>

using namespace std;

long long n,k,a[10007];
bool dd[10007];
long long tinh[10007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PERMUTATIONLIST.inp","r",stdin);
    freopen("PERMUTATIONLIST.out","w",stdout);
    cin >> n >> k;
    tinh[1]=1;
    memset(dd,true,sizeof(dd));
    for (long i=2; i<=n; i++) tinh[i]=tinh[i-1]*i;
    for (long i=1; i<=n; i++)
    {
        long long need=tinh[n-i];
        if (need==0) break;
        double thu=(double)k/need;
        if (thu==k/need)
        {
            a[i]=k/need;
            k=k-need*(a[i]-1);
            if (!dd[a[i]])
               while (!dd[a[i]]) a[i]++;
            dd[a[i]]=false;
        }
        else
        {
            a[i]=(long)k/need +1;
            k=k-need*(a[i]-1);
            if (!dd[a[i]])
               while (!dd[a[i]]) a[i]++;
            dd[a[i]]=false;
        }
        //cout << k << " " << need << endl;
    }
    for (long i=1; i<=n; i++) if (dd[i]) {a[n]=i; break;};
    for (long i=1; i<=n; i++) cout << a[i] << " ";
}
