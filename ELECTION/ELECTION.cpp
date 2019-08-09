#include <bits/stdc++.h>
#define nmax 1007

using namespace std;

struct data
{
    long long id,w;
};

long long n,d[50007],t,ans=0,sum=0,kq[nmax],aa[nmax];
data a[nmax];

bool cmp(data q, data p)
{
    return q.w > p.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ELECTION.inp","r",stdin);
    freopen("ELECTION.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i].w;
        sum+=a[i].w;
        a[i].id=i;
        aa[i]=a[i].w;
    }
    t=(sum+1)/2;
    sort(a+1,a+n+1,cmp);
    memset(d,0,sizeof(d));
    d[0]=-1;
    for (long i=1; i<=n; i++)
      for (long j=t-1; j>=0; j--)
        if (d[j]!=0 && d[j+a[i].w]==0)
        {
            d[j+a[i].w]=a[i].id;
            if (j+a[i].w>ans) ans=j+a[i].w;
        }
     //for (long i=1; i<=n; i++) cout << a[i].w << " "; cout << endl;

     long long dem=0;
     while (d[ans]!=-1)
     {
         kq[++dem]=d[ans];
         ans-=aa[d[ans]];
     }
     cout << dem << '\n';
     sort(kq+1,kq+dem+1);
     for (long i=1; i<=dem; i++)
        cout << kq[i] << " ";
}
