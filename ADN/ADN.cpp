#include <bits/stdc++.h>

using namespace std;

string a,b;
long long maxx=0,vtda,vtca,vtdb,vtcb,n,cuoib,daub,ans=-1,vtcb1,vtca1;

void ktra(long long l1, long long r1)
{
    long long dem=-1,dta,dtb,dodai=0;
    for (long long i=l1; i<=r1; i++)
    {
        dem++;
        if (a[i]==b[dem])
        {
            if (dodai==0) {dtb=dem; dta=i;}
            dodai++;
        }
        else
        {
            if (maxx<dodai)
            {
                maxx=dodai;
                vtdb=dtb; vtcb=dem-1;
                vtda=dta; vtca=i-1;
            }
            dodai=0;
        }
    }
    if (maxx==n) return;
    long long demm=n-1;
    if (vtdb==0)
      {
       while(maxx<n)
       {
          if (a[vtda-1]==b[demm])
          {
              maxx++;
              vtdb--;
              vtda--;
              demm--;
          }
          else break;
       }
       return ;
      }
    demm=0;
    if (vtcb==n-1)
    {
        while (maxx<n)
        {
            if (a[vtca+1]==b[demm])
            {
                maxx++;
                vtcb++;
                vtca++;
                demm++;
            }
            else break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ADN.inp","r",stdin);
    freopen("ADN.out","w",stdout);
    cin >> a >> b;
    n=a.size();
    a+=a;
    for (long long i=0; i<=n; i++)
    {
        ktra(i,i+n-1);
        if (maxx>ans)
        {
            ans=maxx;
            vtcb1=vtcb;
            vtca1=vtca;
        }
    }
    long long dauct=vtcb1-n+1,daua=vtca1-n+1;

    string ct="",ctt="";

    for (long long i=dauct; i<=vtcb1; i++)
        if (i<0) ct+=b[i+n];
        else ct+=b[i];

    for (long long i=daua; i<=vtca1; i++)
        if (i<0) ctt+=a[i+n];
        else ctt+=a[i];

    cout << ans << '\n';
    cout << ctt << '\n';
    cout << ct;
}
