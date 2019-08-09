#include <bits/stdc++.h>
#define nmax 50007

using namespace std;

struct data
{
    long long w,id;
};

long long n,x[nmax],y[nmax],ans=999999999999;
data x1[nmax],yy[nmax];

bool cmp(data q, data p)
{
    return q.w < p.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("queue.inp","r",stdin);
    freopen("queue.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      {
          cin >> x[i] >> y[i];
          x1[i].id=yy[i].id=i;
          x1[i].w=x[i];
          yy[i].w=y[i];
      }
    //xep ve hang
    sort(x+1,x+n+1);
    for (long i=1; i<=n; i++) x1[i].w=x[i]-i+1;
    sort(x1+1,x1+n+1,cmp);

    sort(yy+1,yy+n+1,cmp);
    long tvx=x1[n/2+1].id, tvy=yy[n/2+1].id;
    long long tong=0;
    for (long i=1; i<=n; i++)
      tong+=(abs(y[i]-y[tvy])+abs(x[i]-i+1-x1[tvx].w));
    ans=min(ans,tong);
    //xep ve cot
    for (long i=1; i<=n; i++)
      {
          x1[i].id=yy[i].id=i;
          x1[i].w=x[i];
          yy[i].w=y[i];
      }
    sort(y+1,y+n+1);
    for (long i=1; i<=n; i++) yy[i].w=y[i]-i+1;
    sort(x1+1,x1+n+1,cmp);
    sort(yy+1,yy+n+1,cmp);
    tvx=x1[n/2+1].id, tvy=yy[n/2+1].id;

    tong=0;
    for (long i=1; i<=n; i++)
      tong+=(abs(y[i]-i+1-yy[tvy].w)+abs(x[i]-x[tvx]));
    ans=min(ans,tong);

    //xep thanh HCN


    cout << ans;
}
