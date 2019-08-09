#include <bits/stdc++.h>

using namespace std;
const long long b=37, m=1000000000+7,m2=m*m;

string s;
long long h[300007],s1[300007],s2[300007];

long long get1(long l, long r)
{
    return ((s1[r]-s1[l-1]*h[r-l+1]+m2) % m);
}

long long get2(long l, long r)
{
    return ((s2[r]-s2[l-1]*h[r-l+1]+m2) % m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PAROLE.inp","r",stdin);
    freopen("PAROLE.out","w",stdout);
    cin >> s;
    long n=s.size(); bool okk=true;
    if (n==1) cout << s;
    else
    {
        for (long i=0; i<=n-2; i++ )
        if (s[i]!=s[i+1]) {okk=false; break;};
        if (okk) cout << s;
    };

    if (okk==false)
     {
            h[0]=1;
            for (long i=1; i<=n; i++)
              h[i]=(h[i-1]*b) % m;
            s1[0]=(s[0]) % m;
            for (long i=1;i<=n-1; i++)
              s1[i]=((s1[i-1]*b)+s[i]) % m;

            char ss[300005];
            for (long i=n-1; i>=0; i--)
              ss[n-i-1]=s[i];

            s2[0]=(ss[0]) % m;
            for (long i=1;i<=n-1; i++)
              s2[i]=((s2[i-1]*b)+ss[i]) % m;

           long khe=-1,vtri=0,dodai=0,dodaimax=0,vtrimax=0,khemax=0,dodaimaxk=0;

           for (long i=1; i<=n-2; i++)
             {
                if (get1(i-1,i-1)==get2(n-i-2,n-i-2))
                {
                    vtri=i;
                    long gh1=i, gh2=n-1-i;
                    if (gh1<gh2)
                    {
                        if (get1(0,i-1)==get2(n-i-2-gh1+1,n-i-2))
                            if (dodaimax<gh1)
                            {
                               dodaimax=gh1;
                               vtrimax=vtri;
                            }
                            else vtri=0;
                    }
                    else
                    if (gh1==gh2)
                    {
                        if (get1(0,i-1)==get2(0,i-1))
                        {
                            cout << s;
                            return 0;
                        }
                    }
                    else
                    {
                        if (get1(i-gh2,i-1)==get2(0,n-i-2))
                            if (dodaimax<gh2)
                            {
                               dodaimax=gh2;
                               vtrimax=vtri;
                            }
                            else vtri=0;
                    }
                }
             };

             for (long i=0; i<=n-2; i++)
             {
                if (get1(i,i)==get2(n-i-2,n-i-2))
                {
                    khe=i;
                    long gh1=i+1, gh2=n-1-i;
                    if (gh1<gh2)
                    {
                        if (get1(0,i)==get2(n-i-2-gh1+1,n-i-2))
                            if (dodaimaxk<gh1)
                            {
                               dodaimaxk=gh1;
                               khemax=khe;
                            }
                            else khe=0;
                    }
                    else
                    if (gh1==gh2)
                    {
                        if (get1(0,i)==get2(0,gh2-1))
                        {
                            cout << s;
                            return 0;
                        }
                    }
                    else
                    {
                        if (get1(i-gh2+1,i)==get2(0,gh2-1))
                            if (dodaimaxk<gh2)
                            {
                               dodaimaxk=gh2;
                               khemax=khe;
                            }
                            else khe=0;
                    }
                }
             };

            if (dodaimaxk>dodaimax)
            {
                if (khemax-dodaimaxk==-1)
                {
                    for (long i=n-1; i>=khemax + dodaimaxk+1; i--)
                        cout << s[i];
                    cout << s;
                }
                else
                {
                    cout << s;
                    for (long i=khemax-dodaimaxk; i>=0; i--)
                        cout << s[i];
                }
            }
            else
            {
                if (vtrimax-dodaimax==0)
                {
                    for (long i=n-1; i>=dodaimax + vtrimax+1; i--)
                        cout << s[i];
                    cout << s;
                }
                else
                {
                    cout << s;
                    for (long i=vtrimax-dodaimax-1; i>=0; i--)
                        cout << s[i];
                }
            }
    }
}

