#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long n, a[nmax];

void quicksort(long l, long r)
{
    long i=l,j=r,g=a[(l+r)/2];
    while (i<=j)
    {
         while (a[i]<g) i++;
         while (a[j]>g) j--;
         if (i<=j)
          {
              if (i!=j) cout << i << " " << j << '\n';
              swap(a[i],a[j]);
              i++; j--;
          }
    }
    if (l<j) quicksort(l,j);
    if (i<r) quicksort(i,r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    quicksort(1,n);
}
