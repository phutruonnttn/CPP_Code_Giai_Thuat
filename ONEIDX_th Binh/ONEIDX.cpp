#include <bits/stdc++.h>
#define nmax 100007
#define mmax 107

using namespace std;

long long n,dx[mmax],dy[mmax],dz[mmax],dxy[mmax][mmax],dxz[mmax][mmax],dyz[mmax][mmax],dxyz[mmax][mmax][mmax];

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
    cin.tie(0);
    freopen("ONEIDX.inp","r",stdin);
    freopen("ONEIDX.out","w",stdout);
    doc(n);
    long long ans=0;
    for (long i=1; i<=n; i++)
      {
          long long a,b,c;
          doc(a); doc(b); doc(c);
          dx[a]++; dy[b]++; dz[c]++;
          dxy[a][b]++; dxz[a][c]++; dyz[b][c]++;
          dxyz[a][b][c]++;
          ans+=(dx[a]+dy[b]+dz[c]-2*(dxy[a][b]+dyz[b][c]+dxz[a][c])+3*dxyz[a][b][c]);
      }
    cout << ans;
}
