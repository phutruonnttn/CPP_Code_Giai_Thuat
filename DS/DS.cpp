#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define fu(i, x, y) for(int i=x; i<=y; ++i)
#define fd(i, x, y) for(int i=x; i>=y; --i)
#define maxn 100003
ifstream in("DS.inp");
ofstream out("DS.out");

int n, a[maxn], u[maxn], s[maxn], kq(0), v;
string S;

int mod1(string a,int b)
{
    int nho = 0;
    fu(i, 0, a.length()-1)
        nho = (a[i]-48+nho*10) % b;
    return nho;
}

 main()
 {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("ds.inp","r",stdin);
    freopen("ds.out","w",stdout);
    cin >> n;
    fu(i, 1, n) cin >> S, a[i] = mod1(S, n);
    fu(i, 0, n-1) u[i] = 0;
    s[0] = 0; ++u[0];
    fu(i, 1, n)
    {
        s[i] = s[i-1]+a[i];
        v = s[i] % n;
        kq += u[v];
        ++u[v];
    }
    cout << kq << endl;
}
