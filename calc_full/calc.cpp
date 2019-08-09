#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int nmax=1e4;
long long b,n,res,k;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("calc.inp","r",stdin);
    freopen("calc.out","w",stdout);
    cin>>b>>n;
    k=n*n;
    fore(m,1,2*n)
     {
         double a=b*m*(2*n-m);
         a=(double)(a/k);
         if(a==(long long)a) res++;
     }
     cout<<res-1;
}
