#include <bits/stdc++.h>

using namespace std;

long long n,k;
long long a[12][12],x[12000000],y[1200000];
bool dd[12][12],cc[12][12],dc[12],OK=true;

int main()
{
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    fstream fi,fo;
    fi.open("SODUKU.inp",ios::in);
    fo.open("SODUKU.out",ios::out);
    fi >> n >> k;

    for (long ii=1; ii<=100000; ii++)
     if (OK)
     {
        memset(dd,false,sizeof(dd));
        for (long i=1; i<=n; i++)
        {
            for (long j=1; j<=n; j++)
            {
                while (1<2)
                {
                   long k=rand() % n +1;
                   if (!dd[i][k] )
                     {
                        a[i][j]=k;
                        dd[i][k]=true;
                        break;
                     }
                }
            }
        }

        bool ok=true;

        for (long i=1; i<=n; i++)
        {
            bool okk=true;
            memset(dc,false,sizeof(dc));
            for (long j=1; j<=n; j++)
                dc[a[j][i]]=true;
            for (long j=1; j<=n; j++)
              if (dc[j]==false) {ok=false; okk=false; break; }
            if (!okk) break;
        }

        if (ok==true)
        {
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
           }

           if (ok1)
             {
              for (long i=1; i<=n; i++)
                {
                  for (long j=1; j<=n; j++)
                    fo << a[i][j] << " ";
                  fo << endl;
                }
                fo << endl;
                OK=false;
             }

         }
     }
}
