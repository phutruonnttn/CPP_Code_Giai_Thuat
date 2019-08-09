#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
const int nmax=1e5+9;
int n,a[nmax],res=0;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("running.inp","r",stdin);
    freopen("running.out","w",stdout);
    cin>>n;
    fore(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    fore(x,1,n-2)
    {
        int t1=3,t2=3;
         fore(y,x+1,n-1)
         {
             while( (a[t1]-a[y])<(a[y]-a[x]) &&(t1+1<=n)) t1++;
             while( (a[t2+1]-a[y])<=2*(a[y]-a[x])&&(t2+1<=n) ) t2++;
             if((t2>=t1)&&(a[t1]-a[y])>=(a[y]-a[x])&&(a[t2]-a[y])<=2*(a[y]-a[x])) res+=(t2-t1+1);
             //cout<<t1<<" "<<t2<<'\n';
         }
       // res+=(t2-t1+1);
       // cout<<t1<<" "<<t2<<'\n';
    }
    cout<<res;
}
