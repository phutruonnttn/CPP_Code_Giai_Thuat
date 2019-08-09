#include <bits/stdc++.h>

using namespace std;

long k;
string s,t[25],ss;
bool ok1,thu;

bool comp(string a, string b)
{
    return a.length()<b.length();
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("VIRUS.inp","r",stdin);
    freopen("VIRUS.out","w",stdout);
    cin >> s; ss=s;
    cin >> k;
    for (long i=1; i<=k; i++)
        cin >> t[i];

    sort(t+1,t+k+1,comp);

    while (1<2)
    {
        ok1=false;
        thu=false;
        for (long i=1; i<=k; i++)
        {
            if (s.size()<t[i].size()) continue;
            for (long j=0; j<=s.size()-t[i].size(); j++)
                if (s[j]==t[i][0])
                   {
                       string tmp="";
                       for (long ii=j; ii<=j+t[i].size()-1; ii++)
                            tmp=tmp+s[ii];

                       bool okk=true;

                       for (long ii=0; ii<=tmp.size()-1; ii++)
                           if (tmp[ii]!=t[i][ii])
                            {
                               okk=false;
                            }

                       if (okk)
                         {
                            s.erase(j,t[i].size());
                            thu=true;
                            ok1=true;
                            break;
                         }
                   }
             if (ok1==true) break;
        }
        if (thu==false) break;
    }
    long ans=s.size();

    s=ss;
    while (1<2)
    {
        ok1=false;
        thu=false;
        for (long i=k; i>=1; i--)
        {
            if (s.size()<t[i].size()) continue;
            for (long j=0; j<=s.size()-t[i].size(); j++)
                if (s[j]==t[i][0])
                   {
                       string tmp="";
                       for (long ii=j; ii<=j+t[i].size()-1; ii++)
                            tmp=tmp+s[ii];

                       bool okk=true;

                       for (long ii=0; ii<=tmp.size()-1; ii++)
                           if (tmp[ii]!=t[i][ii])
                            {
                               okk=false;
                            }

                       if (okk)
                         {
                            s.erase(j,t[i].size());
                            thu=true;
                            ok1=true;
                            break;
                         }
                   }
             if (ok1==true) break;
        }
        if (thu==false) break;
    }
    long ans1=s.size();
    ans=min(ans,ans1);
    cout << ans;
}
