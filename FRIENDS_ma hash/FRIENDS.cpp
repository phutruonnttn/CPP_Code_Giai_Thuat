#include <bits/stdc++.h>

using namespace std;
const long long b=643, m=1000000000+7,m2=m*m;

long long n;
string u,uu;
long long h[3000007],s[30000007],ss[30000007];
map <long long,long> M;

/*long long get(long long l, long long r, long long x)
{
    if (x<l || r<x) return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
    if (x==r) return ((s[r-1]-s[l-1]*h[r-1-l+1]+m2) % m);
    if (x==l) return ((s[r]-s[l]*h[r-l]+m2) % m);
    return (s[r]-s[l-1]*h[r-l+1]-(s[x-1]*(b-1)+u[x])*h[r-x]+m2) % m;
}

long long get1(long long l, long long r, long long x)
{
    if (x<l || r<x) return ((ss[r]-ss[l-1]*h[r-l+1]+m2) % m);
    if (x==r) return ((ss[r-1]-ss[l-1]*h[r-1-l+1]+m2) % m);
    if (x==l) return ((ss[r]-s[l]*h[r-l]+m2) % m);
    return (ss[r]-ss[l-1]*h[r-l+1]-(ss[x-1]*(b-1)+uu[x])*h[r-x]+m2) % m;
}*/

long long get(long long l, long long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FRIENDS.inp","r",stdin);
    freopen("FRIENDS.out","w",stdout);
    cin >> u;
    n=u.size();
    h[0]=1; h[1]=b;
    for (long long i=2; i<=n; i++)
        h[i]=(h[i-1]*b) % m;
    s[0]=(u[0]) % m;
    for (long long i=1;i<=n-1; i++)
        s[i]=((s[i-1]*b)+u[i]) % m;
    string ans;
    if (n%2==0) {cout << "NOT POSSIBLE"; return 0;};
    long long g=n/2,dem=0,d,c;

    for (long long i=0; i<=n-1; i++)
    {
       if (i==g && get(0,g-1)==get(g+1,n-1))
       {
           long long kt=get(0,g-1);
           if (M[kt]==0)
           {
              dem++;
              M[kt]=1;
           }
           d=0; c=g-1;
       }
       else
       if (i<g)
       {
           long long x1=get(0,i-1);
           long long x2=get(i+1,g);
           long long x3=(x1*(h[g-i]) +x2) % m;
           if (x3==get(g+1,n-1))
           {
               if (M[x3]==0)
                 {
                   dem++;
                   M[x3]=1;
                 }
               d=g+1,c=n-1;
           }
       }
       else
       {
           long long x1=get(g,i-1);
           long long x2=get(i+1,n-1);
           long long x3=(x1*(h[n-1-i]) +x2) % m;
           if (get(0,g-1)==x3)
           {
               if (M[x3]==0)
                {
                  dem++;
                  M[x3]=1;
                }
               d=0; c=g-1;
           }
       }
    }

    bool ok=true;
    for (long long i=0; i<=n-2; i++) if (u[i]!=u[i+1]) {ok=false; break;}

    if (ok && n%2==1)
    {
        for (long long i=0; i<=g-1; i++) cout << u[i];
        return 0;
    }

    if (dem==0 || n%2==0) cout << "NOT POSSIBLE";
    else if (dem==1)
    {
        for (long long i=d;i<=c;i++) cout << u[i];
    }
    else cout << "NOT UNIQUE";
}
