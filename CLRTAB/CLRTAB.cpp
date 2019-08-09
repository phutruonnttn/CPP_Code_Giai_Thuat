#include <bits/stdc++.h>
#define nmax 507

using namespace std;
typedef pair <long,long> ii;

struct data
{
    long long mau,sl;
};

long m,n,c[nmax][nmax],d[nmax][nmax],t,dd[nmax][nmax];
data a[nmax];
vector <ii> kq1,kq2;
map <long,long> M;

bool cmp(data q, data p)
{
    return q.sl < p.sl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CLRTAB.inp","r",stdin);
    freopen("CLRTAB.out","w",stdout);
    cin >> t;
  for (long ie1=1; ie1<=t; ie1++)
  {
    cin >> m >> n;
    M.clear();
    long demm=0;
    for (long i=1; i<=max(n,m); i++) a[i].sl=0;
    for (long i=1; i<=m; i++)
       for (long j=1; j<=n; j++)
          {
              cin >> c[i][j];
              if (M[c[i][j]]==0) M[c[i][j]]=++demm;
              a[M[c[i][j]]].mau=c[i][j];
              a[M[c[i][j]]].sl++;
          }

    for (long i=1; i<=n; i++)
       {
           sort(a+1,a+demm+1,cmp);
    /*for (long i2=1; i2<=demm; i2++)
          cout << a[i2].mau << " " << a[i2].sl << endl; cout << endl;*/

           long bd;
           for (long j=1; j<=n; j++)
             if (a[j].sl!=0)
             {
                 bd=j;
                 break;
             }

               long nho=a[bd].sl;
               for (long j=1; j<=min(m,nho); j++)
               {
                  d[j][i]=a[bd].mau;
                  a[bd].sl--;
               }
               for (long j=nho+1; j<=m; j++)
               {
                  d[j][i]=a[demm].mau;
                  a[demm].sl--;
               }
       }

       for (long i=0; i<=50; i++)
        for (long j=0; j<=50; j++)
          dd[i][j]=-1;
       kq1.clear(); kq2.clear();
       long ans=0;

       for (long i=1; i<=m; i++)
         for (long j=1; j<=n; j++)
          {
              /*if (d[i][j]==c[i][j]) dd[i][j]=1;
              else*/
              {
                for (long e=1; e<=m; e++)
                {
                  bool ok=false;
                  for (long f=1; f<=n; f++)
                    if (dd[e][f]==-1 && c[e][f]==d[i][j])
                    {
                       ok=true;
                       ans++;
                       kq1.push_back(ii(i,j));
                       kq2.push_back(ii(e,f));
                       swap(c[i][j],c[e][f]);
                       break;
                    }
                  if (ok) break;
                }
                dd[i][j]=1;
               }

          }
           cout << ans << '\n';
           for (long i=0; i<ans; i++)
             cout << kq1[i].first << " " << kq1[i].second << " " << kq2[i].first << " " << kq2[i].second << '\n';
  }
}
