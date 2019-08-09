#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 1ll * 1000000 * 1000000
#define task "nim"
#define maxs 2000005

using namespace std;

long long h[maxs], T;
long long sl, x=1, y=3;

long long calc(long long val)
{
    while(val + x + 1 > y)
    {
        x++;
        y = (x + 1) * (x + 1) - 1;
    }
    return val + x + 1;
}

void setup()
{
    h[0] = 0;
    while(h[sl] <= maxn)
    {
        sl++;
        h[sl] = calc(h[sl-1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> T;
    setup();
    while (T--)
    {
        long long n;
        cin >> n;
        int vt = lower_bound(h+1, h+1+sl, n) - h;
        if(h[vt] == n)
            cout << "STEVE\n";
        else cout << "BILL\n";
    }
    return 0;
}
