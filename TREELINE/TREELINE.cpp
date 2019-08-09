#include <bits/stdc++.h>

using namespace std;

struct data
{
    long w,id;
};

long n,h;
data a[100007];

bool comp(data a, data b)
{
   return a.w>b.w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TREELINE.inp","r",stdin);
    freopen("TREELINE.out","w",stdout);
    cin >> n >> h;
    for (long i=1; i<=n; i++) {cin >> a[i].w; a[i].id=i;}
    sort(a+1,a+n+1,comp);
    for (long i=1; i<=n; i++) cout << a[i].w << " "; cout<< endl;
    for (long i=1; i<=n; i++) cout << a[i].id << " ";
}
