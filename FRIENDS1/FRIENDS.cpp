#include <bits/stdc++.h>

using namespace std;
const long long b=643, m=1000000000+7,m2=m*m;

long n;
string x,ans;
long long h[2000007],s[20000007];

long long get(long l, long r)
{
    return ((s[r]-s[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    freopen("FRIENDS.inp","r",stdin);
    freopen("FRIENDS.out","w",stdout);
    cin >> x;
    n=x.size();
    h[0]=1; h[1]=b;
    for (long i=2; i<=n; i++)
        h[i]=(h[i-1]*b) % m;
    /*s[0]=(x[0]) % m;
    for (long i=1;i<=n-1; i++)
        s[i]=((s[i-1]*b)+x[i]) % m;*/
    //cout << x;
    long d=0; string xx;
    for (long i=0; i<=n-1; i++)
    {
        xx=x;
        xx.erase(i,1);
        //cout << xx << endl;

        s[0]=(xx[0]) % m;
        for (long j=1;j<=n-2; j++)
           s[j]=((s[j-1]*b)+xx[j]) % m;

        if (get(0,((n-1) / 2)-1)==get(((n-1) / 2),n-2))
        {
            d++;
            ans=xx.substr(0,(n-1) / 2);
        }
    };
    if (d==1) cout << ans;
    else
     if (d==0) cout << "NOT POSSIBLE";
       else cout << "NOT UNIQUE";
}
