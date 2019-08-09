#include <bits/stdc++.h>

using namespace std;

long n,maxx=-1,minn=117,a[107][107],ans,ct,cd;
bool ok,dd[107][107];

void loang(long i, long j)
{
    if (i==n && j==n)
    {
        ok=true;
        return;
    }
    dd[i][j]=false;
    if (a[i-1][j]!=-1 && a[i-1][j]<=ct && a[i-1][j]>=cd &&  dd[i-1][j]) loang(i-1,j);
    if (ok) return;
    if (a[i+1][j]!=-1 && a[i+1][j]<=ct && a[i+1][j]>=cd &&  dd[i+1][j]) loang(i+1,j);
    if (ok) return;
    if (a[i][j-1]!=-1 && a[i][j-1]<=ct && a[i][j-1]>=cd &&  dd[i][j-1]) loang(i,j-1);
    if (ok) return;
    if (a[i][j+1]!=-1 && a[i][j+1]<=ct && a[i][j+1]>=cd &&  dd[i][j+1]) loang(i,j+1);
    if (ok) return;
}

bool ktra(long x, long y)
{
    memset(dd,true,sizeof(dd));
    ok=false;
    cd=x; ct=y;
    loang(1,1);
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MTWALK.inp","r",stdin);
    freopen("MTWALK.out","w",stdout);
    cin >> n;
    memset(a,-1,sizeof(a));
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
      {
          cin >> a[i][j];
          minn=min(minn,a[i][j]);
          maxx=max(maxx,a[i][j]);
      }
    ans=maxx-minn;
    for (long i=minn; i<=a[1][1]; i++)
    {
        long l=0,r=ans;
        while (l<r)
        {
            long mid=(l+r)/2;
            if (ktra(i,i+mid)) {ans=mid; r=mid;}
            else l=mid+1;
        }
    }
    cout << ans;
}
