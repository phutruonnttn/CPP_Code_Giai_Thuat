#include <bits/stdc++.h>

using namespace std;

string s;
long long n=0,a[107],aa[107],x[20];
long long ans=0;

bool ktra(char a)
{
    if (a=='A' || a=='E' || a=='I' || a=='O' || a=='U') return true;
    return false;
}

void ktra()
{
   long long d=0,tmp=1; bool ok=false;
   for (long i=1; i<=n; i++)
   {
       if (x[i]==1) tmp*=5;
       if (x[i]==2) tmp*=20;
       if (x[i]==3) tmp*=1;
   }

   for (long i=0; i<=s.size()-1; i++) aa[i]=a[i];
   for (long i=0; i<=s.size()-1; i++) {if (aa[i]==0) aa[i]=x[++d]; if (aa[i]==3) ok=true;};
   if (ok)
   {
       for (long i=0; i<=s.size()-1; i++) if (aa[i]==3) aa[i]=2;

      for (long i=1; i<=s.size()-2; i++)
        if ((aa[i]==1 && aa[i-1]==1 && aa[i+1]==1) || (aa[i]==2 && aa[i-1]==2 && aa[i+1]==2)) ok=false;
      if (ok) ans+=tmp;
   }
}

void tryy(long i)
{
    for (long j=1; j<=3; j++)
    {
        x[i]=j;
        if (i==n) ktra();
        else tryy(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DOBRA.inp","r",stdin);
    freopen("DOBRA.out","w",stdout);
    cin >> s;
    for (long i=0; i<=s.size()-1; i++)
       {
           if (s[i]=='_') {n++;a[i]=0;}
           else
            if (s[i]=='L') a[i]=3;
           else
           if (ktra(s[i])) a[i]=1;
           else
           if (!ktra(s[i])) a[i]=2;
       }
    //for (long i=0; i<s.size(); i++) cout << a[i] <<" ";
    tryy(1);
    cout << ans;
}
