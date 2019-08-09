#include <bits/stdc++.h>
#define nmod 1000000000

using namespace std;

long m,n,k,x[10007];
long long ans;
bool hash[100000000];

void ktra()
{
    long long s=0,shash=0;
    for (long i=1; i<=m;i++)
       s+=x[i];
    if (s==n)
    {
        for (long i=1; i<=m; i++)
            shash=(shash+x[i]*abs(37-x[i])*abs(47-x[i])*abs(57-x[i])) % nmod;
        if (hash[shash]==false) ans++;
        hash[shash]=true;
    }
}

void tinh(long i)
{
    for (long j=0; j<=k;j++)
    {
        x[i]=j;
        if (i==m) ktra();
        else tinh(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("GAME.inp","r",stdin);
    freopen("GAME.out","w",stdout);
    cin >> n >> m >> k;
    if (n>m*k) cout << 0;
    else
     if (n==m*k) cout << 1;
       else
       {
           ans=0;
           memset(hash,false,sizeof(hash));
           tinh(1);
           cout << ans;
       }
}
