#include <bits/stdc++.h>

using namespace std;

struct data
{
    long l,r,dai;
};

long n,m,p,a[100007],b[100007],c[100007],dd[100007];
data canxet[100007];
map <long,long> M[100007];
vector <long> v;

bool comp(data p, data q)
{
    if (p.dai!=q.dai) return p.dai>q.dai;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("search.inp","r",stdin);
    freopen("search.out","w",stdout);
    cin >> m >> n >> p;
    memset(dd,0,sizeof(dd));
    for (long i=1; i<=m; i++)
    {
        cin >> a[i];
        dd[a[i]]=1;
    }
    v.assign(a + 1, a + m + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
m=v.size();
    for (long i=1; i<=n; i++)
    {
        cin >> b[i];
        dd[b[i]]=2;
    }
    for (long i=1; i<=p; i++) cin >> c[i];
    long dt=0,dem=0,sai[100007];
    for (long i=1; i<=p; i++)
       if (dd[c[i]]==2) sai[++dem]=i;
    sai[++dem]=p+1;
    if (sai[1]!=1)
        {
            canxet[++dt].l=1;
            canxet[dt].r=sai[1]-1;
            canxet[dt].dai=canxet[dt].r-canxet[dt].l+1;
        }
    for (long i=1; i<=dem-1; i++)
    {
        if (sai[i]+1<=sai[i+1]-1)
        {
            canxet[++dt].l=sai[i]+1;
            canxet[dt].r=sai[i+1]-1;
            canxet[dt].dai=canxet[dt].r-canxet[dt].l+1;
        }
    }
    sort(canxet+1,canxet+dt+1,comp);

    for (long i=1; i<=dt; i++)
    {
        long dem1=0;
        for (long j=canxet[i].l; j<=canxet[i].r; j++)
           {
               if (dd[c[j]]==1)
               {
                   if (M[i][c[j]]==0)
                   {
                       dem1++;
                       M[i][c[j]]=1;
                   }
               }
               if (dem1==m) {cout << canxet[i].dai; return 0;}
           }
    }
}
