#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;
const long long ma1=719, ma2=643, m=1e9+7, m2=m*m, n=1e7+7, n2=n*n;

struct data
{
    long long h1,h2;
};

long la,lb;
long long hh1[nmax],hh2[nmax];
data bama[nmax],bamb[nmax];
string a,b;

long long geta1(long u, long v)
{
    return (bama[v].h1-bama[u-1].h1*hh1[v-u+1]+m2)%m;
}

long long getb1(long u, long v)
{
    return (bamb[v].h1-bamb[u-1].h1*hh1[v-u+1]+m2)%m;
}

long long geta2(long u, long v)
{
    return (bama[v].h2-bama[u-1].h2*hh2[v-u+1]+n2)%n;
}

long long getb2(long u, long v)
{
    return (bamb[v].h2-bamb[u-1].h2*hh2[v-u+1]+n2)%n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("C11STR2.inp","r",stdin);
    freopen("C11STR2.out","w",stdout);
    cin >> a;
    cin >> b;
    la=a.size(); lb=b.size();

    hh1[0]=1; hh1[1]=ma1;
    for (long i=2; i<=max(la,lb)+1; ++i)
       hh1[i]=(hh1[i-1]*ma1) % m;

    hh2[0]=1; hh2[1]=ma2;
    for (long i=2; i<=max(la,lb)+1; ++i)
       hh2[i]=(hh2[i-1]*ma2) % n;

    bama[0].h1=a[0];
    bama[0].h2=a[0];
    for (long i=1; i<la; ++i)
    {
       bama[i].h1=(bama[i-1].h1*ma1+a[i]) % m;
       bama[i].h2=(bama[i-1].h2*ma2+a[i]) % n;
    }

    bamb[0].h1=b[0];
    bamb[0].h2=b[0];
    for (long i=1; i<lb; ++i)
    {
       bamb[i].h1=(bamb[i-1].h1*ma1+b[i]) % m;
       bamb[i].h2=(bamb[i-1].h2*ma2+b[i]) % n;
    }

    long nho=-1;
    for (long i=0; i<la; ++i)
     if ((la-i)<=lb && a[i]==b[0] && geta1(i,la-1)==getb1(0,la-i-1) && geta2(i,la-1)==getb2(0,la-i-1))
         {
             nho=i;
             break;
         }
    if (nho==-1) cout << a << b;
    else
    {for (long i=0; i<nho; i++) cout << a[i]; cout <<b;}
}
