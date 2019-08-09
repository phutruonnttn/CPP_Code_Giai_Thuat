#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long id, tg, ww; double w;
};

long long n,t[nmax],d[nmax],tong;
data chia[nmax];


bool comp(data a, data b)
{
    if (a.w!=b.w) return a.w < b.w;
    if (a.tg!=b.tg) return a.tg < b.tg;
    if (a.ww!=b.ww) return a.ww < b.ww;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("flowers.inp","r",stdin);
    freopen("flowers.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> t[i] >> d[i];
        tong+=d[i];
        chia[i].w=(double)t[i]/d[i];
        chia[i].tg=t[i];
        chia[i].ww=d[i];
        chia[i].id=i;
    }

    sort(chia+1,chia+n+1,comp);
    long long ans=0,cho=0;
    for (long i=1; i<=n; i++)
    {
        ans+=cho*d[chia[i].id];
        cho+=2*t[chia[i].id];
    }
    cout << ans;
}
