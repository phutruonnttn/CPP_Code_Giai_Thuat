#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
using namespace std;
const int nmax=1e6;
int xa,ya,xb,yb,q,n,x[nmax],y[nmax],u,v,da[nmax],db[nmax],ans[nmax],t[nmax],rmax=0;
struct data{
    int u,v,w,k;
};
data a[nmax];
bool cmp(data p,data q)
{
    if (p.u!=q.u) return p.u<q.u;
    if (p.v!=q.v) return p.v<q.v;
    return p.w<q.w;
}
int calc(int x,int y,int a,int b)
{
    int ans=(x-a)*(x-a)+(y-b)*(y-b);
    return ceil(sqrt(ans));
}
void up(int x)
{
    for(int i=x;i<=rmax+1;i+=i&(-i)) t[i]++;
}
int get(int x)
{
    int ans=0;
    for(int i=x;i;i-=i&(-i)) ans+=t[i];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nuclear.inp","r",stdin);
    freopen("nuclear.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    cin>>xa>>ya>>xb>>yb>>q;
    for(int i=1;i<=n;i++)
    {
        int r1=calc(xa,ya,x[i],y[i]);
        int r2=calc(xb,yb,x[i],y[i]);
        a[i]={r1,r2,0,i};
        da[r1]++; db[r2]++;
        rmax=max(rmax,r1);
        rmax=max(rmax,r2);
    }
    for(int i=1;i<=rmax;i++){
        da[i]+=da[i-1];
        db[i]+=db[i-1];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        rmax=max(rmax,x[i]);
        rmax=max(rmax,y[i]);
        a[n+i]={x[i],y[i],1,i};
    }
    sort(a+1,a+n+q+1,cmp);
    for(int i=1;i<=n+q;i++)
    {
        if(a[i].w) {
            int res=0;
            res+=da[a[i].u]+db[a[i].v];
            res-=get(a[i].v);
            ans[a[i].k]=res;
        }
        else up(a[i].v);
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}
