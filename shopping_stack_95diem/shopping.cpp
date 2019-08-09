#include <bits/stdc++.h>
#define nmax 200007

using namespace std;

long long n,m,p[nmax],ri[nmax];
stack <long long> s;

void xuli()
{
   for (long i=n; i>=1; i--)
    {while (!s.empty() && p[s.top()]>=p[i])
      s.pop();
    if (s.empty()) ri[i]=0;
    else ri[i]=s.top();
    s.push(i);}
}


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("shopping.inp","r",stdin);
    freopen("shopping.out","w",stdout);
    cin >> n >> m;
    for (long long i=1; i<=n; i++) cin >> p[i];
    xuli();
    for (long long i=1; i<=m; i++)
    {
        long long t,l,r;
        cin >> t >> l >> r;
        t=t-p[l]*(t/p[l]);
        bool ok=true;
        while (ok)
        {
            if (l==0 || l>r) break;
            l=ri[l];
            if (l==0 || l>r) break;
            if (p[l]<=t) t=t-p[l]*(t/p[l]);
        }
        cout << t << '\n';
    }
}
