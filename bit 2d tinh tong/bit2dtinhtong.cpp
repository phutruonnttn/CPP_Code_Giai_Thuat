#include <bits/stdc++.h>
using namespace std;

const int N = 1111;

class FenwickTree {
private:
    long long t[N][N];
public:
    void reset() { memset(t, 0ll, sizeof t); }
    void update(int x, int y, long long value) {
        for (int i = x; i < N; i += i & -i) for (int j = y; j < N; j += j & -j)
            t[i][j] += value;
    }
    long long get(int x, int y) {
        long long res = 0;
        for (int i = x; i > 0; i -= i & -i) for (int j = y; j > 0; j -= j & -j)
            res += t[i][j];
        return res;
    }
    long long query(int x, int y, int u, int v) {
        return get(u, v) - get(x - 1, v) - get(u, y - 1) + get(x - 1, y - 1);
    }
} bit;

int n;
long long a[N][N];

int main() {
    freopen("input.in", "r", stdin);
   freopen("output.out", "w", stdout);

    int test; scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        bit.reset();
        memset(a, 0, sizeof a);
        while (1)
        {
            char s[10];
            scanf("%s", s);
            if (s[0] == 'E') break;
            if (s[1] == 'E')
            {
                int x, y, w; scanf("%d%d%d", &x, &y, &w); x++; y++;
                bit.update(x, y, w - a[x][y]);
                a[x][y] = w;
            }
            else
            {
                int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v); x++; y++; u++; v++;
                printf("%lld\n", bit.query(x, y, u, v));
            }
        }
        puts("");
    }

    return 0;
}
