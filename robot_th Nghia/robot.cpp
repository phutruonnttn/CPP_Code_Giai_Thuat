#include <bits/stdc++.h>

using namespace std;

long long n,x,y,d[6],dd[6],dem[6],kq[6];
string s;

void tinh(long x, long y)
{
    if (x<0) d[1]=-x;
    else d[3]=x;
    if (y<0) d[4]=-y;
    else d[2]=y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("robot.inp","r",stdin);
    freopen("robot.out","w",stdout);
    cin >> n;
    cin >> s;
    cin >> x >> y;
    if (x+y>n)
    {
        cout << -1;
        return 0;
    }
    tinh(x,y);
    for (long i=1; i<=4; i++) dem[i]=0;
    for (long i=0; i<n; i++)
       {
           if (s[i]=='L') dem[1]++;
           if (s[i]=='U') dem[2]++;
           if (s[i]=='R') dem[3]++;
           if (s[i]=='D') dem[4]++;
           if (dem[1]==d[1] && dd[1]==0) {kq[1]=i+1; dd[1]=1;}
           if (dem[2]==d[2] && dd[2]==0) {kq[2]=i+1; dd[2]=1;}
           if (dem[3]==d[3] && dd[3]==0) {kq[3]=i+1; dd[3]=1;}
           if (dem[4]==d[4] && dd[4]==0) {kq[4]=i+1; dd[4]=1;}
       }
    for (long i=1; i<=4; i++)
        if (d[i]==0)
        {
            dd[i]=1;
            kq[i]=0;
        }
     for (long i=1; i<=4; i++)
          if (dd[i]==0)
     {
         cout << -1;
         return 0;
     }
     for (long i=1; i<=4; i++) cout << kq[i] << " ";
}
