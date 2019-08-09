#include <bits/stdc++.h>

using namespace std;

struct data
{
    long long w,id;
};

long long n;
data a[100007];

bool comp(data a, data b)
{
    if (a.w!=b.w) return a.w >= b.w;
    return a.id < b.id;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bai2.inp","r",stdin);
    freopen("bai2.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i].w;
        a[i].id=i;
    }
    sort(a+1,a+n+1,comp);
    if (a[1].w==a[n].w)
    {
        cout << "vo nghiem" << endl;
        cout << 1 << " " << 2;
    }
    else
    {
        long long gt;
        for (long i=2; i<=n; i++)
           if (a[i].w!=a[1].w)
            {
               gt=a[i].w;
               break;
            }
        cout << gt << endl;
        for (long i=1; i<=2; i++)
            cout << a[i].id << " ";
    }
}
