#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long w,vt,sb;
};

long long n,k,a[nmax],bit[nmax][32],f[32][nmax],ans=0;
data b[nmax];

bool comp(data q, data p)
{
    if (q.vt!=p.vt) return q.vt < p.vt;
    if (q.w!=p.w) return q.w < p.w;
    if (q.sb!=p.sb) return q.sb < p.sb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FUNBIT.inp","r",stdin);
    freopen("FUNBIT.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) cin >> a[i];

    for (long i=1; i<=n; i++)
       for (long j=0; j<=k-1; j++)
          bit[i][j+1]=(a[i]>>j)&1;

    for (long i=1; i<=k; i++)
      for (long j=1; j<=n; j++)
        f[i][j]=f[i][j-1]+bit[j][i];

    /*for (long i=1; i<=n; i++)
      for (long j=i+ans; j<=n; j++)
       {
          bool ok=true;
          for (long l=1; l<=k; l++)
            if (f[l][j]-f[l][i-1]!=f[1][j]-f[1][i-1])
             {
                ok=false;
                break;
             }
          if (ok) ans=max(ans,j-i+1);
       }
     cout << ans;*/

     for (long i=1; i<=n; i++)
       for (long j=1; j<=k; j++)
       {
           b[i].vt=i; b[i].sb=j;
           b[i].w=f[j][i]-f[1][i];
       }
     sort(b+1,b+n+1,comp);
     for (long i=1; i<=n; i++) cout << b[i].vt << " " << b[i].w << " " << b[i].sb << endl;
}
