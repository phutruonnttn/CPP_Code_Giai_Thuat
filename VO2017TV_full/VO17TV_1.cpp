#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>

int n, k;
ve<string> a;
void read() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int f = 0; f < sz(a[i]); ++f) a[i][f] -= 'A';
    }
}

#define ll pair<long, long>
#define m1 ((long)1e9 + 7)
#define m2 ((long)1000004059)


struct p26 {
    ve<ll> d;
    p26() : d(1, ll(1, 1)) {}
    ll operator[](int i) {
        while (sz(d) <= i)
            d.push_back(ll(
                (d.back().xx * 26) % m1,
                (d.back().yy * 26) % m2
            ));
        return d[i];
    }
} p26;

ve<ll> genhash(const string& s) {
    ve<ll> ans;
    ans.push_back(ll(s[0], s[0]));
    for (int i = 1; i < sz(s); ++i) {
        ans.push_back(ll(
            (ans.back().xx * 26 + s[i]) % m1,
            (ans.back().yy * 26 + s[i]) % m2
        ));
    }
    return ans;
}

ll gethash(const ve<ll>& ht, int l, int r) {
    if (l-- == 0) return ht[r];
    ll ans = ht[r];
    ll t = ht[l];
    ll p = p26[r - l];
    ans.xx = ((ans.xx - (t.xx * p.xx) % m1) % m1 + m1) % m1;
    ans.yy = ((ans.yy - (t.yy * p.yy) % m2) % m2 + m2) % m2;
    return ans;
}

ve<ve<ll> > ht;
map<ll, int> cnt;
set<ll> se;
bool process(int len) {
    cnt.clear();
    for (int i = 0; i < n; ++i) {
        se.clear();
        for (int f = 0; f + len <= sz(a[i]); ++f)
            se.insert(gethash(ht[i], f, f + len - 1));
        set<ll>::iterator it;
        for (it = se.begin(); it != se.end(); ++it) {
            if (++cnt[*it] >= k) return true;
        }
    }
    return false;
}

int process() {
    int maxlen = 0;
    ht.resize(n);
    for (int i = 0; i < n; ++i) {
        maxlen = max(maxlen, sz(a[i]));
        ht[i] = genhash(a[i]);
    }

    int l = 0, r = maxlen;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (process(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    cout << process();

    return 0;
}
