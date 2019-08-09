#include <bits/stdc++.h>

/*using namespace std;

uint64_t t,x,n,m,p,dem=0,ans;

void doc(uint64_t &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) {n=(n<<3)+(n<<1)+ch-48; dem++;}
    if (ktAm) n=-n;
}

uint64_t mul(uint64_t x, uint64_t y)
{
    if (y==0) return 0;
    uint64_t tmp=mul(x,y/2);
    if (y%2==0) return 2*tmp%m;
    else return (2*tmp+x)%m;
}

uint64_t power10(uint64_t k)
{
    if (k==0) return 1%m;
    uint64_t tmp=power10(k/2);
    tmp=mul(tmp,tmp)%m;
    if (k%2==1) tmp=tmp*10%m;
    return tmp;
}

uint64_t power(uint64_t x,uint64_t k)
{
    if (k==0) return 1%m;
    uint64_t tmp=power(x,k/2);
    ans=(ans+tmp)%m;
    tmp=mul(tmp,tmp)%m;
    if (k%2==1) tmp=mul(tmp,x)%m;
    //ans=(ans+tmp)%m;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("REMAINDER.inp","r",stdin);
    freopen("REMAINDER.out","w",stdout);
    doc(t);
    while (t--)
    {
        ans=0;
        dem=0;
        long sl=0;
        doc(x); sl=dem;
        doc(n); doc(m);
        p=power10(sl+1);
        //uint64_t aa=power(p,n-1);
        //ans=mul(x%m,ans);
        cout << p << endl;
    }
}*/

/*
#Divide and Conquer, #Modular Multiplication Trick
*/
#define taskname "REMAINDER"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
typedef unsigned long long llu;
lli x, n, m;

lli Mul(lli x, lli y)
{
    x %= m; y %= m;
    lli q = (long double) x * y / m;
    lli r = (x * y - q * m) % m;
    if (r < 0) r += m;
    return r;
}

//p^0 + p^1 + ... + p^(n - 1) modulo m
lli SumOfPowers(lli p, lli n)
{
    if (n == 1) return 1;
    if (n % 2 == 0)
        return Mul(p + 1, SumOfPowers(Mul(p, p), n / 2));
    else
        return (1 + Mul(p, SumOfPowers(p, n - 1))) % m;
}

void Solve()
{
    cin >> x >> n >> m;
    lli p = 1;
    for (lli temp = x; temp > 0; temp /= 10)
        p = (llu)p * 10UL % (llu)m;
    cout << Mul(x, SumOfPowers(p, n)) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    int nTests;
    cin >> nTests;
    for (; nTests > 0; --nTests)
        Solve();
}

