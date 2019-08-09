#include <bits/stdc++.h>

using namespace std;

void doc(long long &k)
{
    k=0;

    char ch;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) k=(k<<3)+(k<<1)+ch-48;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("a.inp","r",stdin);
    string c;
    /*c=getchar();
    while (c!='-')
    {
        cout << c;
        c=getchar();
    }*/
    long long k,q;
    doc(k); doc(q);
    doc(k); doc(q);
    cout << k << " " << q;
}
