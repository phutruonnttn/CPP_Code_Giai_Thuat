#include <bits/stdc++.h>
#define nmod 1000000007

using namespace std;

long long n1,n2,tinh[3000007];
string w,s;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("WRITING.inp","r",stdin);
    freopen("WRITING.out","w",stdout);
    cin >> n1 >> n2;
    cin >> w;
    cin >> s;
    long long rb=0;
    for (long i=0; i<=n1-1;i++) rb=(rb+(w[i]-64)*(w[i]-57)*(w[i]-47)*(w[i]-37)*(w[i]-17)) % nmod;

    for (long i=0;i<=n2;i++) tinh[i+1]=(tinh[i]+(s[i]-64)*(s[i]-57)*(s[i]-47)*(s[i]-37)*(s[i]-17)) % nmod;

    long long ans=0;

    for (long i=1; i<=n2-n1+1;i++)
    {
        long long tmp=(tinh[i+n1-1]-tinh[i-1]+nmod) % nmod;
        if (tmp==rb) ans++;
    }
    cout << ans;

}
