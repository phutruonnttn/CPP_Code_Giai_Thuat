#include <bits/stdc++.h>
#define nmax 200007
#define mmax 700007

using namespace std;

struct data
{
    long long x,y,cs;
};

struct data1
{
    long u,v;
};

long long t,m1,n1,m2,n2,dem=0;
data na[nmax],nb[nmax];
data1 da[mmax],db[mmax];

bool ktra(long u1, long v1)
{
    for (long i=1; i<=m1; i++)
    {
        dem++;
        long long d=(na[u1].y-nb[v1].y)*(na[da[i].v].x-na[da[i].u].x)+(na[da[i].u].y-na[da[i].v].y)*(nb[v1].x-na[u1].x);
        long long dx=(na[u1].x*nb[v1].y-nb[v1].x*na[u1].y)*(na[da[i].v].x-na[da[i].u].x)+(na[da[i].u].x*na[da[i].v].y-na[da[i].v].x*na[da[i].u].y)*(nb[v1].x-na[u1].x);
        long long dy=(na[u1].y-nb[v1].y)*(na[da[i].u].x*na[da[i].v].y-na[da[i].v].x*na[da[i].u].y)+(na[da[i].u].y-na[da[i].v].y)*(na[u1].x*nb[v1].y-nb[v1].x*na[u1].y);
        if (d==0 && (dx==0 || dy==0)) return false;
        if (d!=0)
        {
            long long n1=dx/d,n2=dy/d;
            bool ok=true;
            if (min(na[u1].x,nb[v1].x)<n1<max(na[u1].x,nb[v1].x) && min(na[u1].y,nb[v1].y)<n2<max(na[u1].y,nb[v1].y)) ok=false;
            if (min(na[da[i].v].x,na[da[i].u].x)<n1<max(na[da[i].v].x,na[da[i].u].x) && min(na[da[i].v].y,na[da[i].u].y)<n2<max(na[da[i].v].y,na[da[i].u].y)) ok=false;
            /*if (n1==na[da[i].v].x && n2!=na[da[i].v].y) ok=true;
            if (n1==na[da[i].u].x && n2!=na[da[i].u].y) ok=true;*/
            if (!ok) return false;
        }
    }

    for (long i=1; i<=m2; i++)
    {
        //dem++;
        long long d=(na[u1].y-nb[v1].y)*(nb[db[i].v].x-nb[db[i].u].x)+(nb[db[i].u].y-nb[db[i].v].y)*(nb[v1].x-na[u1].x);
        long long dx=(na[u1].x*nb[v1].y-nb[v1].x*na[u1].y)*(nb[db[i].v].x-nb[db[i].u].x)+(nb[db[i].u].x*nb[db[i].v].y-nb[db[i].v].x*nb[db[i].u].y)*(nb[v1].x-na[u1].x);
        long long dy=(na[u1].y-nb[v1].y)*(nb[db[i].u].x*nb[db[i].v].y-nb[db[i].v].x*nb[db[i].u].y)+(nb[db[i].u].y-nb[db[i].v].y)*(na[u1].x*nb[v1].y-nb[v1].x*na[u1].y);
        if (d==0 && (dx==0 || dy==0)) return false;
        if (d!=0)
        {
            long long n1=dx/d,n2=dy/d;
            bool ok=true;
            if (min(na[u1].x,nb[v1].x)<n1<max(na[u1].x,nb[v1].x) && min(na[u1].y,nb[v1].y)<n2<max(na[u1].y,nb[v1].y)) ok=false;
            if (min(nb[db[i].v].x,nb[db[i].u].x)<n1<max(nb[db[i].v].x,nb[db[i].u].x) && min(nb[db[i].v].y,nb[db[i].u].y)<n2<max(nb[db[i].v].y,nb[db[i].u].y)) ok=false;
            //if (n1==nb[db[i].v].x && n2!=nb[db[i].v].y) ok=true;
            //if (n1==nb[db[i].u].x && n2!=nb[db[i].u].y) ok=true;
            if (!ok) return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("HIGHWAY.inp","r",stdin);
    freopen("HIGHWAY.out","w",stdout);
    cin >> t;
    for (long tt=1; tt<=t; tt++)
    {
        cin >> n1 >> m1;
        for (long i=1; i<=n1; i++)
        {
            long xx,yy;
            cin >> na[i].x >> na[i].y;
            na[i].cs=i;
        }
        for (long i=1; i<=m1; i++)
        {
            long uu,vv;
            cin >> da[i].u >> da[i].v;
        }
        cin >> n2 >> m2;
        for (long i=1; i<=n2; i++)
        {
            long xx,yy;
            cin >> nb[i].x >> nb[i].y;
            nb[i].cs=i;
        }
        for (long i=1; i<=m2; i++)
        {
            long uu,vv;
            cin >> db[i].u >> db[i].v;
        }
        bool ok=false;
        for (long i=1; i<=n1; i++)
          if (!ok)
           for (long j=1; j<=n2; j++)
             if (ktra(i,j))
              {
                  ok=true;
                  cout << i << " " << j << endl;
                  break;
              }
        if (!ok) cout << 0 << endl;
        /*if (ktra(5,2)) cout << "dung" << endl;
        else cout << "sai" << endl;
        cout << dem << endl;*/
        //cout << n1 << " " << n2-2 << endl;

    }
}
