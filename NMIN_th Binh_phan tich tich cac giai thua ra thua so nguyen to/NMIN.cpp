#include <bits/stdc++.h>
#define nmax 10000007
#define amax 10000000

using namespace std;

long long n,a[nmax],s1[nmax],d[nmax],dt[nmax],xh[nmax],demnt[nmax],tong=0,sp[nmax],dnt=0,am=-1;
int nt[nmax],pt=1;

void sangnt(long n)
{
  for (long i=2; i<=n; i++) nt[i]=i;
  for (long i=2; i<=int(sqrt(n));i++)
    if (nt[i]==i)
    {
        long j=i*i;
        while (j<=n)
        {
           nt[j]=i;
           j=j+i;
        }
    }
}

long long tinhsl(long long x, long long y)
{
    long long res=0,l=y;
    while (true)
    {
        res+=(x/y);
        if (x/y==0) break;
        y*=l;
    }
    return res;
}

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

bool taoso(long long x)
{
    for (long i=2; i<=am; i++)
      if (demnt[i]!=0 && tinhsl(x,i)<demnt[i]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("NMIN.inp","r",stdin);
    freopen("NMIN.out","w",stdout);
    doc(n);
    long long l=1,r=0;
    for (long i=1; i<=n; i++) {doc(a[i]); r+=a[i]; am=max(am,a[i]);}
    if (n==1)
    {
        cout << a[1];
        return 0;
    }
    sangnt(am);
    //tinh mang demnt
    for (int i=1; i<=n; ++i) demnt[a[i]]++;
    for (int i=am; i>=2; --i) demnt[i]+=demnt[i+1];
    for (int x=am; x>=2; --x)
      if (nt[x]!=x)
      {
        demnt[x/nt[x]]+=demnt[x];
        demnt[nt[x]]+=demnt[x];
        demnt[x]=0;
      }

    long long ans=r;
    while (l<=r)
    {
         long long mid=(l+r)/2;
         if (taoso(mid))
         {
             ans=mid;
             r=mid-1;
         }
         else l=mid+1;
    }
    cout << ans;
}
