#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,m,h[nmax],w[nmax],dp[nmax],q[nmax],sumw[nmax];
multiset <long long> ms;

void doc(long long &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;
    if (ktAm) n=-n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CUTSEQS.inp","r",stdin);
    freopen("CUTSEQS.out","w",stdout);
    //doc(n); doc(m);
    cin >> n >> m;//doc bang cin, cout moi full
    for (long i=1; i<=n; i++)
    {
        //doc(w[i]);
        cin >> w[i];
        if (w[i]>m)
        {
            cout << -1;
            return 0;
        }
        h[i]=w[i];
    }
    for (long i=1; i<=n; i++) sumw[i]+=sumw[i-1]+w[i];
    long long sum=0,bd=1,kt=0,k=0;
    //q la dequeue
    for (long i=1; i<=n; i++)
    {
        q[++kt] = i - 1;
        while (bd < kt && h[i] >= h[q[kt]])
        {
            ms.erase(ms.find(dp[q[kt-1]]+h[q[kt]]));
            kt--;
        }
        ms.insert(dp[q[kt]] + h[i]);
        q[kt+1]=i;
        for (sum += w[i]; sum > m; sum -= w[q[bd]])
        {
           ms.erase(ms.find(dp[q[bd]] + h[q[bd+1]]));
           if(++q[bd]==q[bd+1]) bd++;
           else ms.insert(dp[q[bd]] + h[q[bd+1]]);
        }
        dp[i] = *ms.begin();
    }
    cout << dp[n] << endl;
}
