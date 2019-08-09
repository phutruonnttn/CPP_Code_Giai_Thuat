#include <bits/stdc++.h>
#define int long long
#define nmax 100001
#define for(i, a, b) for(int i=(a); i<=(b); i++)

using namespace std;

int n, f[nmax], a[nmax], k;
map <int, int> g;

main(){
    freopen("CUBICS.inp", "r", stdin);
    freopen("CUBICS.out", "w", stdout);

    cin >> n >> k;
    f[0] = 0;
    for(i, 1, n){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    int res = 0; int u = 1e15;

    for(i, 1, n){
        if(f[i]==k*i){
            res = i;
            u = 1;
        }
    }
    for(i, 0, n){
        f[i] = f[i] - k*i;
        int h = g[f[i]];
        if(h){
            if(res<i-h){
                res = i - h;
                u = h + 1;
            }
            else if(res==i-h){
                if(u>h+1) u = h + 1;
            }
            continue;
        }
        g[f[i]] = i;
    }
    if(res==0){
        cout << 0;
        exit(0);
    }
    cout << res << " " << u;
}
