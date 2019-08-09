#include <bits/stdc++.h>

using namespace std;
const long long b=379, m=1000000000+7,m2=m*m;

string t;
long long n;
string ss[107];
long long h[1000007],s[10000007],hashss[107];
map <string,long> M;

long long get(long long l, long long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    fstream fi,fo;
    fi.open("find_patterns.inp",ios::in);
    fo.open("find_patterns.out",ios::out);
    getline(fi,t);
    fi >> n;
    for (long i=1; i<=n; i++)
        fi >> ss[i];

    h[0]=1; h[1]=b;
    long long nn=t.size();
    for (long i=2; i<=nn; i++)
        h[i]=(h[i-1]*b) % m;
    s[0]=(t[0]) % m;
    for (long i=1;i<=nn-1; i++)
        s[i]=((s[i-1]*b)+t[i]) % m;

    for (long i=1; i<=n; i++)
    {
       hashss[i]=ss[i][0];
       for (long j=1; j<=ss[i].size()-1; j++)
          hashss[i]=(hashss[i]*b+ss[i][j]) % m;
    }
    /*for (long i=1; i<=n; i++)
        fo << hashss[i] << endl; fo << get(0,1);*/

    long long ans=0;

    for (long i=1; i<=n; i++)
     if (M[ss[i]]!=111)
     {
         M[ss[i]]=111;
         long long dd=ss[i].size();
         for (long j=0; j<=nn-1; j++)
           if (t[j]==ss[i][0])
             if (get(j,j+dd-1)==hashss[i]) ans++;
     }
     fo << ans;
}
