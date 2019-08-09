#include <bits/stdc++.h>
#define nmax 10007
#define oo 1000000000

using namespace std;

struct data
{
    long long col,s;
};

long long n,k,x[nmax],y[nmax],dem,dcol[nmax],ans=-1;
data a[nmax];

long long tinh(long long m)
{
    long long res=0;
    x[m+1]=x[1]; y[m+1]=y[1];
    for (long i=1; i<=m; i++)
       res+=((long long)(x[i+1]-x[i])*(y[i+1]+y[i]));
    return abs(res);
}

bool cmp(data q, data p)
{
    return q.s < p.s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TFIELD.inp","r",stdin);
    freopen("TFIELD.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
    {
        cin >> dem >> a[i].col;
        for (long j=1; j<=dem; j++)
           cin >> x[j] >> y[j];
        a[i].s=tinh(dem);
        //cout << a[i].s << endl;
    }
    sort(a+1,a+n+1,cmp);
    dcol[n+1]=oo;
    //for (long i=1; i<=n; i++) cout << a[i].s << endl;
    for (long i=1; i<=n; i++)
    {
        dcol[0]=0;
        for (long j=1; j<=n; j++)
          if (a[j].col!=i) dcol[j]=dcol[j-1]+1;
          else dcol[j]=dcol[j-1];
        long long r=1;
        while (dcol[r+1]<=k) r++;
        //cout << r << endl;
        ans=max(ans,a[r].s);
        for (long j=2; j<=n; j++)
        {
            while (dcol[r+1]-dcol[j-1]<=k) r++;
            ans=max(ans,a[r].s-a[j-1].s);
        }
    }
    //cout << fixed << setprecision(1) << (double)ans/2;
    cout << ans/2;
    if (ans%2==1) cout << ".5";
    else cout << ".0";
}
