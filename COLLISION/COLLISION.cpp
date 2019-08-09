#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

struct data
{
    long long x,y,t,h;
};

long long ans,n;
data q[nmax];

bool cmp1(data k, data l)
{
    return k.x < l.x;
}

bool cmp2(data k, data l)
{
    return k.y < l.y;
}

bool cmp3(data k, data l)
{
    return k.t < l.t;
}

bool cmp4(data k, data l)
{
    return k.h < l.h;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("COLLISION.inp","r",stdin);
    freopen("COLLISION.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        cin >> q[i].x >> q[i].y;
        q[i].h=q[i].x-q[i].y;
        q[i].t=q[i].x+q[i].y;
    }

    sort(q+1,q+n+1,cmp1);
    long long dem=1;
    for (long i=2; i<=n; i++)
    {
        if (q[i].x==q[i-1].x) dem++;
        else
        {
            ans+=(dem-1);
            dem=1;
        }
    }
    ans+=(dem-1);

    sort(q+1,q+n+1,cmp2);
    dem=1;
    for (long i=2; i<=n; i++)
    {
        if (q[i].y==q[i-1].y) dem++;
        else
        {
            ans+=(dem-1);
            dem=1;
        }
    }
    ans+=(dem-1);

    sort(q+1,q+n+1,cmp3);
    dem=1;
    for (long i=2; i<=n; i++)
    {
        if (q[i].t==q[i-1].t) dem++;
        else
        {
            ans+=(dem-1);
            dem=1;
        }
    }
    ans+=(dem-1);

    sort(q+1,q+n+1,cmp4);
    dem=1;
    for (long i=2; i<=n; i++)
    {
        if (q[i].h==q[i-1].h) dem++;
        else
        {
            ans+=(dem-1);
            dem=1;
        }
    }
    ans+=(dem-1);
    cout << ans;
}
