#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 500002

using namespace std;
typedef long long ll;

int n, a[nmax]; ll t[nmax], res[nmax], S;

main(){
    freopen("shops.inp", "r", stdin);
    freopen("shops.out", "w", stdout);

    cin >> n >> S;
    f1(i, n) cin >> a[i];
    f1(i, n) t[i] = t[i-1] + a[i];

    res[0] = 0;
    f1(i, n) res[i] = max(res[i-1], t[i]);

    int val = 0; int k = 100000000;
    f1(i, n){
        int l = 0, r = i, ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(S - t[i] + res[mid]>=0){
                ans = mid; r = mid - 1;
            }
            else l = mid + 1;
        }
        if(val < i-ans){
            val = i - ans;
            k = ans + 1;
        }
        else{
            if(val==i-ans && k>ans+1) k = ans + 1;
        }
    }
    cout << val << " " << k;
}
