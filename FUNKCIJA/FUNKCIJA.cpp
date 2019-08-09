#include <bits/stdc++.h>

using namespace std;

long n;
long long ans=0;
string chiso1[30],chiso2[30];
char bien[27]={'.','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

long long xd(string s)
{
    if ('a'<=s[0] && s[0]<='z') return bien[(long)s[0]-96];
    long long kq=0;
    for (long i=0; i<=s.size()-1; i++)
        kq=kq*10+(long)(s[i]-48);
    return kq;
}

void tinh(long i)
{
    for (bien[i]=xd(chiso1[i]); bien[i]<=xd(chiso2[i]); bien[i]++)
    {
        if (i==n) ans++; else tinh(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("FUNKCIJA.inp","r",stdin);
    freopen("FUNKCIJA.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> chiso1[i] >> chiso2[i];

    /*for (long a=1; a<=2; a++)
        for (long b=a; b<=3; b++)
            for (long c=a; c<=b; c++)
              ans++;*/

    tinh(1);
    cout << ans;
}
