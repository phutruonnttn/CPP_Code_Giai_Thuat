#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,l,r,a[nmax],ans=-99999999999999999999,nho=-99999999999999999999;

uint64_t kc(long long a,long long b)
{
    return b-a;
}

long long trungvi(long long a, long long b)
{
    uint64_t d=kc(a,b);
    return b - (d >> 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MAXDIS.inp","r",stdin);
    freopen("MAXDIS.out","w",stdout);
    cin >> n >> l >> r;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);

    if (l<=a[1] && abs(l-a[1])>=ans)
        {
            ans=abs(l-a[1]);
            nho=l;
        }

    if (l>a[1])
    {
        long long vtt=upper_bound(a+1,a+n+1,l)-a;
        if (min(abs(l-a[vtt-1]),abs(a[vtt]-l))>=ans)
        {
            ans=min(abs(l-a[vtt-1]),abs(a[vtt]-l));
            nho=l;
        }
    }

    for (long i=1; i<n; i++)
    {
        long long vt=trungvi(a[i],a[i+1]);
        //cout << vt << endl;
        if (l<=vt && vt<=r && min(abs(vt-a[i]),abs(a[i+1]-vt))>=ans)
        {
            ans=min(vt-a[i],a[i+1]-vt);
            if (vt>nho) nho=vt;
        }
    }
    if (r>=a[n] && abs(r-a[n])>=ans)
        {
            ans=abs(r-a[n]);
            nho=r;
        }
    if (r<a[n])
    {
        long long vtt=upper_bound(a+1,a+n+1,r)-a;
        if (min(abs(r-a[vtt-1]),abs(a[vtt]-r))>=ans)
        {
            ans=min(abs(r-a[vtt-1]),abs(a[vtt]-r));
            if (r>nho) nho=r;
        }
    }


    cout << nho;
}
