#include <bits/stdc++.h>

using namespace std;

long n,k,a[12][12],x[100000],y[100000];
bool dd[12][12],OK=true;
fstream fi,fo;

void ktra()
{
           /*if (!OK) return;
           bool ok1=true;
           fi.close();
           fi.open("SODUKU.inp",ios::in);
           long bo1,bo2; fi >> bo1 >> bo2;
           for (long i=1; i<=k; i++)
           {
               if (!ok1) break;
               char s; fi >> s;
               if (s=='X')
               {
                   long value, num,tich=1;
                   fi >> value >> num;
                   for (long j=1; j<=num; j++) fi >> x[j] >> y[j];
                   for (long j=1; j<=num; j++)
                      tich*=a[x[j]][y[j]];
                   if (tich!=value) {ok1=false; break;}
               }

               if (!ok1) break;

               if (s=='+')
               {
                   long value, num,tong=0;
                   fi >> value >> num;
                   for (long j=1; j<=num; j++) fi >> x[j] >> y[j];
                   for (long j=1; j<=num; j++)
                      tong+=a[x[j]][y[j]];
                   if (tong!=value) {ok1=false; break;}
               }
              if (!OK) return;
               if (ok1)
             {*/
              for (long i=1; i<=n; i++)
                {
                  for (long j=1; j<=n; j++)
                    fo << a[i][j] << " ";
                  fo << endl;
                }
                fo << endl;
                //OK=false;
         /*    }
           }*/
}

void try_( long i1,long i2)
{
    if (!OK) return;
    for (long j=1; j<=n; j++)
      if (dd[i1][j] && OK)
      {
          bool ok=true;
         for (long k=1; k<=i1-1; k++)
         {
             if (a[k][i2]==j) {ok=false; break;}
         }
         if (!ok) continue;

         a[i1][i2]=j;
         dd[i1][j]=false;
         if (i2==n) try_(i1+1,1);
         else try_(i1,i2+1);
         if (!OK) return;
         if (i1==n) ktra();
         dd[i1][j]=true;
      }
}

int main()
{
    ios_base::sync_with_stdio(0);
    fi.open("SODUKU.inp",ios::in);
    fo.open("SODUKU.out",ios::out);
    fi >> n >> k;
    memset(dd,true,sizeof(dd));
    try_(1,1);
}
