#include <bits/stdc++.h>

using namespace std;

long n,m,a[200][200],q,ax[20000],ay[20000],bx[20000],by[20000],cx[20000],cy[20000],na,nb,nc;
long long ans;
bool dd[200][200];

void loang(long i, long j)
{
    if (a[i][j]==9 && dd[i][j]==true) ans++;
    dd[i][j]=false;
    if (a[i][j+1]!=1 && dd[i][j+1]) loang(i,j+1);
    if (a[i+1][j]!=1 && dd[i+1][j]) loang(i+1,j);
}

void xuli()
{
   ans=0;
   memset(dd,false,sizeof(dd));
   for (long i=1; i<=na; i++)
     {
        for (long j=1; j<=nb; j++)
        {
         for (long j=1; j<=n; j++)
           for (long k=1; k<=m; k++)
             dd[j][k]=true;
          a[bx[j]][by[j]]=1;
          loang(ax[i],ay[i]);
          a[bx[j]][by[j]]=0;
        }
     }
   cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TURTLE.inp","r",stdin);
    freopen("TURTLE.out","w",stdout);
    cin >> n >> m;
    for (long i=0; i<=n+1; i++)
        for (long j=0; j<=m+1; j++)
          a[i][j]=1;
    for (long i=1; i<=n; i++)
    {
        string s; cin >> s;
        for (long j=0; j<m; j++)
            if (s[j]=='.') a[i][j+1]=0;
    }
    cin >> q;
    for (long k=1; k<=q; k++)
    {
        cin >> na;
        for (long j=1; j<=na; j++) cin >> ax[j] >> ay[j];
        cin >> nb;
        for (long j=1; j<=nb; j++) cin >> bx[j] >> by[j];
        cin >> nc;
        for (long j=1; j<=nc; j++) {cin >> cx[j] >> cy[j]; a[cx[j]][cy[j]]=9;}
        xuli();
        for (long j=1; j<=nc; j++) a[cx[j]][cy[j]]=0;
    }
}

