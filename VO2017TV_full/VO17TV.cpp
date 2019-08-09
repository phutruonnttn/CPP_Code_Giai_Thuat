#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 100005

int n, k;
string a[55];
int l[55];
ll h[55][100111], p[100111];
ll mu[maxn];
//#undef int
void sol_RR(){
//#define int long long
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//  cout << (fixed) << setprecision(9);
  int ntest;
  ntest = 1;
  p[0] = 1;
  For(i, 1, 100100) p[i] = p[i - 1] * 31;
  while (ntest--) {
    cin >> n >> k;
//    cout << n << " " << k << endl;
    For(i, 1, n) {
      cin >> a[i];
      l[i] = sz(a[i]);
      a[i] = " " + a[i] + " ";

      For(j, 1, l[i]) { h[i][j] = h[i][j - 1] + (a[i][j] - 'A' + 1) * p[j]; }
    }
    ll res = 0;
    For(len, 1, 100000) {
      // generate count
      map<ll, ll> all;
      map<ll, ll>::iterator it;
      For(i, 1, n) {
        For(u, 1, l[i] - len + 1) {
          int v = u + len - 1;
          ll cur = (h[i][v] - h[i][u - 1]) * p[100000 - u];
          all[cur] |= 1LL << i;
        }
      }
      // update result
      ll cur = 0;
      for (it = all.begin(); it != all.end(); it++) {
    	II p = *(it);
        if (__builtin_popcount(p.second) >= k) {
          ++cur;
        }
      }
      if (cur == 0) break;
      res = len;
    }
    cout << res << endl;
  }
}

bool can(int x){
	map<ll, ll> M;
	map<ll, ll>::iterator it;
	For(i, 1, n){
		for(int j = 0; j + x <= l[i]; j++){
			ll RR = h[i][j + x] - h[i][j] * mu[x];
			M[RR] = onbit(M[RR], i);
		}
	}
	for(it = M.begin(); it != M.end(); it++) {
		II p = *(it);
		if(cntbit(p.se) >= k) return true;
	}
	return false;
}

void sol_Hieu(){
	mu[0] = 1;
	For(i, 1, maxn - 1) mu[i] = mu[i - 1] * mod;
	cin >> n >> k;
	For(i, 1, n){
		string s;
		cin >> s;
		l[i] = sz(s);
		h[i][0] = 0;
		Rep(j, l[i]){
			int c = s[j];
			h[i][j + 1] = h[i][j] * mod + c;
		}
	}

	int l = 0, r = maxn - 1, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(can(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l - 1 << endl;
}

string toString(int x){
	stringstream iss;
	string res;
	iss << x;
	iss >> res;
	return res;
}

void sol(int test){
//	cout << 1 << endl;
    freopen(("VO17TV/input/" + toString(test) + ".in").c_str(), "r", stdin);
    freopen(("VO17TV/output/" + toString(test) + ".out").c_str(), "w", stdout);
//    cout << 1 << endl;
    sol_Hieu();
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol_Hieu();
//    Rep(i, 20){
//    	clock_t start = clock();
//    	sol(i);
//    	cerr << clock() - start << endl;
//    }
    return 0;
}
