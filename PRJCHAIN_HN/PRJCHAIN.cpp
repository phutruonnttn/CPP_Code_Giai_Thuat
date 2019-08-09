#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long a,b,thu,dau,id;
};

long long n;
data da[nmax];

bool cmp(data q, data p)
{
    if (q.dau!=p.dau) return q.dau < p.dau;
    if (q.dau==p.dau && p.dau==1 && q.thu!=p.thu) return q.thu > p.thu;
    if (q.dau==p.dau && p.dau==2 && q.b!=p.b) return q.b > p.b;
}

bool kt(long long k)
{
    long long cur=k;
    for (long i=1; i<=n; i++)
      {
          cur=cur-da[i].a;
          if (cur<0) return false;
          cur=cur+da[i].b;
          if (cur<0) return false;
      }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PRJCHAIN.inp","r",stdin);
    freopen("PRJCHAIN.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> da[i].a; da[i].id=i;}
    for (long i=1; i<=n; i++) cin >> da[i].b;
    for (long i=1; i<=n; i++) {da[i].thu=da[i].b-da[i].a; if (da[i].thu>=0) da[i].dau=1;else da[i].dau=2;}
    sort(da+1,da+n+1,cmp);

    //long long cur=0;
    //long long minn=9999999999999999;
    /*for (long i=1; i<=n; i++)
    {
        minn=min(minn,cur-da[i].a);
        cur=cur+da[i].thu;
    }
    cout << -minn << '\n';*/

    long long l=0,r=99999999999999999999,ans=0;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        //cout << mid << endl;
        if (kt(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << ans;
    //for (long i=1; i<=n; i++) cout << da[i].id << " ";
}
