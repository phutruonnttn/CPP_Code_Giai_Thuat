#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

#define MAXN 100005
#define INF 2000000005
#define mid ((l + r) >> 1)
#define il (i << 1)
#define ir (il | 1)

using namespace std;

int n, Z, k , a[MAXN], c[MAXN], tr[MAXN], tree[MAXN << 2];
vector<int> b;

int cmax(int i, int j)
{
  return (c[i] > c[j]) ? i : j;
}

int get(int l, int r, int x, int y, int i)
{
  if (l > y || r < x) return 0;
  if (x <= l && r <= y) return tree[i];
  return cmax(get(l, mid, x, y, il), get(mid + 1, r, x, y, ir));
}

int update(int l, int r, int x, int k, int i)
{
  tree[i] = cmax(tree[i], k);
  if (l == r) return 0;
  if (mid >= x)
    update(l, mid, x, k, il);
  else
    update(mid + 1, r, x, k, ir);
}

int init()
{
  b.assign(a + 1, a + n + 1);
  b.push_back(-INF);
  b.push_back(INF);
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  Z = b.size() - 1;
}

int write(int i)
{
  if (tr[i]) write(tr[i]);
  cout << a[i] << " ";
}

main()
{
  freopen("financial.inp", "r", stdin);
  freopen("financial.out", "w", stdout);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];

  init();

  for (int i = 1; i <= n; i++)
  {
    int p = lower_bound(b.begin(), b.end(), a[i] - k + 1) - b.begin() - 1;
    int q = lower_bound(b.begin(), b.end(), a[i] + k) - b.begin();
    int j = cmax(get(0, Z, 0, p, 1), get(0, Z, q, Z, 1));
    c[i] = c[j] + 1;
    tr[i] = j;

    int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    update(0, Z, x, i, 1);
  }


  //cout << MAXN << 2;

  //cout << c[tree[1]] << "\n";
  //write(tree[1]);
  cout << b.size();
}
