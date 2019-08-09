#include <bits/stdc++.h>

using namespace std;

uint64_t t,m,n,k,a,b;

void doc(uint64_t &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;
    if (ktAm) n=-n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ACTIVITY.inp","r",stdin);
    freopen("ACTIVITY.out","w",stdout);
    doc(t);
    while (t--)
    {
        doc(m);doc(n);doc(k);doc(a);doc(b);
        uint64_t songuoi=a+b,sn=min(m/a,n/b),tt=m+n-sn*songuoi;
        if (tt>k)
        {
            cout << sn << '\n';
            continue;
        }
        if ((k-tt)%songuoi==0)
        {
            sn-=(k-tt)/songuoi;
        }
        else
        {
            sn-=((k-tt)/songuoi+1);
        }
        uint64_t ll1=0;
        cout << max(sn,ll1) << '\n';
    }
}
