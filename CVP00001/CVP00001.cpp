#include <bits/stdc++.h>

using namespace std;

long n,a[10007],sa[10007],s;

bool ktra()
{
    long tg=s;
    tg++;
    if (tg!=n) tg=tg%n;
    if (sa[tg]!=0) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("CVP00001.inp","r",stdin);
    freopen("CVP00001.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    while (1<2)
    {
        cin >> s;
        if (s==0) break;
        for (long i=1; i<=n; i++)
           sa[i]=a[i]; long tg=s;
        while (ktra()==true)
        {
            long tgg=tg; s=tg;
            for (long i=1; i<=sa[tg]; i++)
                {s=(s+1); if (s!=n) s=s%n;sa[s]++;}
            sa[tgg]=0;
            tg=s;
            tg++; if (tg!=n) tg%=n;
        }

        for (long i=1; i<=n; i++)
            cout << sa[i] <<  " "; cout << endl;

        long long ans=0;

        while (1<2)
        {
            long tg1=s+1,tg2=s+2;
            if (tg1!=n) tg1%=n;
            if (tg2!=n) tg2%=n;
            if (sa[tg1]==0 && sa[tg2]!=0) {ans+=sa[tg2]; s=tg2;}
            else break;
        }
        cout << ans << endl;
    }
}
