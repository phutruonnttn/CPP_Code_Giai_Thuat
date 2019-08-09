#include <bits/stdc++.h>
#define nmax 500007

using namespace std;

long long n,k,dd[nmax],a[nmax],a1[nmax],ans=0,f[nmax][5],dtest[nmax];

void sub1()
{
    for (long i=1; i<=n; i++) dd[i]=0;
    long vt=0;
    for (long i=1; i<=k; i++)
      {
          scanf("%lld",&a[i]);
          if (a[i]==0) vt=i;
          else dd[a[i]]=1;
      }

    for (long i=1; i<=n; i++)
      if (dd[i]==0)
      {
          a[vt]=i;
          for (long j=1; j<=k; j++) a1[j]=a[j];
          sort(a1+1,a1+k+1);

          long long res=0,chay=1;
          for (long j=2; j<=k; j++)
            if (a1[j]==a1[j-1]+1) chay++;
            else
            {
                res=max(res,chay);
                chay=1;
            }
          res=max(chay,res);
          ans=max(ans,res);
      }
     printf("%lld",ans);
}

void sub2()
{
    long vt=-1;
    for (long i=1; i<=k; i++)
    {
        scanf("%lld",&a[i]);
        if (a[i]==0) vt=i;
    }
    sort(a+1,a+k+1);
    //for (long i=1; i<=k; i++) cout << a[i] << " "; cout << endl;
    if (vt==-1)
    {
         long long res=0,chay=1;
          for (long j=2; j<=k; j++)
            if (a[j]==a[j-1]+1) chay++;
            else
            {
                res=max(res,chay);
                chay=1;
            }
          res=max(chay,res);
          ans=max(ans,res);
    }
    else
    {
        long long res=-1,chay=1;
    f[2][0]=1;
    for (long j=3; j<=k; j++)
    {
       if (a[j]==a[j-1]+1) chay++;
       else
       {
          res=max(res,chay);
          chay=1;
       }
       f[j][0]=chay;
    }

    f[2][1]=2;
    for (long i=3; i<=k; i++)
       if (a[i]==a[i-1]+2) f[i][1]=f[i-1][0]+2;
       else
       if (a[i]==a[i-1]+1) f[i][1]=max(f[i-1][0],f[i-1][1])+1;
       else f[i][1]=2;
    for (long i=2; i<=k; i++) ans=max(ans,f[i][1]);}
    printf("%lld",ans);
}

void sinh()
{
    freopen("lcsu.inp","w",stdout);
    cout << 100000 << " " << 20000 << endl;
    cout << 0 <<endl;
    srand(time(NULL));
    bool ok1;
    for (long i=1; i<=19999; i++)
    {
        ok1=true;
        while (ok1)
        {
            long x=rand()%100000+1;
            if (dtest[x]==0)
            {
                cout << x << endl;
                dtest[x]=1;
                ok1=false;
            }
        }
    }
}

int main()
{
    //sinh();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LCSU.inp","r",stdin);
    freopen("LCSU.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    /*if (n<=1000) sub1();
    else*/ sub2();
}

