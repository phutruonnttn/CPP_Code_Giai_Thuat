#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,a[nmax],a1[nmax],f[nmax],t[nmax],tr[nmax];
vector <long long> v;

long long fmax(long long i,long long j)
{
  return (f[i]>f[j]) ? i : j;
}

long long get(long long x)
{
    long long res=t[x];
    while (x>0)
    {
       res=fmax(res,t[x]);
       x-=(x&(-x));
    }
    return res;
}

void update(long long x, long long d)
{
    while (x<n)
    {
        t[x]=fmax(t[x],d);
        x+=(x&(-x));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DCT.inp","r",stdin);
    freopen("DCT.out","w",stdout);
    cin >> n;
    for(long long i=1; i<=n; i++) {cin >> a[i]; a1[i]=a[i];}
    v.assign(a + 1, a + n + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long long i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;

    long long ans=0,vt=0;
    for(long long i=1; i<=n; i++)
    {
        f[i]=f[get(a[i]-1)]+1;
        tr[i]=get(a[i]-1);
        update(a[i],i);
        if (ans<f[i])
        {
            ans=f[i];
            vt=i;
        }
        ans=max(ans,f[i]);
    }
    long long dem=0,b[40007];
    cout << ans << endl;
    while (vt!=0)
    {
        b[++dem]=a1[vt];
        //cout << a1[vt] << " ";
        vt=tr[vt];
    }
    for (long long i=dem; i>=1; i--) cout << b[i] << " ";
}
