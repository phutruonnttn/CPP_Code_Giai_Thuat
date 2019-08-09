#include <bits/stdc++.h>
#define nmax 107

using namespace std;

long long n,a[nmax][nmax],dem[nmax][nmax],dd[nmax],sz[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Teamup.inp","r",stdin);
    freopen("Teamup.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        long long k;
        cin >> k;
        while (k!=0)
        {
            a[i][k]=1;
            a[k][i]=1;
            cin >> k;
        }
    }
    long long sl=0,de;
    for (long i=1; i<=n; i++)
       if (dd[i]==0)
       {
           de=0;
           dd[i]=1;
           sl++;
           dem[sl][++de]=i;
           for (long j=1; j<=n; j++)
              if (dd[j]==0)
              {
                  bool ok=true;
                  for (long k=1; k<=de; k++)
                     if (a[j][dem[sl][k]]==0)
                     {
                        ok=false;
                        break;
                     }
                  if (ok)
                  {
                      dem[sl][++de]=j;
                      dd[j]=1;
                  }
              }
           sz[sl]=de;
       }
    if (sl==1)
    {
        if (n%2==1) cout << 1;
        else cout << 0;
        return 0;
    }
    if (sz[1]<sz[2]) swap(dem[1],dem[2]);
    long long thu[nmax],slt=0,ans=99999999,thu2[nmax],t2;

    for (long i=1; i<=n; i++)
    {
        slt=0;
        thu[++slt]=i;
        memset(dd,0,sizeof(dd));
        dd[i]=1;
        for (long j=n; j>=1; j--)
          if (dd[j]==0)
          {
             bool ok=true;
             for (long k=1; k<=slt; k++)
                if (a[j][thu[k]]==0)
                {
                   ok=false;
                   break;
                }
             if (ok)
             {
                 thu[++slt]=j;
                 dd[j]=1;
             }
          }
         t2=0;
         for (long j=1; j<=n; j++)
          if (dd[j]==0)
          {
             bool ok=true;
             for (long k=1; k<=t2; k++)
                if (a[j][thu2[k]]==0)
                {
                   ok=false;
                   break;
                }
             if (ok)
             {
                 thu2[++t2]=j;
                 dd[j]=1;
             }
          }
         if (t2+slt==n) ans=min(ans,abs(n-2*slt));
    }
    if (ans==99999999)cout << "No solution";
    else cout << ans;
}
