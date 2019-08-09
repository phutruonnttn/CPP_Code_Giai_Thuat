#include <bits/stdc++.h>
#define maxm 17
#define maxn 1005
#define oo 2000000000

using namespace std;

int n, m;
char s[maxm][maxn];
int a[maxm][maxm];
int nho[1<<maxm][maxm], dp[1<<maxm][maxm];

int calc(int y,int j) {
    if (y==(1<<(m-1))) return 0;
    if (y==(1<<(j-1))) return oo;
    if (nho[y][j]) return dp[y][j];
    nho[y][j]=1; dp[y][j]=oo;
    int x=y^(1<<(j-1));
    for(int i=1;i<=m;++i) if ((x>>(i-1)) & 1) {
        int t=calc(x,i);
        dp[y][j]=min(dp[y][j],t+a[i][j]);
    }
    return dp[y][j];
}

int main() {
    freopen("garlan.inp","r",stdin);
    freopen("garlan.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%s",s[i]);
    for(int i=1;i<=m;++i)
    for(int j=i;j<=m;++j) {
        a[i][j]=0;
        for(int u=0;u<n;++u) if (s[i][u]!=s[j][u]) ++a[i][j];
        a[j][i]=a[i][j];
    }
    for(int i=1;i<=m;++i) {
        a[i][m+1]=a[m+1][i]=0;
        for(int u=0;u<n;++u) if (s[i][u]=='1') a[i][m+1]++, a[m+1][i]++;
    }
    memset(nho,0,sizeof(nho));
    ++m;
    int ds=oo;
    for(int i=1;i<m;++i) {
        int t=calc((1<<m)-1,i);
        ds=min(ds,t);
    }
    printf("%d",ds);
}
