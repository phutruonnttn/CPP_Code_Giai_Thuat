#include <bits/stdc++.h>

using namespace std;

long long n,a[100000000],q,k[100007];
long long sod1[1000000],sod2[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VOLLEY.inp","r",stdin);
    freopen("VOLLEY.out","w",stdout);
    cin >> n;
    long long maxx=-1,dcl=0,d=0;
    for (long i=1; i<=n; i++) {cin >> a[i]; maxx=max(maxx,a[i]);};
    cin >> q;
    for (long i=1; i<=q; i++) cin >> k[i];
    sod1[0]=a[1]; sod2[0]=a[2];
    long long dau=1, cuoi=n;

    while (1<2)
    {
        if (a[dau]<a[dau+1]) {a[++cuoi]=a[dau++]; dcl++;d++;};
        sod1[d]=a[dau]; sod2[d]=a[dau+1];
        if (a[dau]==maxx) break;

        if (a[dau]>a[dau+1]) {a[++cuoi]=a[dau+1]; a[dau+1]=a[dau++]; dcl++; d++;};
        sod1[d]=a[dau]; sod2[d]=a[dau+1];
        if (a[dau]==maxx) break;
    }
    if (dcl!=0) dcl--;

    for (long i=d+1; i<=d+n-2; i++)
    {
        if (a[dau]>a[dau+1]) {a[++cuoi]=a[dau+1]; a[dau+1]=a[dau++]; };
        sod1[i]=a[dau]; sod2[i]=a[dau+1];
    }
    d+=n-2;
    /*cout << dcl; cout << endl;
    for (long i=1; i<=d; i++) {cout << sod1[i] << " " <<sod2[i]; cout << endl;};*/

    for (long i=1; i<=q; i++)
    {
        if (k[i]<=dcl) cout <<  sod1[k[i]-1] << " " << sod2[k[i]-1] << endl;
        else
        {
            k[i]=k[i]-dcl;
            if (k[i]%(n-1)==0) cout <<sod1[dcl+n-2] << " " << sod2[dcl+n-2] << endl;
            else
            {
                k[i]=k[i] % (n-1);
                cout << sod1[dcl+k[i]-1] << " " << sod2[dcl+k[i]-1] << endl;
            }
        }
    }
}
