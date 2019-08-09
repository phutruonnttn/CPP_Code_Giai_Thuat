#include <bits/stdc++.h>

using namespace std;

long n,vt1[27],vt2[27],f[27][1<<23];
bool sau[27][27];

long getbit(long k, long x)
{
    return ((x>>k)&1);
}

void batbit(long k, long &x)
{
    x=x|(1<<k);
}

long long tinh(long i, long x)
{
    if (i>n) return 1;
    if (f[i][x]!=-1) return f[i][x];
    f[i][x]=0;
    for (long u=1; u<=n; u++)
      if (getbit(u-1,x)==0)
      {
          bool ok=true;
          for (long v=1; v<=n; v++)
            if (getbit(v-1,x)==1 && sau[u][v])
              {ok=false; break;}
          if (!ok) continue;
          long newx=x;
          batbit(u-1,newx);
          f[i][x]+=tinh(i+1,newx);
      }
    return f[i][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("genetic.inp","r",stdin);
    freopen("genetic.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
    {
        long a; cin >> a;
        vt1[a]=i;
    }
    for (long i=1; i<=n; i++)
    {
        long a; cin >> a;
        vt2[a]=i;
    }
    memset(sau,false,sizeof(sau));
    for (long i=1; i<=n; i++)
       for (long j=0; j<=1<<(n+1); j++)
          f[i][j]=-1;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
        if (vt1[i]<vt1[j] && vt2[i]<vt2[j])
            sau[i][j]=true;
    cout << tinh(1,0);
}
