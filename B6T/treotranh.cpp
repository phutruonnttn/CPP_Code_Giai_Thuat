#include <bits/stdc++.h>

using namespace std;

long a1,a2,a3,b1,b2,b3,a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("treotranh.inp","r",stdin);
    freopen("treotranh.out","w",stdout);
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    a=a2+a3; b=max(b2,b3);
    if (a<=a1 && b<=b1)
    {
        cout << "YES";
        return 0;
    }
    if (a<=b1 && b<=a1)
    {
        cout << "YES";
        return 0;
    }

    a=a2+b3; b=max(b2,a3);
    if (a<=a1 && b<=b1)
    {
        cout << "YES";
        return 0;
    }
    if (a<=b1 && b<=a1)
    {
        cout << "YES";
        return 0;
    }

    a=b2+a3; b=max(a2,b3);
    if (a<=a1 && b<=b1)
    {
        cout << "YES";
        return 0;
    }
    if (a<=b1 && b<=a1)
    {
        cout << "YES";
        return 0;
    }

    a=b2+b3; b=max(a2,a3);
    if (a<=a1 && b<=b1)
    {
        cout << "YES";
        return 0;
    }
    if (a<=b1 && b<=a1)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}
