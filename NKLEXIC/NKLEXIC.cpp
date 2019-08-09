#include <bits/stdc++.h>

using namespace std;

long long n,m,k,x[300],a[300],dem,rb;
bool dd[300],OK;

void ktra()
{
    dem++; bool ok=true;
    for (long i=1; i<=m; i++)
      if (x[i]!=a[i]) {ok=false; break;};
    if (ok) {cout << dem << endl; OK=true;};
}

void tryy(long long i)
{
   if (OK) return;
   if (!OK)
    for (long j=1; j<=n; j++)
      if (dd[j])
        {
         x[i]=j;
         dd[j]=false;
         if (i==m) ktra();
         else tryy(i+1);
         if (OK) return;
         dd[j]=true;
        }
}

void ktra_()
{
    dem++;
    if (dem==rb)
    {
       OK=true;
       for (long i=1; i<=m; i++)
        cout << char(x[i]+96);
       cout << endl;
    }
}

void try_(long long i)
{
   if (OK) return;
   if (!OK)
    for (long j=1; j<=n; j++)
      if (dd[j])
        {
         x[i]=j;
         dd[j]=false;
         if (i==m) ktra_();
         else try_(i+1);
         if (OK) return;
         dd[j]=true;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKLEXIC.inp","r",stdin);
    freopen("NKLEXIC.out","w",stdout);
    cin >> k;
    for (long q=1; q<=k; q++)
    {
        cin >> n >> m;
        char s; cin >>s;
        if (s=='P')
        {
           string ss;
           cin >> ss;
           for (long i=0; i<=m-1; i++)
                a[i+1]=(long)ss[i]-96;
           memset(dd,true,sizeof(dd));
           OK=false; dem=0;
           tryy(1);
           if (!OK) cout << "Incorrect data" << endl;
        }
        else
        {
            cin >> rb;
            OK=false;
            memset(dd,true,sizeof(dd));
            dem=0;
            try_(1);
            if (!OK) cout << "Incorrect data"<<endl;
        }
    }
}
