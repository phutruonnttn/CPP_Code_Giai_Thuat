#include <bits/stdc++.h>

using namespace std;

long n,a[10007],l[10007],r[10007];
stack <long> sl,sr;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("t5.inp","r",stdin);
    freopen("t5.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];

    for (long i=1; i<=n; i++)
    {
        while (!sl.empty() && a[sl.top()]<=a[i]) sl.pop();
        if (sl.empty()) l[i]=0;
        else l[i]=sl.top();
        sl.push(i);
    }

    for (long i=n; i>=1; i--)
    {
        while (!sr.empty() && a[sr.top()]<=a[i]) sr.pop();
        if (sr.empty()) r[i]=0;
        else r[i]=sr.top();
        sr.push(i);
    }

    cout << l[4] << " " << r[4];
}
