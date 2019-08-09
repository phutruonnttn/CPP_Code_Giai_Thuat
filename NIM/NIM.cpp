#include <bits/stdc++.h>

using namespace std;

long n,t,b[100000009];
map <long long, long> M;
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL); cin.tie(NULL);
    freopen("NIM.inp","r",stdin);
    freopen("NIM.out","w",stdout);
    cin >> t;
    long cur=0,dem=2;
    while(cur<=100000007)
     {
        if ((cur+dem)>=(dem*dem)) dem++;
        cur+=dem;
        b[cur]=1;
     }
    long long a;
    for (long i=1; i<=t; i++)
     {
         cin >> a;
         if (a==1000000000000) {cout <<"BILL" << endl; continue;}
         if (a<100000007) {if (b[a]==0 ) cout << "BILL" << '\n'; else cout << "STEVE" << '\n';}
         else
         {
             while (a>100000007)
             {
                 if ((double)sqrt(a)==trunc(sqrt(a))) a=a-trunc(sqrt(a))-2;
                 else a=trunc(a-sqrt(a));
             }
             if (b[a]==0) cout << "BILL" << '\n'; else cout << "STEVE" << '\n';
         }
     }
}
