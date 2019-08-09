#include <bits/stdc++.h>

using namespace std;

long long n, p[107], a,b, ans= -1, res;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CHILDNAME.inp","r",stdin);
    freopen("CHILDNAME.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> p[i];
    cin >> a >> b;
    sort(p+1, p+n+1);
    if (a>=p[n]) {
        if (b%2==1) cout << b;
        else cout << b-1;
        return 0;
    }
    if (b<=p[1]) {
        if (a%2==1) cout << a;
        else cout << a+1;
        return 0;
    }
    //xử lý trường hợp trung điểm nằm ngoài khoảng [a;b] thì lấy vị trí gần k nhất
    for (long i=1; i<n; i++){

        long long dau = p[i], cuoi = p[i+1], k = (dau+cuoi)/2;
        if (dau>b) continue;
        if (cuoi < a) continue;

        if (ans < min(k-dau, cuoi-k) && k%2==1 && a<=k && k<=b){
            ans= min(k-dau, cuoi-k);
            res=k;
        }
        k++;
        if (ans < min(k-dau, cuoi-k) && k%2==1 && a<=k && k<=b){
            ans= min(k-dau, cuoi-k);
            res=k;
        }
        k-=2;
        if (ans < min(k-dau, cuoi-k) && k%2==1 && a<=k && k<=b){
            ans= min(k-dau, cuoi-k);
            res=k;
        }
    }
    cout << res;
}
