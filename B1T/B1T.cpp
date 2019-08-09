#include <bits/stdc++.h>

using namespace std;

long long n,x,a[1000007];
vector <long long> slxh[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("bai1.inp","r",stdin);
    freopen("bai1.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) {cin >> a[i]; slxh[a[i]].push_back(i);};
    cin >> x;
    a[0]=10000000000;
    cout << slxh[x].size() << endl;
    if (slxh[x].size()!=0)
    {
        for (long i=0; i<slxh[x].size(); i++)
           cout << slxh[x][i] << " ";
        cout << endl;
        for (long i=0; i<slxh[x].size(); i++)
           cout << slxh[x][i] << " ";
    }
    else
    {
        a[++n]=x;
        sort(a+1,a+n+1);
        a[n+1]=10000000000;
        long vtx;
        for (long i=1; i<=n; i++) if (a[i]==x) vtx=i;
        if (abs(a[vtx]-a[vtx-1])>=abs(a[vtx]-a[vtx+1]))
        {
            for (long i=0; i<slxh[a[vtx+1]].size(); i++)
               cout << slxh[a[vtx+1]][i] << " ";
        }
        else
        {
            for (long i=0; i<slxh[a[vtx-1]].size(); i++)
               cout << slxh[a[vtx-1]][i] << " ";
        }
    }
}
