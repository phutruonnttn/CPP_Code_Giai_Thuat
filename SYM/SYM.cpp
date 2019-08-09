#include <bits/stdc++.h>

using namespace std;

long long n,x[1007],y[1007],b[1007];
double tamx[5000007],tamy[5000007];
map <double, int> M;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SYM.inp","r",stdin);
    freopen("SYM.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    long d=0;
    for (long i=1; i<=n;i++)
      for (long j=i; j<=n;j++)
      {

          d++;
          tamx[d]=(double)(x[i]+x[j])/2;
          tamy[d]=(double)(y[i]+y[j])/2;
          double s=tamx[d]*2+tamy[d];
          if (M[s]==1) d--;
          else M[s]=1;
      } cout << d;

    long long ans1=10000000000;
    for (long i=1; i<=d; i++)
    {
        bool ok=false; long long dem=0,slb=0;
        for (long j=1; j<=n; j++)
        {
           double tx=2*tamx[i]-x[j];
           double ty=2*tamy[i]-y[j];
           double s=tx*2+ty;
           if (M[s]!='a')
           {
               dem++;
               b[++slb]=s;
               M[s]='a';
           }
        }
        ans1=min(ans1,dem);
        for (long j=1; j<=slb; j++)
            M.erase(b[j]);
    }
    //cout << ans1 << " " << 0;
}
