#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 21

using namespace std;
typedef long long ll;

ll f[nmax][11][11][2][2][2], c = 0, n;
string a, b;

ll calc(int i, int k1, int k2, bool ok1, bool ok2, bool ok3){
    if(f[i][k1][k2][ok1][ok2][ok3]!=-1) return f[i][k1][k2][ok1][ok2][ok3];
    if(i>n){
        f[i][k1][k2][ok1][ok2][ok3] = 1;
        return 1;
    }
    ll ans = 0;
    f0(j, 10){
        if((j!=k2 && j!=k1)){
            if(((j>=a[i]-48) || ok1) && ((j<=b[i]-48) || ok2)){
                if(ok3==0 && j==0)
                    ans = ans + calc(i+1, k2, 10, (ok1 || j>a[i]-48), (ok2 || j<b[i]-48), 0);

                if(ok3==0 && j!=0){
                    ans = ans + calc(i+1, k2, j, (ok1 || j>a[i]-48), (ok2 || j<b[i]-48), (ok3 || j>0));

                }
                if(ok3){
                    ans = ans + calc(i+1, k2, j, (ok1 || j>a[i]-48), (ok2 || j<b[i]-48), (ok3 || j>0));
                }
            }
        }
    }
    f[i][k1][k2][ok1][ok2][ok3] = ans;
    return f[i][k1][k2][ok1][ok2][ok3];
}

main(){
    freopen("A.inp", "r", stdin);
    freopen("A.out", "w", stdout);

    n = 19;
    cin >> a >> b;
    f0(i1, nmax){
        f0(i2, 11){
            f0(i3, 11){
                f0(i5, 2){
                    f0(i6, 2) f[i1][i2][i3][i5][i6][0] = f[i1][i2][i3][i5][i6][1] = -1;
                }
            }
        }
    }

    while(a.length()<19) a = "0" + a;
    while(b.length()<19) b = "0" + b;
    a = "0" + a; b = "0" + b;

    ll ans = calc(1, 10, 10, 0, 0, 0);

    cout << ans;
}
