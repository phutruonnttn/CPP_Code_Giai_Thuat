#include <bits/stdc++.h>

using namespace std;

long n,p,l,w[10007],trace[10007],kq[10007];
double t[10007],f[10007];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cargroup.inp","r",stdin);
    freopen("cargroup.out","w",stdout);
    cin >> n >> p >> l;
    for (long i=1; i<=n;i++)
    {
        long v;
        cin >> w[i] >> v;
        t[i]=(double)l/v;
    }
    f[0]=0;
    for (long i=1; i<=n; i++)
    {
       double maxtime=0;
       f[i]=1000000000;
       long sum=0;
       for (long j=i; j>=1; j--)
       {
           sum+=w[j];
           if (sum>p) break;
           if (maxtime < t[j]) maxtime=t[j];
           if (f[i]>(maxtime +f[j-1]))
           {
               f[i]=maxtime + f[j-1];
               trace[i]=j-1;
           }
       }
    }
    cout << fixed << setprecision(2)<< f[n] << endl;
    long k=n,d=1;
    kq[1]=n;
    while (trace[k]!=0)
    {
        kq[++d]=trace[k];
        k=trace[k];
    }
    for (long i=d; i>=1; i--)
        cout << kq[i] << " ";
}
