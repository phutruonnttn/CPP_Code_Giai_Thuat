#include <bits/stdc++.h>
#define nmax 100007

using namespace std;
typedef pair <long long,long long> ii;

struct data
{
    long long w,c,tg;
};

long long n;
data a[nmax];
priority_queue <long> b;

bool comp(data q, data p)
{
    if (q.tg!=p.tg) return q.tg < p.tg;
    if (q.c!=p.c) return q.c < p.c;
    if (q.w!=p.w) return q.w < p.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("stack.inp","r",stdin);
    freopen("stack.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i].w;
    for (long i=1; i<=n; i++) cin >> a[i].c;
    for (long i=1; i<=n; i++) a[i].tg=a[i].w+a[i].c;
    long long t=0, k=0;
    sort(a+1,a+n+1,comp);
    for (long i=1; i<=n; i++)
    {
      if (a[i].c>=t)
      {
          t+=a[i].w; k++;
          b.push(a[i].w);
      }
      else
      {
          long long tmp=b.top();
          if ((a[i].c>=(t-tmp)) && (a[i].w<tmp))
          {
              b.pop();
              t=t-tmp+a[i].w;
              b.push(a[i].w);
          }
      }
    }
    cout << k;
}
