#include <bits/stdc++.h>

using namespace std;

long long n,l[20007],r[20007],sl[20007],tongdiem;
bool a[20007][20007];

int main()
{
    freopen("VISIT.inp","r",stdin);
    freopen("VISIT.out","w",stdout);
    cin >> n;
    for (long i=0; i<=n+1; i++)
      for (long j=0; j<=n+1; j++)
         a[i][j]=false;
    for (long i=1; i<=n; i++)
    {
        long u,v;
        cin >> u >> v; l[i]=u; r[i]=v; sl[i]=r[i]-l[i]+1;
        for (long j=u; j<=v; j++)
            a[i][j]=true;
    };



    /*for (long i=1; i<=n; i++)
    {
      for (long j=1; j<=n; j++)
          cout << a[i][j] << " ";
       cout << endl;
    };

    for (long i=1; i<=n; i++)
        cout << l[i] << r[i] << sl[i] << endl;*/



    tongdiem=0; long long diem=0;
    for (long i=1; i<=n; i++)
        tongdiem+=sl[i];
    //cout << tongdiem;
    long long i=1, vtri=1, buoc=0;

    diem+=sl[1]; buoc+=r[1]-1; vtri=r[1];

    while (i!=n)
    {
       i=i+1;
       if (vtri>=r[i])
       {
         buoc=buoc+1+vtri-l[i];
         diem+=sl[i];
         vtri=l[i];
         continue;
       };
       if (vtri<=l[i])
       {
         buoc=buoc+1+r[i]-vtri;
         diem+=sl[i];
         vtri=r[i];
         continue;
       };
       if (vtri<r[i] && vtri >l[i])
       {
       if (vtri-l[i]<=r[i]-vtri)
       {
           buoc=buoc+vtri-l[i]+1+r[i]-l[i];
           diem+=sl[i];
           vtri=r[i];
           continue;
       };
       if (vtri-l[i]>r[i]-vtri)
       {
           buoc=buoc+r[i]-vtri+1+r[i]-l[i];
           diem+=sl[i];
           vtri=l[i];
           continue;
       };
       };
    };
    buoc=buoc+n-vtri;
    cout << buoc;
}
