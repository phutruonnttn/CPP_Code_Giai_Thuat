#include <bits/stdc++.h>

using namespace std;

const int N = 1<<20;
int n, z[N];
char s[N];

int main() {
  freopen("compression.inp","r",stdin);
  freopen("compression.out","w",stdout);
  cin >> s;n = strlen(s);
  z[0] = n;
  int l = -1, r = -1;
  for (int i = 1; i < n; i++) {
    if (r < i) while (i + z[i] < n && s[i + z[i]] == s[z[i]])
      z[i]++;
    else {
      z[i] = std::min(z[i - l], r - i + 1);
      while (i + z[i] < n && s[i + z[i]] == s[z[i]])
        z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  for (int i = 1; i < n; i++) if (n % i == 0 && z[i] >= n - i) {
    s[i] = 0;
    printf("%s\n", s);
    return 0;
  }
  printf("%s\n", s);
  return 0;
}

