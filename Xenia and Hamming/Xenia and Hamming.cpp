#include <bits/stdc++.h>

using namespace std;

long long n,m;
string x,y;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Xenia and Hamming.inp","r",stdin);
    freopen("Xenia and Hamming.out","w",stdout);
    cin >> n >> m;
    cin >> x;
    cin >> y;
    long long sx=x.size(),sy=y.size();
    long long cc=sx*sy/(__gcd(sx,sy));
    string ct1,ct2;
    for (long long i=1; i<=cc/sx; i++) ct1+=x;
    for (long long i=1; i<=cc/sy; i++) ct2+=y;
    long long dem=0;
    for (long long i=0; i<=cc-1; i++)
       if (ct1[i]!=ct2[i]) dem++;
    cout << dem*(n*sx/cc);
}
