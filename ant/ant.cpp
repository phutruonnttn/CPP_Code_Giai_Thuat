#include <bits/stdc++.h>

using namespace std;
typedef pair <pair <int,int>, int> ii;

int c,s;
long long ans=0;
int a[20007][20007];

void loang(int xx,int yy)
{
    queue <ii> q;
    q.push(make_pair(make_pair(xx,yy),0));
    while(!q.empty())
    {
       int xo=q.front().first.first, yo=q.front().first.second;
       int buoc=q.front().second;
       q.pop();
       if (buoc>s || a[xo][yo]==1) continue;
       if (a[xo][yo]!=1) ans++;
       a[xo][yo]=1;
       if (buoc+1<=s)
       {
         if (a[xo+1][yo]==0) {a[xo+1][yo]=2; q.push(make_pair(make_pair(xo+1,yo),buoc+1));};
         if (a[xo][yo+1]==0) {a[xo][yo+1]=2; q.push(make_pair(make_pair(xo,yo+1),buoc+1));};
         if (a[xo-1][yo]==0) {a[xo-1][yo]=2; q.push(make_pair(make_pair(xo-1,yo),buoc+1));};
         if (a[xo][yo-1]==0) {a[xo][yo-1]=2; q.push(make_pair(make_pair(xo,yo-1),buoc+1));};
       }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ant.inp","r",stdin);
    freopen("ant.out","w",stdout);
    cin >> c >> s;
    for (int i=1 ; i<=c; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x+s][y+s]=1;
    }
    loang(s,s);
    cout << ans;
}
