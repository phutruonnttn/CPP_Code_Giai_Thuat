//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "bro"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int a[maxn], b[maxn], n;
long long sa[maxn*2], sb[maxn*2];

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        b[i+n] = b[i]; a[i+n] = a[i]; // lam 2 vong tron
    }
    for (int i = 2; i <= n+n+1; i++) {
        sb[i] = sb[i-1] + b[i-1]; // khoang cach tu 1 toi dinh i
        sa[i] = sa[i-1] + a[i]; // tong luong bia tu 1 toi i
    }

    long long T = 0;
    for (int i = 1; i <= n; i++) T += min(sb[i] - sb[1], sb[n+1] - sb[i]) * a[i];
    long long res = T, haft = sb[n+1]/2; // 1 nua vong tron
    int cur = upper_bound(sb+1, sb+n+1, haft) - sb - 1; // vi tri cuoi cung di nguoc chieu kim dong ho
    for (int i = 2; i <= n; i++){
        T -= (sa[cur] - sa[i-1]) * b[i-1]; // phan bi giam di
        while (sb[cur+1] - sb[i] <= haft){
            cur ++;
            T -= (sb[i+n-1] - sb[cur] - sb[cur]+ sb[i]) * a[cur]; // thay doi
        }
        T += (sa[i-1+n] - sa[cur]) * b[i-1]; // phan tang len
        res = min(res, T);
    }
    cout << res;
    return 0;
}
