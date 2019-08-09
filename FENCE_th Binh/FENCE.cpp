#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long x,w,h;
};

long long n;
data hr[nmax];

bool cmp(data q, data p)
{
    if (q.w!=p.w) return q.w < p.w;
    return q.x < p.x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FENCE.inp","r",stdin);
    freopen("FENCE.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
       cin >> hr[i].x >> hr[i].w >> hr[i].h;
    sort(hr+1,hr+n+1,cmp);
    long long dem=0;
    for (long i=1; i<=n; i++)

}
