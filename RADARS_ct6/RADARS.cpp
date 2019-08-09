#include <bits/stdc++.h>
#define nmax 1000007
#define vc 999999999

using namespace std;

long long t,n,k,vt[nmax],w[nmax],f[nmax],ans;

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
    freopen("RADARS.inp","r",stdin);
    freopen("RADARS.out","w",stdout);
    doc(t);
    while (t--)
    {
        doc(n); doc(k);
        for (long i=1; i<=n; i++) {doc(vt[i]); f[i]=0;}
        for (long i=1; i<=n; i++) doc(w[i]);
        long long maxx=-1,chay=0;
        f[0]=0;
        vt[0]=-vc;

        //f[i] la loi nhuan lon nhat khi den vi tri i va phai chon i

        for (long i=1; i<=n; i++)
           //for (long j=0; j<=i-1; j++)
             //if (vt[i]-vt[j]>=k) f[i]=max(f[i],f[j]+w[i]);
             {
                 //xem lai 2 dong tren de nho cong thuc truy hoi
                 long nho;
                 while (vt[i]-vt[chay]>=k)
                 {
                     chay++;
                     nho=maxx;
                     maxx=max(maxx,f[chay]);
                 }
                 chay--;
                 maxx=nho;
                 f[i]=maxx+w[i];
             }
        ans=-1;
        for (long i=1; i<=n; i++) ans=max(ans,f[i]);
        cout << ans+1 << '\n'; // chua giai thich duoc tai sao phai cong them 1 nhung cong them 1 moi dung
    }
}
