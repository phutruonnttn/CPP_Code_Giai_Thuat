#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,q,a[nmax],p[nmax],mx[nmax],dd[10007],b,e;
vector <long long> v;

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
    cin.tie(0); cout.tie(0);
    freopen("CHECK.inp","r",stdin);
    freopen("CHECK.out","w",stdout);
    doc(n); doc(q);
    for (long i=1; i<=n; i++) doc(a[i]);

    v.assign(a + 1, a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;

    for (long i=1; i<=n; i++)
        {
            p[i]=dd[a[i]];
            dd[a[i]]=i;
        }
    mx[1]=p[1];
    for (long i=2; i<=n; i++)
      mx[i]=max(mx[i-1],p[i]);


    for (long i=1; i<=q; i++)
    {
        doc(b); doc(e);
        if (mx[e]<b) cout << 0;
        else cout << 1;
    }
}
