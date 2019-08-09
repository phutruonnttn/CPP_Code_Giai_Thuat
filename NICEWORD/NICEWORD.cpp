#include <bits/stdc++.h>

using namespace std;

string s;
long long n,ans=0,dem=0,x[105],vt[105],a[105];

void kt()
{
    for (long i=1; i<=dem; i++) a[vt[i]]=x[i];
    bool ok=true;
    for (long i=1; i<=n-2; i++)
       if (a[i]==a[i+1] && a[i]==a[i+2])
       {
           ok=false;
           break;
       }
    if (ok)
    {
        long long sum=1;
        for (long i=1; i<=dem; i++)
           if (x[i]==1) sum*=21;
           else sum*=5;
        ans+=sum;
    }
}

void tryy(long i)
{
    for (long j=1; j<=2; j++)
    {
        x[i]=j;
        if (i==dem) kt();
        else tryy(i+1);
    }
}

void kt2()
{
    bool kt1=false;
    for (long i=1; i<=dem; i++)
    {
        if (x[i]==3)
        {
            kt1=true;
            a[vt[i]]=1;
        }
        else a[vt[i]]=x[i];
    }
    if (!kt1) return;
    bool ok=true;
    for (long i=1; i<=n-2; i++)
       if (a[i]==a[i+1] && a[i]==a[i+2])
       {
           ok=false;
           break;
       }
    if (ok)
    {
        long long sum=1;
        for (long i=1; i<=dem; i++)
           if (x[i]==1) sum*=20;
           else
            if (x[i]==2) sum*=5;
        ans+=sum;
    }
}

void try2(long i)
{
    for (long j=1; j<=3; j++)
    {
        x[i]=j;
        if (i==dem) kt2();
        else try2(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NICEWORD.inp","r",stdin);
    freopen("NICEWORD.out","w",stdout);
    cin >> s;
    n=s.size();
    bool ok=false;
    for (long i=0; i<n; i++)
    {
        if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') a[i+1]=2;
        else
        if (s[i]!='_') a[i+1]=1;
        if (s[i]=='L') ok=true;
        if (s[i]=='_')
        {
            dem++;
            vt[dem]=i+1;
        }
    }
    if (n==1)
    {
        cout << 1;
        return 0;
    }
    if (ok)
    {
        tryy(1);
        cout << ans;
    }
    else
    {
        try2(1);
        cout << ans;
    }
}
