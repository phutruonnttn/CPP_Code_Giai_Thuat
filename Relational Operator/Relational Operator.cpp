#include <bits/stdc++.h>

using namespace std;

long long t,a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("Relational Operator.inp","r",stdin);
    //freopen("Relational Operator.out","w",stdout);
    cin >> t;
    for (long i=1; i<=t; ++i)
    {
        cin >> a >> b;
        if (a>b) cout << ">" << '\n';
        else if (a==b) cout << "=" << '\n';
        else cout << "<" << '\n';
    }
}
