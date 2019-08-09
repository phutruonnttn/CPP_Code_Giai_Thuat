#include <bits/stdc++.h>
#define maxn 100005
#define oo 100000009

using namespace std;

pair <long long  ,long long  > d[maxn];
vector <pair < long, long long  > > a[maxn];
int n, m;

void IJK()
{
  priority_queue <pair < pair< long long  ,long long  >  , long > > q;
  q.push(make_pair(make_pair(0, oo) , 1));
  for(long i= 1; i<= n;i++) d[i] = make_pair(oo,oo);
  d[1].first = 0;
  while(!q.empty())
  {
    pair <long long , long long  >  w = q.top().first;
    long v = q.top().second;
    q.pop();
    if (d[v].first < -w.first && d[v].second < -w.second) continue;
    for(long i= 0; i<a[v].size(); i++)
    {
      long u= a[v][i].first;
      long long  ww = a[v][i].second ;
      long long  d1 = ww + d[v].first;
      long long  d2 = ww + d[v].second;
      int ok = 0;

      if (d[u].second > d2 && d2 != d[u].first)
      {
        d[u].second =d2;
        ok = 1;
      };
      if(d[u].first > d[u].second) swap(d[u].first, d[u].second);

      if (d[u].second > d1 && d1 != d[u].first)
      {
        d[u].second = d1;
        ok = 1;
      }

      if(d[u].first > d[u].second) swap(d[u].first, d[u].second);
      if (ok)
        q.push(make_pair(make_pair(-d[u].first, -d[u].second), u));
    }
  }
}

/*Thuật toán:
Quy hoạch động trên đồ thị sử dụng thuật toán dijktra.
	D[i].first là độ dài ngắn nhất từ 1 tới i;
	D[i].second là độ dài đường đi ngắn nhì tới i;

Cơ sở: D[1].first = 0, D[1].second = oo, D[i].first = D[i].second = oo (i : 2÷n)

Với u là đỉnh có D[u].first nhỏ nhất ta duyệt đến từng đỉnh v kề với u.
Với mỗi đỉnh v ta có thêm 2 trường hợp là đường đi được chọn là từ u đến v
Mỗi trường hợp xét xem đường đi mới có tối ưu hơn không và có bị trùng hay không.
Ta gọi thêm d1, d2 lầ độ dài đường đi ngắn nhất, ngắn nhì  dài đường đi từ u tới v. */

int main()
{
   ios_base::sync_with_stdio(0);
   freopen("SHORTEST.inp", "r", stdin);
   freopen("SHORTEST.out", "w", stdout);
   cin >> n >> m;
   for (long i= 1; i<= m; i++)
   {
      long x, y, z;
      cin >> x >> y >> z;
      a[x].push_back(make_pair(y, z));
   }

   IJK();

   if (d[n].second==oo) d[n].second=-1;
   cout << d[n].second ;
}

