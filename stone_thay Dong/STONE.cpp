#include <bits/stdc++.h>

using namespace std;

long te,n,k,s[107],l[3][100007];

long play(long p, long t)
{
    if (l[p][t]!=-1) return l[p][t];
    long r=0;
    for (long i=0; i<k; i++)
      if ((t>=s[i]) && (play(1-p,t-s[i])==0))
      {
          r=1;
          break;
      }
    l[p][t]=r;
    return r;
}

void sub1()
{
    memset(l,-1,sizeof(l));
    if (play(0,n)==1) cout << "YES" << '\n'; else cout << "NO" << '\n';
}

void sub2()
{
    if (n%(k+1)) cout << "YES" << '\n'; else cout << "NO" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("STONE.inp","r",stdin);
    freopen("STONE.out","w",stdout);
    cin >> te;
    for (long tt=1; tt<=te; tt++)
    {
        cin >> n >> k;
        for (long i=0; i<k; i++) cin >> s[i];
        if (n<=100000) sub1();
        else sub2();
    }
}
