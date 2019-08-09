#include "network.h"
#include <bits/stdc++.h>
using namespace std;

void findRoute (int n, int a, int b) {

    /*long d[2007],tr[2007];
    typedef pair <int,int> ii;
    priority_queue <ii> pq;
    fill(d,d+n+1,1e9);
    d[a]=0;
    pq.push(ii(0,a));

    long u,du;
    while (!pq.empty())
    {
        u=pq.top().second;
        du=-pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (long i=1;i<=n;i++)
          if (i!=u)
          {
            long v=i;
            long wv=ping(u,i);
            if (d[v]>d[u]+wv)
            {
                d[v]=d[u]+wv;
                tr[v]=u;
                pq.push(ii(-d[v],v));
            }
          }
    }
    long bb[2007],dem=0;
    while (b!=a)
    {
        bb[++dem]=b;
        b=tr[b];
    }
    for (long i=dem; i>=1; i--) travelTo(bb[i]);*/

}
