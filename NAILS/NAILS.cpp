#include <bits/stdc++.h>
#define nmax 500007

using namespace std;

long long t,n,m,l[nmax],d[4*nmax];
long long s[nmax],ans1,ans2;

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=l[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=min(d[node*2],d[node*2+1]);

}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 10000000000;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void sub1()
{
   ans1=-1;
   long long min1;
   for (long i=1; i<=n-1; i++)
     {
        min1=l[i];
        for (long j=i+1; j<=n; j++)
          {
             min1=min(min1,l[j]);
             long long sld=s[j]-s[i-1]-(j-i+1)*min1;
             if (j-i+1>=ans1 && sld<=m)
              {
                  if (ans1==j-i+1)
                  {
                      ans2=min(sld,ans2);
                  }
                  else
                  {
                      ans1=j-i+1;
                      ans2=sld;
                  }
               }
           }
      }
   cout << ans1 << " " << ans2 << endl;
}

void sub2()
{
    build(1,1,n);
    ans1=-1; ans2=-1;
    long ri=2;
    long long minn=(l[1],l[2]);
    for (long le=1;le<=n-1;le++)
    {
       while (1<2)
       {
           long long stl=s[ri]-s[le-1]-(ri-le+1)*minn ;
           if (stl<=m)
           {
             if (ans1<=ri-le+1)
             {
                 if (ans1==ri-le+1)
                  {
                      ans2=min(stl,ans2);
                  }
                 else
                  {
                      ans1=ri-le+1;
                      ans2=stl;
                  }
             }
             ri++;minn=min(minn,l[ri]);
             if (ri>n) break;
           }
           else {minn=get(1,1,n,le+1,ri);break;}
       }
    }
    cout << ans1 << " " << ans2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NAILS.inp","r",stdin);
    freopen("NAILS.out","w",stdout);
    cin >> t;
    for (long q=1; q<=t; q++)
    {
        cin >> n >> m;
        s[0]=0;
        for (long i=1; i<=n; i++) {cin >> l[i];s[i]=s[i-1]+l[i];}
        if (n<10000) sub1();
        else sub2();
    }
}
