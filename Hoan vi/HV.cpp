#include <bits/stdc++.h>
#define nmax 50

using namespace std;

long long n,a[nmax],use[nmax],giaithua[nmax];

long long so_hieu_trong_tu_dien()//cua day a
{
    long long res=0;
    for (long i=1; i<=n; i++) use[i]=0;

    for (long i=1; i<=n; i++)
    {
      for (long k=1; k<=a[i]-1; k++)
         if (use[k]==0)
           res+=giaithua[n-i];
      use[a[i]]=1;
    }
    return res+1;
}

void hoan_vi_tuong_ung(long long t)
{
    for (long i=1; i<=n; i++) use[i]=0;

    for (long i=1; i<=n; i++)
    {
      for (long k=1; k<=n; k++)
        if (use[k]==0)
          if (t>giaithua[n-i]) t-= giaithua[n-i];
          else {a[i]=k; break;}
       use[a[i]]=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("HV.inp","r",stdin);
    freopen("HV.out","w",stdout);
    cin >> n;
    giaithua[0]=1;
    for (long i=1; i<=27; i++)
       giaithua[i]=giaithua[i-1]*i;

    cout << giaithua[n] << '\n';

    long long tv;
    while (cin>>tv)
    {
        if (tv==1)
        {
            for (long i=1; i<=n; i++) cin >> a[i];
            cout << so_hieu_trong_tu_dien() << '\n';
        }
        else
        {
            long long l; cin >> l;
            hoan_vi_tuong_ung(l);
            for (long i=1; i<=n; i++) cout << a[i] << " ";
            cout << '\n';
        }
    }
}
