#include <bits/stdc++.h>
#define nmax 3000007
#define vc 99999999999

using namespace std;

long long n,t,a[nmax],dmax[4*nmax],dmin[4*nmax],ans=0;

void build1(long node,long L,long R)
{
    if (L==R)
    {
        dmax[node]=a[L];
        return;
    };
    long mid=(L+R) /2;
    build1(node*2,L,mid);
    build1(node*2+1,mid+1,R);
    dmax[node]=max(dmax[node*2],dmax[node*2+1]);

}

long long get1(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dmax[id];
    if ((L>v) || (R<u)) return -1;
    long mid=(L+R) /2 ;
    long long x1=get1(id*2,L,mid,u,v);
    long long x2=get1(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void build2(long node,long L,long R)
{
    if (L==R)
    {
        dmin[node]=a[L];
        return;
    };
    long mid=(L+R) /2;
    build2(node*2,L,mid);
    build2(node*2+1,mid+1,R);
    dmin[node]=min(dmin[node*2],dmin[node*2+1]);

}

long long get2(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return dmin[id];
    if ((L>v) || (R<u)) return vc;
    long mid=(L+R) /2 ;
    long long x1=get2(id*2,L,mid,u,v);
    long long x2=get2(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Fgarden.inp","r",stdin);
    freopen("Fgarden.out","w",stdout);
    cin >> n >> t;
    long dem=0;
    for (long i=1; i<=n; i++)
    {
        cin >> a[i];
        if (a[i]!=0) dem++;
        else break;
    }
    n=dem;
    build1(1,1,n); build2(1,1,n);
    long long j=1;
    for (long long i=1; i<=n; i++)
    {
          if (j<i) j=i;
          long long minn=get2(1,1,n,i,j), maxx=get1(1,1,n,i,j);
          while (abs(maxx-minn)<=t)
          {
              ans=max(ans,j-i+1);
              //cout << j-i+1 << " " << i << " " << j << " " << minn << " " << maxx << endl;
              if (j==n) break;
              if (j+1<=n)
              {
                  j++;
                  maxx=max(maxx,a[j]);
                  minn=min(minn,a[j]);
              }
          }
    }
    cout << ans;
}
