#include <bits/stdc++.h>
#define nmax 507
#define vc 999999999999999

using namespace std;

long long m,n,k,dd[nmax][nmax],f[nmax][nmax],sl[nmax];

long long xep(long long x, long long k)
{
    if (k==0) return x*(x+1)/2;
    k++; //k luot duoi thi se co k+1 luot nguoi o
    return (x%k)*(x/k+1)*(x/k+2)/2+(k-x%k)*(x/k+1)*(x/k)/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NOISE.inp","r",stdin);
    freopen("NOISE.out","w",stdout);
    cin >> n >> m >> k;
    for (long i=1; i<=n; i++)
    {
        long u; cin >> u;
        sl[u]++; //khong can quan tam thu tu vao cac phong, chi can quan tam den so luong nguoi moi phong
    }
    for (long i=1; i<=m; i++)
      for (long j=1; j<=k; j++)
        {
            f[i][j]=vc;
            dd[i][j]=xep(sl[i],j);
        }
    for (long i=1; i<=m; i++)
    {
        dd[i][0]=xep(sl[i],0);
        f[i][0]=f[i-1][0]+dd[i][0];
    }
    //f[i][j] la dap an toi uu den phong thu i va da dung j luot duoi
    //dd[i][j] la tong tieng on khi duoi phong i j lan
    f[0][0]=0;
    for (long i=1; i<=m; i++)
      for (long j=1; j<=k; j++)
        for (long i1=0; i1<=j; i1++)
          f[i][j]=min(f[i][j],f[i-1][j-i1]+dd[i][i1]);
    cout << f[m][k];
}
