#include <bits/stdc++.h>
#define nmax 50007
#define nmod 1000000007

using namespace std;

long long n,f[nmax],t[nmax];
string s;

/*void khoitao(string s, long n)
{
    t[0]=-1; t[1]=0;
    long pos=2, cnd=0;
    while (pos<n)
    {
        if (s[pos-1]==s[cnd])
        {
            t[pos]=cnd+1;
            pos++; cnd++;
        }
        else
        if (cnd>0) cnd=t[cnd];
        else
        {
            t[pos]=0;
            pos++;
        }
    }
}*/

void khoitao(string s, long n)
{
    t[0]=-1; t[1]=0;
    for (long i=2; i<=n; i++)
    {
        long l=t[i-1];
        while (l!=-1 && s[l+1]!=s[i]) l=t[l];
        t[i]=l+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("WORDS.inp","r",stdin);
    freopen("WORDS.out","w",stdout);
    cin >> n;
    cin >> s;
    long long k=s.size();
    s="*"+s;
    khoitao(s,k);
    f[k]=1;
    for (long i=k+1; i<=n; i++)
       for (long l=1; l<=k; l++)
         if (t[l]==0) f[i]=(f[i]+f[i-l])%nmod;
    cout << f[n]%nmod;
}
