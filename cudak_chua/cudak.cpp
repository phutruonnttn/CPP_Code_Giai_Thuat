#include <bits/stdc++.h>

using namespace std;

long long a,b,s,d[20][200],minsol=-1;

long long power(long a)
{
    if (a==0) return 1;
    long long kq=1;
    for (long i=1; i<=a ; i++)
      kq=kq*10;
    return kq;
}

long long solve (long long p, long digit, long sum)
{
    if (sum<0) return 0;
    long long mi=p, ma=p+power(digit)-1;
    if (mi>b || ma<a) return 0;
    if (digit==0)
    {
        if (sum>0) return 0;
        if (minsol==-1) minsol=p;
        return 1;
    }
    bool kt=(mi>=a) && (ma<=b);
    if ((kt) && (d[digit][sum]!=-1)) return d[digit][sum];
    long long res=0;
    for (long di=0; di<=9; di++)
        res+=solve(p+di*power(digit-1),digit-1,sum-di);
    if (kt) d[digit][sum]=res;
    return res;

}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cudak.inp","r",stdin);
    freopen("cudak.out","w",stdout);
    cin >> a >> b >> s;
    memset(d,-1,sizeof(d));
    cout << solve(0,15,s)<<endl;
    cout<<minsol;
}
