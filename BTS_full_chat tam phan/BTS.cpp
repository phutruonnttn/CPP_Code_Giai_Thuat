#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std ;

const double eps = 1e-6;

struct point
{
  double x, y ;
  point() {}
  point(double x, double y) : x(x), y(y) {}
} ;

int n ;
point a[500010] ;
point u, v ;

inline double f(const double &X)
{
  double Y = (v.y - u.y) / (v.x - u.x) * (X - u.x) + u.y ;
  double ans = 0 ;
  for(int i = 1; i <= n; ++i) ans = max(ans, sqrt((X - a[i].x) * (X - a[i].x) + (Y - a[i].y) * (Y - a[i].y))) ;
  return ans ;
}

main()
{
  freopen("BTS.INP", "r", stdin) ;
  freopen("BTS.OUT", "w", stdout) ;
  scanf("%d", &n) ;
  for(int i = 1; i <= n; ++i) scanf("%lf %lf", &a[i].x, &a[i].y) ;
  scanf("%lf %lf %lf %lf", &u.x, &u.y, &v.x, &v.y) ;
  if(u.x == v.x)
  {
    for(int i = 1; i <= n; ++i) swap(a[i].x, a[i].y)  ;
    swap(u.x, u.y) ;
    swap(v.x, v.y) ;
  }
  double l = u.x, r = v.x, m ;
  if(l > r) swap(l, r) ;
  l = -1e9 - 7 ; r = 1e9 + 7 ;
  while(r - l > eps)
  {
    double L = l + 4 * (r - l) / 9 ;
    double R = l + 5 * (r - l) / 9 ;
    if(f(L) <= f(R)) r = R ;
    else l = L ;
  }
  printf("%0.4f", f((l + r) / 2)) ;
  return 0 ;
}
