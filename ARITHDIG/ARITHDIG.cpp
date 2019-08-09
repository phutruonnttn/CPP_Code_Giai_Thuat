#include <bits/stdc++.h>

using namespace std;

long long t,l,r,tach[100007],t2[100007];

bool ktra(long k)
{
    if (k<100) return true;
    long long tmp=k,dem=0,ss=0,s1;
    while (tmp>0)
    {
        ss++;
        tmp=tmp/10;
    }
    s1=ss;
    for (long i=1; i<=ss; i++) tach[i]=0;
    tmp=k;
    while (tmp>0)
    {
        if (ss==1)
        {
            tach[++dem]=tmp;
            break;
        }
        long tam=1;
        for (long i=1; i<=ss-1; i++) tam*=10;
        tach[++dem]=tmp/tam;
        tmp=tmp%tam;
        ss--;
    }
    long cs;
    if (tach[1]<=tach[2]) cs=tach[2]-tach[1];
    else cs=10+tach[2]-tach[1];
    for (long i=3; i<=s1; i++)
      if ((tach[i-1]+cs)%10!=tach[i]) return false;
    return true;
}

void sub1()
{
    long long ans=0;
    for (long i=l; i<=r; i++) if (ktra(i)) ans++;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ARITHDIG.inp","r",stdin);
    freopen("ARITHDIG.out","w",stdout);
    cin >> t;
    for (long ii=1; ii<=t; ii++)
    {
        cin >> l >> r;
        /*if (r-l<=100000)*/ sub1();
    }
}
