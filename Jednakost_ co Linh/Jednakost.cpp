#include <bits/stdc++.h>
#define nmax 5007
#define vc 999999999

using namespace std;

long long n,s,m[nmax][nmax],pre[nmax];
char a[nmax];
bool ok=true;

//f[i][sum] la so cach chen phep cong it nhat neu da chen den so thu i va co tong la sum
long long f(long i, long sum)
{
    if (i==n) return (sum==0) ? 0 : vc;
    if (sum<0) return vc;
    long res=m[i][sum];
    if (res!=-1) return res;
    long so=0; res=vc;
    for (long j=pre[i]; j<n; ++j)
    {
        so=so*10+a[j]-48;
        if (so>sum) break;
        if (res>1+f(j+1,sum-so)) res=1+f(j+1,sum-so);
    }
    m[i][sum]=res;
    return res;
}

long long solve(long i, long sum)
{
    if (!ok) return 0;
    if (i==n)
    {
        printf("=%lld\n",s);
        ok=false;
        return 1;
    }
    if (!ok) return 0;
    if (i>0) printf("+");
    long so=0;
    for (long j=i; j<n; ++j)
    {
        printf("%c",a[j]);
        so=so*10+a[j]-48;
        if (so>sum) break;
        if (f(i,sum)==f(j+1,sum-so)+1) return solve(j+1,sum-so);
    }
    if (!ok) return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Jednakost.inp","r",stdin);
    freopen("Jednakost.out","w",stdout);
    scanf("%[^=]=%lld",a,&s);
    n=strlen(a);
    pre[n-1]=n-1;
    for (long i=n-2; i>=0; --i)
       pre[i] = (a[i]=='0') ? pre[i+1] : i;
    memset(m,-1,sizeof(m));
    solve(0,s);
}
