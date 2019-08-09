#include <bits/stdc++.h>
#define maxn 3000
#define INF 1000000000000000LL

using namespace std;

int n, k;
int a[maxn][maxn];
long long b[maxn][maxn];

int main() {
    freopen("mahatan.inp","r",stdin);
    freopen("mahatan.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) {
        int u=i-j+n, v=i+j;
        b[u][v]=a[i][j];
    }
    for(int i=1;i<=2*n-1;i++)
        for(int j=1;j<=2*n;j++) b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
    long long ds=-INF;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) {
        int u=i-j+n,v=i+j;
        int u1=max(1,u-k), v1=max(1,v-k);
        int u2=min(2*n-1,u+k), v2=min(2*n,v+k);
        ds=max(ds,b[u2][v2]-b[u1-1][v2]-b[u2][v1-1]+b[u1-1][v1-1]);
    }
    printf("%I64d",ds);
}
