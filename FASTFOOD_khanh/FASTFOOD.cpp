#include<bits/stdc++.h>

using namespace std;
const int N=1600*1600;
int n,f[N],fd[N],m=0,ans[N],x,dd[N],k[N],b[N];
vector <int> c[N],name;
void lis(int id,int l,int r)
{
    int res=0,m=0;
    for(int i=1;i<=r-l+1;++i) b[i]=0;
    for(int i=l;i<=r;++i)
    {
        f[i]=upper_bound(b+1,b+m+1,c[id][i])-b;
        m=max(f[i],m);
        b[f[i]]=c[id][i];
    }
    m=0;
    for(int i=1;i<=r-l+1;++i) b[i]=0;
    for(int i=r;i>=l;--i)
    {
        fd[i]=upper_bound(b+1,b+m+1,-c[id][i])-b;
        m=max(fd[i],m);
        b[fd[i]]=-c[id][i];
    }
    for(int i=l;i<=r;++i)
        ans[f[i]+fd[i]-1]++;
}
void solve()
{
    for(int i=0;i<name.size();++i)
    {
        int na=name[i];
        int n=c[na].size();
        lis(na,0,n-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("fastfood.inp","r",stdin);
    freopen("fastfood.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j)
     {
         cin>>x;
         c[x].push_back(j);
         if(!dd[x]){
            name.push_back(x);
            dd[x]=1;
         }
     }
    solve();
    for(int i=1;i<2*n;++i)
        cout<<ans[i]<<endl;
    return 0;
}
