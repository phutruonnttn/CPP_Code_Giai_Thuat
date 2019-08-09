#include <bits/stdc++.h>

using namespace std;

long n,m,w,a[207][207];
stack <long> s;

void euler(long uu)
{
    stack <long> s;
    s.push(uu);
    while (!s.empty())
    {
        long u=s.top();
        bool kt=true;
        for (long v=1; v<=n; v++)
          if (a[u][v]==1)
          {
             a[u][v]=0;
             a[v][u]=0;
             kt=false;
             s.push(v);
             break;
          }
        if (kt)
        {
            cout << u << " ";
            s.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKPOS.inp","r",stdin);
    freopen("NKPOS.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w;
    for (int i=1;i<=m;i++)
    {
        long u,v;
        cin >> u >> v;
        a[u][v]++;
        a[v][u]++;
    }
    cout << m << endl;
    euler(1);
    /*s.push(1);
    while (!s.empty())
    {
        long u = s.top();
        bool kt = true;
        for (int v=1;v<=n;v++)
          if (a[u][v] > 0)
            {
                a[u][v]--;
                a[v][u]--;
                kt = false;
                s.push(v);
                break;
            }
        if (kt)
        {
            cout << u << " ";
            s.pop();
        }
    }*/
    return 0;
}
