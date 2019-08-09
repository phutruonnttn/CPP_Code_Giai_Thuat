#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,k,minn=1000000000000009,a[nmax],b[nmax],dem;

bool ktra(long long dk)
{
    dem=0;
    for (long i=1; i<=n; i++)
    {
        if (dk-a[i]>0) dem=dem+((dk-a[i])/b[i])+1;
        //if (dem>k) return false;
    }
    if (dem>k) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ATTACK.inp","r",stdin);
    freopen("ATTACK.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i];
        minn=min(a[i]+k*b[i],minn);
    }
    long long d=0, c=minn, g=(d+c)/2;
    /*while (d!=g && g!=c)
    {
        if (ktra(g)) d=g;
        else c=g;
        g=(d+c)/2;
    }
    //cout << d << " " << c << endl;
    if (ktra(d) && dem<=k) cout << c;
    else cout << d;*/
    while (d<c)
    {
        //g=(d+c)/2;
        if (ktra(g)) d=g+1;
        else c=g-1;
        g=(d+c)/2;
    }
    cout << g;
}
