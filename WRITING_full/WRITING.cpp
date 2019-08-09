#include <bits/stdc++.h>
#define nmax 3005
#define mmax 3000005

using namespace std;

long x[131],y[131],n,m,res;
string s,ss;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("WRITING.inp","r",stdin);
    freopen("WRITING.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    cin >> ss;
    for(long i=0; i<s.length(); i++) x[s[i]]++;

    for(long i=0; i<s.length(); i++) y[ss[i]]++;

   /*for(long i=0; i<=130; i++) cout<<x[i]<<" ";
    cout<<endl;
    for(long i=0; i<=130; i++) cout<<y[i]<<" ";
    cout<<endl;*/

    long k=0;
    for(long i=0; i<=130; i++)
        if(x[i]!=y[i]) k++;
    res+=(k==0);
    //cout<<k<<endl;
    for(long i=0; i<=m-n-1; i++)
    {
        k-=(x[ss[i]]!=y[ss[i]]);
        k-=(x[ss[i+n]]!=y[ss[i+n]]);
        y[ss[i]]--; y[ss[i+n]]++;
       // for(long i=0; i<=130; i++) cout<<y[i]<<" ";
        //cout<<endl;
        k+=(x[ss[i]]!=y[ss[i]]);
        k+=(x[ss[i+n]]!=y[ss[i+n]]);
        res+=(k==0);
    }
    cout<<res;
}
