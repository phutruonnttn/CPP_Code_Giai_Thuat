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

#define maxn 30000005

string toString(int x){
	stringstream iss;
	string res;
	iss << x;
	iss >> res;
	return res;
}

int prime[maxn], F[maxn], mu[100005], muC[100005], a[maxn], num[maxn];
int n_prime = 0;
int n, c;

void sang() {
    int i, j;
    num[1] = 0;
    n_prime = 0; ms(F, 0);
	for(i = 2; i <= maxn; i++) {
		if (F[i] == 0) {
			F[i] = prime[++n_prime] = i;
		}
		j = 0;
		while (j < n_prime && prime[j] < F[i] && prime[j + 1] * i < maxn)
		{
			int A = prime[j + 1] * i;
			F[A] = prime[j + 1];
			j++;
		}
	}
}

void add(ll &x, ll y){
	x += y;
	if(x >= mod) x -= mod;
}

void sol_Hieu(){
    sang();
    cin >> n >> c;
    mu[0] = 1; muC[0] = 1;

    For(i, 1, 100004) {
    	mu[i] = mu[i - 1] * 2 % mod;
    	muC[i] = muC[i - 1] * 1ll * (c - 1) % mod;
    }
    ms(a, 0);

    Rep(run, n){
    	int x;
    	cin >> x;
    	vector<int> pr;
    	while(x > 1){
    		int y = F[x];
    		pr.pb(y);
    		while(x % y == 0){
    			x /= y;
    		}
    	}
    	int tichm[512];
    	tichm[0] = 1;
    	a[1]++;
    	For(mask, 1, (1 << sz(pr)) - 1) Rep(i, sz(pr)) if(getbit(mask, i)){
    		tichm[mask] = tichm[offbit(mask, i)] * pr[i];
    		a[tichm[mask]]++;
    		num[tichm[mask]] = cntbit(mask);
    		break;
    	}
    }

    ll res = 0;
    For(i, 1, maxn - 1) if(a[i]){
    	ll C = (mu[a[i]] + mod - 1) * 1ll * muC[num[i]] % mod;
//    	cout << C << endl;
    	add(res, C);
    }
    cout << res << endl;
}


void sol(int test){
//	cout << 1 << endl;
//    freopen(("VO17XXX/input/" + toString(test) + ".in").c_str(), "r", stdin);
//    freopen(("VO17XXX/output/" + toString(test) + ".out").c_str(), "w", stdout);
    sol_Hieu();
//    sol_Trung();
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol(0);
//    For(i, 0, 0){
//    	clock_t start = clock();
//    	sol(i);
//    	cerr << clock() - start << endl;
//    }

    return 0;
}
