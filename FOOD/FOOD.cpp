#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,k,a[nmax],ans,r[nmax];
stack <long long> sr;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FOOD.inp","r",stdin);
    freopen("FOOD.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
    {
        long u;
        cin >> u; a[i]=u*2;
    }

    for (long i=n; i>=1; i--)
    {
       while (!sr.empty() && a[sr.top()]>a[i]) sr.pop();
       if (sr.empty()) r[i]=n+1;
       else r[i]=sr.top();
       sr.push(i);
    }

    long long d=0;
    ans=a[1]; d=1;
    if (r[1]>k)
    {
        ans+=(k-d)*a[1];
        d=k;
    }
    else
    {
       ans+=(a[1]*(r[1]-1-d));
       d=r[1]-1;
    }
    if (d==n)
    {
        cout << ans;
        return 0;
    }
    for (long i=2; i<=n; i++)
    {
       if (i==n && d!=n)
       {
           ans+=a[n];
           continue;
       }
       if (r[i]>i+k-1)
       {
           if (i+k-1-d>0)
           {ans+=(i+k-1-d)*a[i];
           d=i+k-1;}
       }
       else
       {
           if (r[i]-1-d>0)
           {ans+=(a[i]*(r[i]-1-d));
           d=r[i]-1;}
       }
       if (d==n)
       {
           cout << ans;
           return 0;
       }
    }
    cout << ans;
}
