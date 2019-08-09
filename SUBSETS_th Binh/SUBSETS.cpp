#include <bits/stdc++.h>
#define nmax 27

using namespace std;

long long n,x[nmax],a[nmax],ans=0,tmp[nmax],dem,y[nmax];
bool ok;
priority_queue <long> pq;

void ktra()
{
    long long sum=0;
    dem=0;
    for (long i=1; i<=n; i++)
     if (x[i]==1)
       {
          sum+=a[i];
          tmp[++dem]=a[i];
       }
    if (sum%2==1) return;
    if (dem<=1) return;
    if (dem==2)
    {
        if (tmp[1]==tmp[2]) ans++;
        return ;
    }
    //for (long i=1; i<=dem; i++) cout << tmp[i] << " "; cout << endl;
    /*long long tinh=0,cl=0;
    sum/=2;
    for (long i=1; i<=dem; i++)
      if (tmp[i]+tinh<=sum) tinh+=tmp[i];
      else cl+=tmp[i];
    if (tinh==sum && cl==sum)
    {
        ans++;
        return;
    }
    tinh=0; cl=0;
    for (long i=dem; i>=1; i--)
       if (tinh+tmp[i]<=sum) tinh+=tmp[i];
       else cl+=tmp[i];
    if (tinh==sum && cl==sum)
    {
        ans++;
        return;
    }*/
    long long k=0;
    for (long i=dem; i>=1; i--) pq.push(tmp[i]);
    while (!pq.empty())
    {
        if (pq.size()==1)
        {
            k=pq.top();
            pq.pop();
            break;
        }
        long long s1=pq.top();
        pq.pop();
        long long s2=pq.top();
        pq.pop();
        pq.push(abs(s1-s2));
    }
    if (k==0) ans++;
    //cout << k<< endl;
}

void tryy(long i)
{
    for (long j=0; j<=1; j++)
    {
        x[i]=j;
        if (i==n) ktra();
        else tryy(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SUBSETS.inp","r",stdin);
    freopen("SUBSETS.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    tryy(1);
    cout << ans;
}
