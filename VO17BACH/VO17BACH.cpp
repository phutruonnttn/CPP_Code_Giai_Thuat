#include <bits/stdc++.h>

using namespace std;

struct data
{
    long tong;
    string s;
};

long long t,q,n,k;
data a[1000007];
map <string, long> M;

bool comp(data a, data b)
{
    if (a.tong!=b.tong) return a.tong < b.tong;
    return a.s < b.s;
}

string titoa(long i)
{
    string ss="";
    long aa[100000];
    long dem=0;
    while (i!=0)
    {
        aa[++dem]=i%10;
        i=i/10;
    }
    for (long j=dem; j>=1; j--)
       ss+=(char)aa[j]+48;
    return ss;
}

void sub1()
{
    M.clear();
    for (long i=1; i<=n; i++)
    {
        a[i].tong=0;
    }
    for (long i=1; i<=n; i++)
    {
        long tmp=i;
        while (tmp!=0)
        {
            a[i].tong+=tmp%10;
            tmp=tmp/10;
        }
        char s2[15];
        string s1=titoa(i);
        a[i].s=s1;
    }
    sort(a+1,a+n+1,comp);
    for (long i=1; i<=n; i++)
    {
        string tmp=a[i].s;
        while (tmp[0]=='0') tmp.erase(0,1);
        M[tmp]=i;
    }

    if (t==1)
    {
        string tmp=a[k].s;
        while (tmp[0]=='0') tmp.erase(0,1);
        cout << tmp << endl;
    }
    else
    {
        char s1[15];
        string s2=titoa(k);
        cout << M[s2] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VO17BACH.inp","r",stdin);
    freopen("VO17BACH.out","w",stdout);
    cin >> q;
    for (long qq=1; qq<=q; qq++)
    {
        cin >> t >> n >> k;
        sub1();
    }
}
