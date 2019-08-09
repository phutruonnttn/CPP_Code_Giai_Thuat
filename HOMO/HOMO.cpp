#include <bits/stdc++.h>
#define nmax 100005

using namespace std;

long long n=0,t,dem=0;
map <long long, long> M;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("HOMO.inp","r",stdin);
    freopen("HOMO.out","w",stdout);
    cin >> t;
    for (long i=1; i<=t; i++)
    {
        string s; long long k;
        cin >> s;
        cin >> k;
        if (s=="insert")
        {
            n++;
            M[k]++;
            if (M[k]>=2) dem++;
            //cout << n << " " <<dem << endl;
            if (n<2) cout << "neither" << '\n';
            else
            if (dem==0) cout << "hetero" << '\n';
            else
            if (dem>0 && dem==n-1) cout << "homo" << '\n';
            else cout << "both" << '\n';
        }
        else
        {
            if (M[k]!=0)
            {
                n--;
                if (M[k]>1) dem--;
                M[k]--;
            }
                //cout << n << " " <<dem << endl;
                if (n<2) cout << "neither" << '\n';
                else
                if (dem==0) cout << "hetero" << '\n';
                else
                if (dem>0 && dem==n-1) cout << "homo" << '\n';
                else cout << "both" << '\n';


        }
    }
}
