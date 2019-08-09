#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long id,gt;
};

struct data1
{
    long long id,nguyen,du;
};

long long n,l,x[nmax],x1[nmax],b[nmax],ans,d[nmax];
data a[nmax];
data1 a2[nmax];
vector <long long> vv;
map <long long, long > M;

bool cmp1(data q, data p)
{
    return q.gt < p.gt;
}

bool cmp2(data1 q, data1 p)
{
    if (q.nguyen!=p.nguyen) return q.nguyen < p.nguyen;
    return q.du < p.du;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Walking.inp","r",stdin);
    freopen("Walking.out","w",stdout);
    cin >> l >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i].gt;
        long long vi;
        cin >> vi;
        a[i].id=i;
        a2[i].id=i;
        a2[i].nguyen=(l/vi)+a[i].gt;
        a2[i].du=l-vi*(l/vi);
    }
    sort(a+1,a+n+1,cmp1);
    sort(a2+1,a2+n+1,cmp2);

    /*for (long i=1; i<=n; i++) cout << a[i].id << " "; cout << endl;
    for (long i=1; i<=n; i++) cout << a2[i].id << " "; cout << endl;*/


    for (long i=1; i<=n; i++)
        M[a[i].id]=i;

    for (long i=1; i<=n; i++)
        x1[i]=M[a2[i].id];

    for (long i=1; i<=n; i++)
        x[i]=x1[n-i+1];

    for (long i=1; i<=n; i++) b[i]=1000000007;
    for (long i=1; i<=n; i++)
    {
        d[i]=lower_bound(b+1,b+n+1,x[i])-b;
        b[d[i]]=x[i];
        ans=max(ans,d[i]);
    }
    cout << ans;
}
