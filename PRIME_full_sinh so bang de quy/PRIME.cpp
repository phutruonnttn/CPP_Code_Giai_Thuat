#include <bits/stdc++.h>
#define nmax 17

using namespace std;

long n;
long long l,r,p[nmax],ans[1000007],dem=0;

void duyet(long long x,long long pos)
{
    if (x>r) return;
    if (x>=l) ans[++dem]=x;
    for (long i=pos; i<=n; i++)
       duyet(x*p[i],i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PRIME.inp","r",stdin);
    freopen("PRIME.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> p[i];
    cin >> l >> r;
    duyet(1,1);
    if (dem==0)
    {
        cout << "none";
        return 0;
    }
    sort(ans+1,ans+dem+1);
    for (long i=1; i<dem; i++) cout << ans[i] << ","; cout << ans[dem];
}
