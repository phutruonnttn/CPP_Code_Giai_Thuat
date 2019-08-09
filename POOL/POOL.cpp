#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,m,t[nmax],sumt=0,lane[nmax];

bool kt(long u)
{
   if (u==n) return true;
   if ((long long)m*u<sumt) return false;

   priority_queue <long> pq;
   for (long i=1; i<=u; i++) pq.push(-t[i]);

   for (long i=u+1; i<=n; i++)
   {
       long long gt=-pq.top();
       if (t[i]+gt>m) return false;
       pq.pop();
       pq.push(-t[i]-gt);
   }
   return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("POOL.inp","r",stdin);
    freopen("POOL.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n; i++) {cin >> t[i]; sumt+=t[i];}
    //sort(t+1,t+n+1);
    long long d=0, c=n, ans=0;
    while (d<=c)
    {
        long long mid=(d+c)/2;
        //cout << mid << endl;
        if (kt(mid))
        {
            ans=mid;
            c=mid-1;
        }
        else d=mid+1;
    }
    cout << ans;
}
