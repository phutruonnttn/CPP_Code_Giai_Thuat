#include <bits/stdc++.h>

using namespace std;
typedef pair <long long,long long> ii;
long long b,n;
map <ii,long> M;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CALC.inp","r",stdin);
    freopen("CALC.out","w",stdout);
    cin >> b >> n;
    long long ans=0;
    for (long a=0; a<b*2; a++)
    {
        double cdel=(double)sqrt(4*b*b*n*n-4*b*n*n*a);
        double n1=(double)(2*b*n-cdel)/(2*b);
        double n2=(double)(2*b*n+cdel)/(2*b);
        if (n1==trunc(n1))
        {
            if (n1>0)
                //if (M[ii(n1,a)]==0)
                {
                    //M[ii(n1,a)]=1;
                    //M[ii(a,n1)]=1;
                    //cout << n1 << " " << a << endl;
                    ans++;
                }
        }
        if (n2==trunc(n2))
        {
             if (n2>0)
                //if (M[ii(n2,a)]==0)
                {
                   // M[ii(n2,a)]=1;
                    //M[ii(a,n2)]=1;
                    //cout << n2 << " " << a << endl;
                    ans++;
                }
        }
    }
    cout << ans;
}
