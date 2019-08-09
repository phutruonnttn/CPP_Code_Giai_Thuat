#include <bits/stdc++.h>
#define nmax 1e9+7

using namespace std;
typedef pair <string,long> ii;

long n,a[10],stt[8][8][8][8][8][8][8],dem,l[6000][3][400];
double dd[10][10][10][10][5][107],t[10];
map <ii,double> M;

void sub1()
{
    if (a[1]==3 && a[2]==2 && a[3]==1) cout << "5.00000";
    if (a[1]==1 && a[2]==2 && a[3]==3) cout << "0.00000";
    if (a[1]==2 && a[2]==3 && a[3]==1) cout << "4.00000";
    if (a[1]==2 && a[2]==1 && a[3]==3) cout << "1.00000";
    if (a[1]==1 && a[2]==3 && a[3]==2) cout << "1.00000";
    if (a[1]==3 && a[2]==1 && a[3]==2) cout << "4.00000";
}

double tinh(long h[], long p, long ds)
{
    if (dd[h[1]][h[2]][h[3]][h[4]][p][ds]!=0) return dd[h[1]][h[2]][h[3]][h[4]][p][ds];
    bool ok=true;
    for (long i=1; i<=n-1; i++)
      if (h[i]>h[i+1]) {ok=false; break;}

    if (ok || ds==100)
    {
        dd[h[1]][h[2]][h[3]][h[4]][p][ds]=0;
        return 0;
    }
    double ts=0,tmin=nmax;
    for (long i=1; i<=n-1; i++)
    {
        swap(h[i],h[i+1]);
        t[i]=tinh(h,1-p,ds+1)+1;
        ts+=t[i]; tmin=min(tmin,t[i]);
        swap(h[i],h[i+1]);
    }
    if (p==0)
    {
        dd[h[1]][h[2]][h[3]][h[4]][p][ds]=tmin;
        return tmin;
    }
    else
    {
        dd[h[1]][h[2]][h[3]][h[4]][p][ds]=(double)ts/(n-1);
        return (double)ts/(n-1);
    }
}

void sub2()
{
    printf("%.5f",tinh(a,0,1));
}

/*double tinh3(long h[], long p, long ds)
{
    string s="";
    for (long i=1; i<=n; i++) s=s+(char)(h[i]+48);
    s=s+(char)(p+48);
    if (M[ii(s,ds)]!=0) return M[ii(s,ds)];
    bool ok=true;
    for (long i=1; i<=n-1; i++)
      if (h[i]>h[i+1]) {ok=false; break;}

    if (ok || ds==200) return 0;

    double ts=0,tmin=nmax;
    for (long i=1; i<=n-1; i++)
    {
        swap(h[i],h[i+1]);
        t[i]=tinh3(h,1-p,ds+1)+1;
        ts+=t[i]; tmin=min(tmin,t[i]);
        swap(h[i],h[i+1]);
    }
    if (p==0)
    {
        M[ii(s,ds)]=tmin;
        return tmin;
    }
    else
    {
        M[ii(s,ds)]=(double)ts/(n-1);
        return (double)ts/(n-1);
    }
}*/

double tinh3(long h[], long p, long ds)
{
    bool ok=true;
    for (long i=1; i<=n-1; i++)
      if (h[i]>h[i+1]) {ok=false; break;}

    if (ok || ds==400)
        return 0;
    if (stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]==0)  stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]=++dem;
    if (l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds]!=-1) return l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds];
    double ts=0,tmin=nmax;
    for (long i=1; i<=n-1; i++)
    {
        swap(h[i],h[i+1]);
        t[i]=tinh3(h,1-p,ds+1)+1;
        ts+=t[i]; tmin=min(tmin,t[i]);
        swap(h[i],h[i+1]);
    }
    if (p==0)
    {
        l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds]=tmin;
        return tmin;
    }
    else
    {
        l[stt[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]][p][ds]=(double)ts/(n-1);
        return (double)ts/(n-1);
    }
}

void sub3()
{
    dem=1;
    stt[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]]=1;
    memset(l,-1,sizeof(l));
    printf("%.5f",tinh3(a,0,1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("P12n.inp","r",stdin);
    freopen("P12n.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++) cin >> a[i];
    /*if (n==3) sub1();
    else
    if (n==4) sub2();
    else*/ sub3();
}
