#include <bits/stdc++.h>
#define nmax 207

using namespace std;

long long n,m,f[nmax][nmax];
vector <long> tr[nmax][nmax];
string x,y;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NUMBER.in","r",stdin);
    freopen("NUMBER.out","w",stdout);
    cin >> x >> y;
    n=x.size();
    m=y.size();
    x='*'+x;
    y='*'+y;
    long dem=0;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=m; j++)
        if (x[i]==y[j])
        {
            f[i][j]=f[i-1][j-1]+1;
            for (long k=0; k<tr[i-1][j-1].size(); k++)
                tr[i][j].push_back(tr[i-1][j-1][k]);
            tr[i][j].push_back((long)x[i]-48);
        }
        else
        {
            if (f[i-1][j]>f[i][j-1])
            {
                f[i][j]=f[i-1][j];
                for (long k=0; k<tr[i-1][j].size(); k++)
                   tr[i][j].push_back(tr[i-1][j][k]);
            }
            else if (f[i-1][j]<f[i][j-1])
            {
                f[i][j]=f[i][j-1];
                for (long k=0; k<tr[i][j-1].size(); k++)
                   tr[i][j].push_back(tr[i][j-1][k]);
            }
            else
            {
                f[i][j]=f[i][j-1];
                string s1="",s2="";
                for (long k=0; k<tr[i-1][j].size(); k++)
                   s1=s1+char(tr[i-1][j][k]+48);
                for (long k=0; k<tr[i][j-1].size(); k++)
                   s2=s2+char(tr[i][j-1][k]+48);
                if (s1>s2)
                {
                   for (long k=0; k<tr[i-1][j].size(); k++)
                      tr[i][j].push_back(tr[i-1][j][k]);
                }
                else
                {
                    for (long k=0; k<tr[i][j-1].size(); k++)
                      tr[i][j].push_back(tr[i][j-1][k]);
                }
            }
        }
    //cout << f[n][m] << endl;
    long nho=tr[n][m].size()-1;
    for (long i=0; i<tr[n][m].size(); i++)
        if (tr[n][m][i]!=0)
         {
            nho=i;
            break;
         }
    if (nho==tr[n][m].size()-1) cout << 0;
    else
    {
        for (long i=nho; i<tr[n][m].size(); i++) cout << tr[n][m][i];
    }
}
