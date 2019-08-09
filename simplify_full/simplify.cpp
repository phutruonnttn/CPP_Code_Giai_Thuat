#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

const int N = (int) 4e4 + 5;
const int M = (int) 1e5 + 5;
const int MOD = (int) 1e9 + 7;

int n, m;
int par[N];
pair <int, pair <int, int> > edge[M];

int root(int u) {
	return u == par[u] ? u : par[u] = root(par[u]);
}

bool join(int u, int v) {
	if (root(u) == root(v)) return false;
	par[root(u)] = root(v);
	return true;
}

int main() {
	freopen("SIMPLIFY.inp", "r", stdin); freopen("SIMPLIFY.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &edge[i].nd.st, &edge[i].nd.nd, &edge[i].st);
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= n; i++) par[i] = i;
	long long sumWei = 0, sumWay = 1;
	for (int i = 1, num, sum, k; i <= m; ) {
        num = sum = 0;
        set <pair <int, int> > myset;
        for (k = i; k <= m && edge[k].st == edge[i].st; k++) {
            int u = root(edge[k].nd.st);
            int v = root(edge[k].nd.nd);
            if (v < u) swap(u, v);
            if (u != v) {
                myset.insert(make_pair(u, v));
                sum++;
            }
        }
        for ( ; i < k; i++) num += join(edge[i].nd.st, edge[i].nd.nd);
        sumWei += num * edge[i - 1].st;
        if (sum == 3) {
            if (num == 1 || num == 2 && myset.size() == 3) sumWay = (sumWay * 3) % MOD;
            if (num == 2 && myset.size() == 2) sumWay = (sumWay << 1) % MOD;
        }
        if (sum == 2 && num == 1) sumWay = (sumWay << 1) % MOD;
    }
	printf("%lld %lld\n", sumWei, sumWay);
	return 0;
}
