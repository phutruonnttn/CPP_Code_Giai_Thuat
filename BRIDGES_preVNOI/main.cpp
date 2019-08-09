#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

long long n,a[nmax];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BRIDGES.inp","r",stdin);
    freopen("BRIDGES.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n-1; i++) cin >> a[i];
    /*long long ans1=0;
    for (long i=1; i<=n-2; i++)
      if (a[i]%2==1) ans1+=a[i];
    else ans1+=(a[i]-1);
    if (a[n-1]%2==1) ans1+=a[n-1];
    else
    {
        ans1+=a[n-1];
        for (long i=n-2; i>=1; i--)
            if (a[i]%2==0) ans1+=1;
        else break;
    }*/

    long long ans2=0;
    for (long i=n-1; i>=2; i--)
      if (a[i]%2==1) {ans2+=(a[i]); a[i]=0;}
    else {ans2+=(a[i]-1);a[i]=1;}

    if (a[1]%2==1) {ans2+=a[1]-2; a[1]=2;}
    else
    {
        ans2+=a[1]-2;
        a[1]=2;
    }
        /*long dung;
        for (long i=1; i<=n-1; i++)
            if (a[i]!=0) {ans2+=1; a[i]--;}
        else {dung=i; break;}*/

    for (long i=1; i<=n-1; i++) cout << a[i] << " "; cout << endl;
    //cout << max(ans1,ans2);
    cout << ans2;
}
