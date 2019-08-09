#include <bits/stdc++.h>
#define nmax 40007

using namespace std;

long n;
long long a[nmax],an=0,binh=0,ans1,ans2;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("nsgame.inp","r",stdin);
    freopen("nsgame.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];

    long l=1,r=n,luot=0,td=2,tt=1;
    while (r-l+1>=1)
    {
        if (tt>r-l+1) break;
        if (luot==0)
        {
            long slc,tong=0,d=0;
            long long chon=-10000000000;
            for (long i=l; i<=l+min(td,r-l+1)-1; i++)
            {
                d++;
                tong+=a[i];
                if (tong>chon && d>=tt)
                {
                    chon=tong;
                    slc=d;
                }
            }
            an+=chon;
            //cout << an << endl;
            l=l+slc;
            tt=slc; td=slc+1;
            //cout << l << " " << r << endl;
        }
        else
        {
            long long slc,tong=0,d=0,chon=-10000000000;
            for (long i=r; i>=l; i--)
            {
                d++;
                if (d>td) break;
                tong+=a[i];
                if (tong>chon && d>=tt)
                {
                    chon=tong;
                    slc=d;
                }
            }
            binh+=chon;
            //cout << binh << endl;
            r=r-slc;
            tt=slc; td=slc+1;
            //cout << l << " " << r << endl;
        }
        luot=1-luot;
    }
    ans1=an-binh;

    an=0; binh=0; l=1;r=n;luot=0;td=2;tt=2;
    while (r-l+1>=1)
    {
        if (tt>r-l+1) break;
        if (luot==0)
        {
            long slc,tong=0,d=0;
            long long chon=-10000000000;
            for (long i=l; i<=l+min(td,r-l+1)-1; i++)
            {
                d++;
                tong+=a[i];
                if (tong>chon && d>=tt)
                {
                    chon=tong;
                    slc=d;
                }
            }
            an+=chon;
            //cout << an << endl;
            l=l+slc;
            tt=slc; td=slc+1;
            //cout << l << " " << r << endl;
        }
        else
        {
            long long slc,tong=0,d=0,chon=-10000000000;
            for (long i=r; i>=l; i--)
            {
                d++;
                if (d>td) break;
                tong+=a[i];
                if (tong>chon && d>=tt)
                {
                    chon=tong;
                    slc=d;
                }
            }
            binh+=chon;
            //cout << binh << endl;
            r=r-slc;
            tt=slc; td=slc+1;
            //cout << l << " " << r << endl;
        }
        luot=1-luot;
    }
    ans2=an-binh;
    long long ans=max(ans1,ans2);
    cout << ans;
}
