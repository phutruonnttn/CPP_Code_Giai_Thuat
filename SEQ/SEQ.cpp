#include <bits/stdc++.h>

using namespace std;

long long n,k,a[1000007];
map <long long, long> M;



int main()
{
    ios_base::sync_with_stdio(0);
    freopen("SEQ.inp","r",stdin);
    freopen("SEQ.out","w",stdout);
    cin >> n >> k;
    for (long i=1; i<=n ; i++)
      {
        cin >> a[i];
        M[a[i]] =i;
      };
    bool ok=false;
    for (long i=1; i<=n; i++)
        {
            if (M[a[i]-k]!=0)
            {
                if (i!=M[a[i]-k])
                {
                    ok=true;
                    cout << i<< " " << M[a[i]-k];
                    break;
                };
            };

           if (M[a[i]+k]!=0)
            {
                if (i!=M[a[i]+k])
                {
                    ok=true;
                    cout << M[a[i]+k]<< " " << i;
                    break;
                };
            };

        };
       if (not ok) cout << 0;

}
