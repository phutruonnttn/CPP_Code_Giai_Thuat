#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,m,a[nmax],p[nmax],mx[nmax],f[nmax],d[4*nmax];//,xd[nmax][nmax];
map <long long, long> M;

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=f[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=max(d[node*2],d[node*2+1]);

}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return -10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("DIP.inp","r",stdin);
    freopen("DIP.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) cin >> a[i];
    for (long i=1; i<=n; i++)
        {
            p[i]=M[a[i]];
            M[a[i]]=i;
        }
        mx[1]=p[1];
        for (long i=2; i<=n; i++)
             mx[i]=max(mx[i-1],p[i]);
    //for (long i=1; i<=n; i++) cout << mx[i] << " ";cout << endl;

    for (long i=1; i<=n; i++) f[i]=i-mx[i];
    //for (long i=1; i<=n; i++) cout << f[i] << " "; cout << endl;
    //build(1,1,n);


    for (long i=1; i<=m; i++)
    {
        long long b,e;
        cin >> b >> e;
        ++b; ++e;
        if (mx[e]<b) cout << e-b+1 << '\n';
        else //cout << get(1,1,n,b,e) << '\n';
        {
            long long ans=-1000;
            for (long j=b; j<=e; j++)
               ans=max(ans,min(f[j],j-b+1));
            cout << ans << '\n';
        }
    }
}
