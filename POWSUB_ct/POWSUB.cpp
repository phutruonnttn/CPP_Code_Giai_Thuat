#include <bits/stdc++.h>
#define nmax 200007
#define dmax 1000007

using namespace std;

long long n,t,a[nmax],dem[dmax],ans,nho[nmax];
map <long,long> M;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("POWSUB.inp","r",stdin);
    freopen("POWSUB.out","w",stdout);
    cin >> n >> t;
    for (long i=1; i<=n; i++) cin >> a[i];
    //xu ly sub 2 rieng
    for (long i=1; i<=t; i++)//sub 1+3
    {
        long u,v,d1=0; cin >> u >> v;
        ans=0;
        M.clear();
        for (long j=u; j<=v; j++)
        {
            if (M[a[j]]==0)
            {
                nho[++d1]=a[j];
                M[a[j]]=1;
            }
            ans+=(2*dem[a[j]]+1)*a[j];
            dem[a[j]]++;
        }
        cout << ans << '\n';
        for (long j=1; j<=d1; j++) dem[nho[j]]=0;
    }
}
