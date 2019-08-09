#include <bits/stdc++.h>
#define nmax 107

using namespace std;

struct data
{
    long long id,w;
};

long long m,n,ss,a[nmax][nmax],a1[nmax][nmax],tt[nmax],t1[nmax],x[nmax],b[nmax],danhdau[nmax];
data aa[nmax];
int s[nmax],s1[nmax],s2[nmax];
bool ok=true;
map <long,long> M;

bool cmp(data q, data p)
{
    if (q.w!=p.w) return q.w < p.w;
}

void sort_(long k)
{
    for (long i=1; i<=m; i++)
    {
        aa[i].id=s[i];
        aa[i].w=a[i][k];
    }

    sort(aa+1,aa+m+1,cmp);

    for (long i=1; i<=m; i++)
      s1[i]=aa[i].id;

    for (long i=1; i<=m; i++)
       if (s[i]!=s1[i])
        {
             for (long j=i+1; j<=m; j++)
               if (s[j]==s1[i])
                 {
                     for (long l=1; l<=n; l++)
                        swap(a[i][l],a[j][l]);
                     swap(s[i],s[j]);
                 }
        }
      /*for (long i=1; i<=m; i++)
         cout << s[i] << " "; cout << endl;*/
}

void ghinhan(long k)
{
    //for(long i=1; i<=k; i++) cout << x[i] << " "; cout <<endl;

    for (long i=1; i<=m; i++)
      s[i]=i;

    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
       a[i][j]=a1[i][j];

    for (long i=1; i<=k; i++) sort_(x[i]);
    //cout << s << endl;

    bool ok1=true;
    for (long i=1; i<=m; i++)
      if (s[i]!=s2[i])
      {
          ok1=false;
          break;
      }

    if (ok1)
    {
        cout << k << '\n';
        for (long i=1; i<=k; i++) cout << x[i] << " ";
        ok=false;
    }
}

void chinhhopkl(long i, long k)
{
   if (!ok) return;
   for (long j=1; j<=n; j++)
    if (b[j]==0)
     {
         x[i]=j;
         b[j]=1;
         if (!ok) return;
         if (i==k) ghinhan(k);
         else chinhhopkl(i+1,k);
         if (!ok) return;
         b[j]=0;
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sctab.inp","r",stdin);
    freopen("sctab.out","w",stdout);
    cin >> m >> n >> ss;
    bool ok2=true;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
       {
           cin >> a[i][j];
           a1[i][j]=a[i][j];
           if (a[i][j]!=0) ok2=false;
       }

    for (long i=1; i<=ss; i++) cin >> tt[i];

    for (long i=ss; i>=1; i--)
       if (M[tt[i]]==0)
       {
          M[tt[i]]=1;
          danhdau[i]=1;
       }
    long demm=0;
    for (long i=1; i<=ss; i++)
      if (danhdau[i]==1) t1[++demm]=tt[i];
    ss=demm;

    for (long i=1; i<=m; i++)
      s[i]=i;

    for (long i=1; i<=ss; i++) sort_(t1[i]);
    for (long i=1; i<=m; i++)
      s2[i]=s[i];
    //for (long i=1; i<=m; i++) cout << s2[i] << " "; cout << endl;
    if (ok2)
    {
        cout << 0;
        return 0;
    }
//-------------------------
   /* for (long i=1; i<=m; i++)
      for (long j=1; j<=n; j++)
       a[i][j]=a1[i][j];
    sort_(1); sort_(2);
    for (long i=1; i<=m; i++) cout << s[i] << " "; cout << endl;*/
//---------------
    for (long i=1; i<=n; i++)
       {
           chinhhopkl(1,i);
           if (!ok) return 0;
       }
}
