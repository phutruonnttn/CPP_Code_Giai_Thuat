#include <bits/stdc++.h>
#define nmax 300007

using namespace std;

long n,m,kq[nmax],next[nmax],l,r,x;

long get_next(long v)
{
    if(next[v]==v) return v;
    return next[v]=get_next(next[v]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Knight Tournament.inp","r",stdin);
    freopen("Knight Tournament.out","w",stdout);
    cin >> n >> m;
    for (long i=1; i<=n+1; i++) next[i]=i;
    for (long i=1; i<=m; i++)
    {
        cin >> l >> r >> x;
        l=get_next(l);
        while (l<=r)
         {
            if (l==x) l++;
            else
            {
                kq[l]=x;
                next[l]=l+1;
            }
            l=get_next(l);
            //cout << l << endl;
         }

        /*for (long j=1; j<=n; j++) cout << next[j] << " "; cout << endl;
        for (long j=1; j<=n; j++) cout << kq[j] << " "; cout << endl <<endl;*/
        //return 0;
    }
    for (long i=1; i<=n; i++) cout << kq[i] << " ";
}
