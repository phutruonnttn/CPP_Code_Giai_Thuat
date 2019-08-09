#include <bits/stdc++.h>

using namespace std;

long long x,a,b,dd[17],m[17][100007][5];
string s;

long long mu(long k)
{
    long long res=1;
    for (long i=1; i<=k; i++)
        res*=10;
    return res;
}

bool ktra(long long y)
{
    while (y!=0)
    {
        long long thu=y%10;
        if (dd[thu]==0) return false;
        y/=10;
    }
    return true;
}

//f[n][p] la boi so cua x neu co n chu so, p la chu so da duoc dat
long long f(long n, long p)
{
    long long minn,maxx;
    if (p==0) minn=0, maxx=mu(n)-1;
    else minn=p*mu(n), maxx=p*mu(n)+mu(n)-1;

    if (maxx<a || minn>b) return 0;
    if (n==0) return p%x==0;
    long kt=(minn>=a && maxx<=b);
    if (kt && m[n][p%x][p==0]>=0) return m[n][p%x][p==0];
    long long tong=0;
    for (long d=0; d<=9; d++)
      if (dd[d]==1 || (d==0 && p==0))
         tong+=f(n-1,p*10+d);
    if (kt) m[n][p%x][p==0]=tong;
    return tong;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Boiso.inp","r",stdin);
    freopen("Boiso.out","w",stdout);
    cin >> x >> a >> b;
    cin >> s;
    for (long i=0; i<s.size(); i++)
        dd[s[i]-48]=1;
    if (x>b)
    {
        cout << 0;
        return 0;
    }
    if (b/x<=1000000)
    {
        long long v1=a/x, v2=b/x,ans=0;
        for (long i=v1; i<=v2; i++)
          if (x*i>=a && x*i<=b && ktra(x*i))
             ans++;
        cout << ans;
        return 0;
    }
    else
    {
        for (long i=0; i<=12; i++)
          for (long j=0; j<=100001; j++)
             for (long k=0; k<=2; k++)
               m[i][j][k]=-1;
        cout << f(11,0);
    }
}
