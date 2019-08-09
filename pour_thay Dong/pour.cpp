#include <bits/stdc++.h>

using namespace std;
typedef pair <long,long> ii;

struct data
{
    long w,id;
};

long dem=0,d[100000007],c[100000007];
bool dd[3007][3007];
data v[5];

/*void dfs(long a[])
{
    if (a[1]==0 || a[2]==0 || a[3]==0) return;
    if (!dd[a[1]][a[2]]) return;
    dd[a[1]][a[2]]=false;
    for (long i=1; i<=3; i++)
      for (long j=1; j<=3; j++)
        if (i!=j && v[i]>=v[j])
        {
           a[i]-=a[j];
           a[j]*=2;
           dem++;
           d[dem]=i;
           c[dem]=j;
           if (a[1]==0 || a[2]==0 || a[3]==0) return;
           if (dd[a[1]][a[2]]) dfs(a);
        }
}*/

bool comp(data q, data p)
{
    if (q.w!=p.w) return q.w < p.w;
}

int main()
{
    ios::sync_with_stdio(0);
    freopen("pour.inp","r",stdin);
    freopen("pour.out","w",stdout);
    cin >> v[1].w >> v[2].w >> v[3].w;
    v[1].id=1; v[2].id=2; v[3].id=3;
    /*memset(dd,true,sizeof(dd));   sub1
    dfs(v);
    cout << dem << '\n';
    for (long i=1; i<=dem; i++)
       cout << d[i] << " " << c[i] << '\n';*/
    while (1<2)
    {
        sort(v+1,v+4,comp);
        if (v[1].w==0) break;
        long y=v[2].w/v[1].w, z=v[3].w/v[1].w, x=1;
        while (x<=y)
        {
            if (x&y>0)
            {
                dem++;
                y-=x;
                v[2].w-=v[1].w;
                d[dem]=v[2].id;
                c[dem]=v[1].id;
            }
            else
            {
                z-=x;
                v[3].w-=v[1].w;
                dem++;
                d[dem]=v[3].id;
                c[dem]=v[1].id;
            }
            x*=2; v[1].w*=2;
            if (v[1].w==0 || v[2].w==0 || v[3].w==0) break;
        }
    }
    cout << dem;
}
