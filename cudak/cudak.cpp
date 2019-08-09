#include <bits/stdc++.h>

using namespace std;

long long a,b,s,dem=0,n=0,tong=0,so=0,x[20],stm;

void tryy(long long i)
{
   if (tong>s || so>b) return;
   for (long j=0; j<=9; j++)
     {
         x[i]=j;
         tong+=x[i];
         so=so*10+x[i];
         if (i==n)
         {
            //cout << so << endl;
            if (a<=so && so<=b && tong==s)
                {dem++; stm=min(stm,so);};
         }
         else tryy(i+1);
         tong-=x[i];
         so=so/10;
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cudak.inp","r",stdin);
    freopen("cudak.out","w",stdout);
    cin >> a >> b >> s;
    long long bb=b; stm=b;
    while (bb!=0)
    {
        n++;
        bb=bb/10;
    }
    tryy(1);
    cout << dem << endl << stm;
}
