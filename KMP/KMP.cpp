#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

string s,w;
long m=0,i=0,t[nmax],n,nn;

void khoitao(string s, long n)
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
    while (m+i<n)
    {
        if (s[m+i]==w[i])
        {
            i++;
            if (i==nn) return m;
        }
        else
        {
            if (t[i]>-1)
            {
                m=m+i-t[i];
                i=t[i];
            }
            else
            {
                i=0; m++;
            }
        }
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("KMP.inp","r",stdin);
    freopen("KMP.out","w",stdout);
    getline(cin, s);
    getline(cin, w);
    n=s.size(),nn=w.size();
    khoitao(w,nn);
    for (long i=1; i<=nn; i++) cout << t[i] << " "; cout <<endl;
    long ans=calc();
    if (ans==n) cout << -1;
    else cout << ans;
}
