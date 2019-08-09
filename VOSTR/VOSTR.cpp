#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;
const long long ma=643, m=1e9+7, m2=m*m;

long la,lb,q,l,r,u,v;
long long h[nmax],bama[nmax],bamb[nmax];
string a,b;

long long geta(long u, long v)
{
    return (bama[v]-bama[u-1]*h[v-u+1]+m2)%m;
}

long long getb(long u, long v)
{
    return (bamb[v]-bamb[u-1]*h[v-u+1]+m2)%m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VOSTR.inp","r",stdin);
    freopen("VOSTR.out","w",stdout);
    cin >> la >> lb;
    cin >> a; cin >> b;
    cin >> q;
    h[0]=1; h[1]=ma;
    for (long i=2; i<=max(la,lb)+1; ++i)
       h[i]=(h[i-1]*ma) % m;

    bama[0]=a[0];
    for (long i=1; i<la; ++i)
       bama[i]=(bama[i-1]*ma+a[i])%m;

    bamb[0]=b[0];
    for (long i=1; i<lb; ++i)
       bamb[i]=(bamb[i-1]*ma+b[i])%m;

    for (long ii=1; ii<=q; ++ii)
    {
        cin >> l >> r >> u >> v;
        l--; r--; u--; v--;
        long ll=1, rr=min(r-l+1,v-u+1), i=(ll+rr)/2;

        while (ll!=i && i!=rr)
        {
            if (geta(l,l+i-1)==getb(u,u+i-1)) ll=i;
            else rr=i;
            i=(ll+rr)/2;
        }
        long ans;
        for (long i=ll; i<=rr; i++)
           if (geta(l,l+i-1)==getb(u,u+i-1)) ans=i;

        if (ans==min(r-l+1,v-u+1))
        {
            if (r-l+1==v-u+1) cout << "=";
            else
            if (r-l+1<v-u+1) cout << "<";
            else cout << ">";
        }
        else
        {
            if (a[l+ll]>b[u+ll]) cout << ">";
            else cout << "<";
        }
    }
}
