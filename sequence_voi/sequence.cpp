#include <bits/stdc++.h>
#define nmax 300007
#define vc 99999999999

using namespace std;

long long n,a[nmax];

long long tinh(long u1, long u2, long u3)
{
    return abs(a[1]-u1)+abs(a[2]-u2)+abs(a[3]-u3);
}

void sub1()
{
    if (a[1]<a[2] && a[2]<a[3])
    {
        cout << 0 << '\n';
        cout << a[1] << " " << a[2] << " " << a[3];
    }
    if (a[1]<=a[2] && a[2]<=a[3])
    {
        if (a[1]==a[2] && a[2]==a[3])
        {
            cout << 2 << '\n';
            cout << a[1]-1 << " " << a[1] << " " << a[1]+1;
        }
        else
        {
            cout << 1 <<'\n';
            if (a[1]==a[2])
            {
                cout << a[1] << " " << a[1]+1 << " " << a[3];
            }
            else
            {
                cout << a[1] << " " << a[3] << " " << a[3]+1;
            }
        }
    }
    long long gt=(a[1]+a[2]+a[3])/3;
    long long ans=vc, vtd;
    for (long i=gt-1000000; i<=gt+1000000; i++)
       if (tinh(i,i+1,i+2)<ans)
       {
           ans=tinh(i,i+1,i+2);
           vtd=i;
       }

    long long gt1=max(a[1],max(a[2],a[3])),ll=10;
    for (long sl=1; sl<=10; sl++){
            gt=gt1/ll;
            ll+=10;
    for (long i=gt-10000; i<=gt+10000; i++)
       if (tinh(i,i+1,i+2)<ans)
       {
           ans=tinh(i,i+1,i+2);
           vtd=i;
       }
    }
    gt=min(a[1],min(a[2],a[3]));
    for (long i=gt-1000000; i<=gt+1000000; i++)
       if (tinh(i,i+1,i+2)<ans)
       {
           ans=tinh(i,i+1,i+2);
           vtd=i;
       }
    cout << ans << '\n';
    cout << vtd << " " << vtd+1 << " " << vtd+2;
}

long long tinh2(long u)
{
    long long res=0;
    for (long i=1; i<=n; i++)
    {
        res+=abs(a[i]-u);
        u++;
    }
    return res;
}

void sub2()
{
     long long maxx=-vc, minn=vc, tong=0;
     for (long i=1; i<=n; i++)
     {
         tong+=a[i];
         minn=min(minn,a[i]);
         maxx=max(maxx,a[i]);
     }
     long long gt=tong/n;
     long long ans=vc, vtd;
     for (long i=gt-1000; i<=gt+1000; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     gt=minn;
     for (long i=gt-1000; i<=gt+1000; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     gt=maxx;
     for (long i=gt-1000; i<=gt+1000; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     gt=(minn+maxx)/2;
     for (long i=gt-1000; i<=gt+1000; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     cout << ans << '\n';
     for (long i=0; i<n; i++)
        cout << vtd+i << " ";
}

void sub3()
{
     long long maxx=-vc, minn=vc, tong=0;
     for (long i=1; i<=n; i++)
     {
         tong+=a[i];
         minn=min(minn,a[i]);
         maxx=max(maxx,a[i]);
     }
     long long gt=tong/n;
     long long ans=vc, vtd;
     for (long i=gt-100; i<=gt+100; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     gt=minn;
     for (long i=gt-100; i<=gt+100; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     gt=(minn+maxx)/2;
     for (long i=gt-100; i<=gt+100; i++)
       {
           long long tmp=tinh2(i);
           if (tmp<ans)
            {
              ans=tmp;
              vtd=i;
            }
       }

     cout << ans << '\n';
     for (long i=0; i<n; i++)
        cout << vtd+i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    scanf("%lld",&n);
    for (long i=1; i<=n; ++i)
       scanf("%lld",&a[i]);
    if (n==3) sub1();
    else if (n>3000) sub3();
    else sub2();
}
