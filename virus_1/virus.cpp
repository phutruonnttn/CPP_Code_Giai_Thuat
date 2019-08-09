#include <bits/stdc++.h>

using namespace std;
const long long b=727, m=1e9+7, m2=m*m;

long long n,nn,k[20],h[3007],hasht[3007];
string t;
bool ok;

long long get(long l, long r)
{
    return (hasht[r]-hasht[l-1]*h[r-l+1]+m2) % m;
}

void sub1()
{
    nn=t.size();
    for (long iii=1; iii<=n; iii++)
    {
    long ans=0;
    for (long i=nn/2+1; i>=1; i--)
    {
        bool okk=false;
        for (long j=0; j<=nn-1; j++)
        {
            if (j==nn-1) break;
            if (i+j-1>=nn-1) break;
            if (j+i+i-1>nn-1) break;
            string tmp1="", tmp2="";
            for (long jj=j; jj<=j+i-1; jj++)
                tmp1+=t[jj];
            for (long jj=j+i; jj<=j+i+i-1; jj++)
                tmp2+=t[jj];
            long demk=0;
            for (long jj=0; jj<=i-1; jj++)
               if (tmp1[jj]!=tmp2[jj]) demk++;
            if (demk==k[iii])
            {
                okk=true;
                break;
            }
        }
        if (okk) ans=max(ans,i);
    }
    cout << ans << endl;
    }
}

void sub2()
{
   nn=t.size();
   h[0]=1; h[1]=b;
   for (long i=2; i<=nn; i++)
     h[i]=(h[i-1]*b) % m;

   hasht[0]=(t[0])%m;
   for (long i=1; i<=nn-1; i++)
    hasht[i]=(hasht[i-1]*b+t[i]) % m;

   long ans=0;
   for (long i=0; i<=nn-1; i++)
   {
       for (long j=1; j<=nn/2+1; j++)
       {
           if (i+j-1>=nn-1) break;
           if (i+j+j-1>nn-1) break;
           long long tmp1=get(i,i+j-1), tmp2=get(i+j,i+j+j-1);
           if (tmp1==tmp2) ans=max(ans,j);
       }
   }
   for (long tt=1; tt<=n; tt++)
     cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("virus.inp","r",stdin);
    freopen("virus.out","w",stdout);
    cin >> n;
    cin >> t;
    ok=true;
    for (long i=1; i<=n; i++)
    {
        cin >> k[i];
        if (k[i]!=0) ok=false;
    }
    if (ok) sub2();
    else sub1();
}
