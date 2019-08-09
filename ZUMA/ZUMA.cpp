#include <bits/stdc++.h>

using namespace std;

long n,k,a[107],f[107][107][107];

long tinh(long l, long r, long c)
{
   if (l>r) return 0;
   if (l==r) return k-1-c;
   if (f[l][r][c]!=-1) return f[l][r][c];
   f[l][r][c]=1000000000;
   if (c<k-1) f[l][r][c]=tinh(l,r,c+1)+1;
   if (c==k-1) f[l][r][c]=tinh(l+1,r,0);
   for (long j=l+1; j<=r; j++)
   {
       if (a[l]!=a[j]) continue;
       long v=tinh(l+1,j-1,0)+tinh(j,r,min(c+1,k-1));
       f[l][r][c]=min(f[l][r][c],v);
   }
   return f[l][r][c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("ZUMA.inp","r",stdin);
    //freopen("ZUMA.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n; i++)
        cin >> a[i];
    memset(f,-1,sizeof(f));
    cout << tinh(1,n,0);
}
