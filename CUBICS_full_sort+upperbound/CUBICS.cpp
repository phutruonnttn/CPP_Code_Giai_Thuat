#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

struct data
{
    long long w,id;
};

long long n,k,a[nmax],b[nmax],s[nmax],f[nmax],ans=0,cs;
data ff[nmax];

bool comp(data q, data p)
{
    if (q.w!=p.w) return q.w < p.w;
    if (q.id!=p.id) return q.id <p.id;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CUBICS.inp","r",stdin);
    freopen("CUBICS.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++) {cin >> a[i]; s[i]=s[i-1]+a[i];}

    for (long i=0; i<=n; i++)
       {
           f[i]=s[i]-k*i;
           ff[i].w=f[i];
           ff[i].id=i;
       }

    for (long i=1; i<=n; i++)
      if (f[i]==k*i)
        {
            ans=i;
            cs=1;
        }

    sort(ff,ff+n+1,comp);
    for (long i=0; i<=n; i++) b[i]=ff[i].w;
    for (long i=0; i<=n; i++)
    {
        long long v=ff[upper_bound(b+1,b+n+1,f[i])-b-1].id;
        if (ans<v-i)
        {
            ans=v-i;
            cs=i+1;
        }
    }
    if (ans==0) cout << 0;
    else cout << ans << " " << cs;
}
