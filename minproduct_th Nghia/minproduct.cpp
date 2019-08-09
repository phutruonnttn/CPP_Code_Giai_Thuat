#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,a[nmax],min1=99999,min2=99999,max1=-99999,max2=-99999;

void doc(long long &n)
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
    freopen("minproduct.inp","r",stdin);
    freopen("minproduct.out","w",stdout);
    doc(n);
    for (long i=1; i<=n; i++)
    {
        doc(a[i]);
        if (min1>a[i])
        {
            min2=min1;
            min1=a[i];
        }
        else
        if (min2>a[i]) min2=a[i];

        if (max1<a[i])
        {
            max2=max1;
            max1=a[i];
        }
        else
        if (max2<a[i]) max2=a[i];
    }
    //sort(a+1,a+n+1);
    if (max1<=0)
    {
        if (max1==0)
        {
            cout << 0;
            return 0;
        }
        cout << (long long)max1*max2;
        return 0;
    }
    if (min1>=0)
    {
        if (min1==0)
        {
            cout << 0;
            return 0;
        }
        cout << (long long)min1*min2;
    }
    if (min1<0 && max1>0)
    {
        cout << (long long)min1*max1;
    }
}
