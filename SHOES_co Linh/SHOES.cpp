#include <bits/stdc++.h>
#define nmax 1007
#define vc 9999999999

using namespace std;

long long m,n,h[nmax],s[nmax],d[nmax],minn[nmax];

//d[j] la chenh lech phat sinh khi xet den giay j(co lay giay j), i hoc sinh (for i tu 1 den n va cap nhat lien tuc)
//minn[j] la tong chenh lech nho nhat voi j giay (for dan hoc sinh tu 1 den n de cap nhat minn[j] lien tuc)

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SHOES.inp","r",stdin);
    freopen("SHOES.out","w",stdout);
    cin >> m >> n;
    for (long i=1; i<=m; i++) cin >> s[i];
    for (long i=1; i<=n; i++) cin >> h[i];
    sort(s+1,s+m+1); sort(h+1,h+n+1);
    //truong hop co so, co 1 hoc sinh (i=1)
    d[1]=abs(h[1]-s[1]);
    minn[1]=d[1];
    for (long j=2; j<=m; j++)
    {
        d[j]=abs(h[1]-s[j]);
        minn[j]=min(minn[j-1],d[j]);
    }
    //tang dan so hoc sinh
    for (long i=2; i<=n; i++)
    {
        for (long j=m; j>=i; j--)
          d[j]=abs(h[i]-s[j])+minn[j-1];
        minn[i]=d[i];
        for (long j=i+1; j<=m; j++)
          minn[j]=min(minn[j-1],d[j]);
    }
    //---------------------------
    long long ans=vc;
    for (long i=n; i<=m; i++) ans=min(ans,minn[i]);
    cout << ans;
}
