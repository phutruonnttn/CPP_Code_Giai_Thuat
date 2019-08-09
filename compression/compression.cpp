#include <bits/stdc++.h>
#define nmax 1000007

using namespace std;

string s,w;
long t[nmax],n,nn,ii,m;

void khoitao()
{
    t[0]=-1; t[1]=0;
    long pos=2, cnd=0;
    while (pos<n)
    {
        if (s[pos-1]==s[cnd])
        {
            t[pos]=cnd+1;
            pos++; cnd++;
        }
        else
        if (cnd>0) cnd=t[cnd];
        else
        {
            t[pos]=0;
            pos++;
        }
    }
}

long calc()
{
    while (m+ii<n)
    {
        if (s[m+ii]==w[ii])
        {
            ii++;
            if (ii==nn) return m;
        }
        else
        {
            if (t[ii]>-1)
            {
                m=m+ii-t[ii];
                ii=t[ii];
            }
            else
            {
                ii=0; m++;
            }
        }
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("compression.inp","r",stdin);
    freopen("compression.out","w",stdout);
    cin >> s;
    n=s.size();
    bool giong=true;
    for (long i=0; i<n-1; i++)
      if (s[i]!=s[i+1]) giong=false;

    if (giong)
    {
        cout << s[0];
        return 0;
    }
    khoitao();

    for (long i=2; i<=n; i++)
    {
        if (n%i!=0) continue;
        string tmp="";
        for (long j=0; j<i; j++) tmp=tmp+s[j];
        w=tmp;
        for (long j=1; j<n/i; j++) w=w+tmp;
        nn=w.size();
        ii=0; m=0;
        if (calc()==0)
        {
            cout << tmp;
            return 0;
        }
    }
    cout << s;
}
