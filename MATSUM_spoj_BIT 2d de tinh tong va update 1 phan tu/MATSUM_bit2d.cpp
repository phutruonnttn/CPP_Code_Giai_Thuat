#include <bits/stdc++.h>
#define nmax 1111

using namespace std;

long long t,n,d[nmax][nmax],a[nmax][nmax];

void build()
{
    memset(d,0ll,sizeof(d));
}

void update(long x,long y,long val)
{
    while(x<=nmax)
    {
        long ty=y;
        while(ty<=nmax)
        {
            d[x][ty]+=val;
            ty+=(ty&-ty);
        }
        x+=(x&-x);
    }
}

long long read(long x,long y)// tinh tong tu (1,1) -> (x,y)
{
    long long sum=0;
    while (x)
    {
        long ty = y;
        while(ty)
        {
            sum+=d[x][ty];
            ty-=(ty&-ty);
        }
        x-=(x&-x);
    }
    return sum;
}

long long tong(long x,long y,long u,long v) // tinh tong tu (x,y) -> (u,v)
{
    return read(u,v)-read(x-1,v)-read(u,y-1)+read(x-1,y-1);
}

void sinhts()
{
    freopen("MATSUM.inp","w",stdout);
    cout << 10 << '\n';
    long long tt=10;
    while(tt--)
    {cout << 1000 << '\n';
    srand(time(NULL));
    for (long i=1; i<=100000; i++)
    {
        long vt=rand()%2;
        if (vt==0) cout << "SET" << " " << rand()%1001 << " " << rand()%1001 << " " << rand()%100000 << '\n';
        else
        {
            long long x1=rand()%1001, y1=rand()%1001,ll=1000;
            cout << "SUM" << " " << x1 << " " << y1 << " " << min(ll,x1+rand()%1001) << " " << min(ll,y1+rand()%1001) << '\n';
        }
    }
    cout << "END";}
}

int main()
{
    //sinhts();
    ios_base::sync_with_stdio(0);
    freopen("MATSUM.inp","r",stdin);
    freopen("MATSUM.out","w",stdout);
    scanf("%lld",&t);
    while (t--)
    {
         scanf("%lld",&n);
         build();
         memset(a,0,sizeof(a));
         while (true)
         {
             char s[10];
             scanf("%s",s);
             if (s[0]=='E') break;
             if (s[1]=='E')
             {
                 long long x,y,num;
                 scanf("%lld%lld%lld", &x, &y, &num);
                 x++; y++;
                 update(x,y,num-a[x][y]);//update chi cong len va cong len de no dung bang num
                 a[x][y]=num;
             }
             else
             {
                 long long x,y,u,v;
                 scanf("%lld%lld%lld%lld",&x,&y,&u,&v);
                 x++; y++; u++; v++;
                 long long ans=tong(x,y,u,v);
                 printf("%lld\n",ans);
             }
         }
         puts("");//xuong dong
    }
}
