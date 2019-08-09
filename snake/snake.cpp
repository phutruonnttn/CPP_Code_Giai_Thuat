#include <bits/stdc++.h>

using namespace std;

long r,s,dau[1007],cuoi[1007],dong,cot,ans=0;
char a[1007][1007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("snake.inp","r",stdin);
    freopen("snake.out","w",stdout);
    cin >> r >> s;
    for (long i=1; i<=r; i++)
      for (long j=1; j<=s; j++)
        cin >> a[i][j];

    for (long i=1; i<=r; i++)
    {
        dau[i]=-1; cuoi[i]=-1;
        for (long j=1; j<=s; j++)
          if (a[i][j]=='J') {dau[i]=j;cuoi[i]=j;break;}
        for (long j=s; j>=1; j--)
          if (a[i][j]=='J') {cuoi[i]=j; break;}
    }

   /* for (long i=1; i<=r; i++)
        cout << dau[i] << " " <<cuoi[i] << endl;*/

    long rbd=0,rbc0=0,rbc1=0;
    for (long i=1; i<=r; i++)
      if (dau[i]!=-1) {rbd=i;rbc0=dau[i]; rbc1=cuoi[i]; break;}
    dong=r; cot=1; int huong=1;
    if (rbd==0) cout << 0;
    else
    {
        while (dong!=rbd )
        {
           if (huong==1)
           {
              if (cuoi[dong]!=-1) {ans+=cuoi[dong]-cot; cot=cuoi[dong];}
              if (cuoi[dong-1]>cot) {ans+=cuoi[dong-1]-cot; cot=cuoi[dong-1];}
           }
           else
           {
               if (dau[dong]!=-1) {ans+=cot-dau[dong]; cot=dau[dong];}
               if (dau[dong-1]<cot && dau[dong-1]!=-1) {ans+=cot-dau[dong-1];cot=dau[dong-1];}
           }
           dong--; huong=1-huong;

           if (dong==rbd)
           {
               if (huong==0 && cot!=rbc0) ans+=abs(cot-rbc0);
               if (huong==1 && cot!=rbc1) ans+=abs(cot-rbc1);
           }

           //cout << dong <<  " " << cot << " " << huong<< " " << ans << endl;
        }
        cout << ans+r-rbd;
    }
}
