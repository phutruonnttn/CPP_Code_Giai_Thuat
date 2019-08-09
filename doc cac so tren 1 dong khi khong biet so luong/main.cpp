#include <bits/stdc++.h>

using namespace std;

long a[100];

int main()
{
    freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    string st;
    getline(cin, st); //cout << st << endl;
    stringstream scin(st);
    long k=0, x;
    while (scin >> x) a[++k] = x;
    for (long i=1; i<=k; i++) cout << a[i] << " ";
}
