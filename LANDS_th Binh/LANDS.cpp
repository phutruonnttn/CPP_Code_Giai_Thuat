#include <bits/stdc++.h>
#define nmax 1007
#define fore(i1,a,b) for (long i1=a; i1<=b; ++i1)
#define vc 9999999999

using namespace std;

long long n,x,y,z,p[nmax],q[nmax],f[nmax][nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("LANDS.inp","r",stdin);
    freopen("LANDS.out","w",stdout);
    cin >> n >> x >> y >> z;
    long long dp=0,dq=0;
    fore(i,1,n)
    {
        long u,v;
        cin >> u >> v;
        for (long j=1; j<=u; j++) p[++dp]=i;
        for (long j=1; j<=v; j++) q[++dq]=i;
    }

    //for (long i=1; i<=dp; i++) cout << p[i] << " " ; cout << endl;
    //for (long i=1; i<=dq; i++) cout << q[i] << " " ; cout << endl;

    fore(i,1,dp) f[i][0]=y*i;
    fore(i,1,dq) f[0][i]=x*i;
    f[0][0]=0;
    fore(i,1,dp)
      fore(j,1,dq)
        {
            f[i][j] = min(min(f[i-1][j] + y,f[i][j-1] + x),f[i-1][j-1] + z*abs(p[i] - q[j]));
            if (p[i]==q[j]) f[i][j]=min(f[i-1][j-1],f[i][j]);
        }
    cout << f[dp][dq];
}
