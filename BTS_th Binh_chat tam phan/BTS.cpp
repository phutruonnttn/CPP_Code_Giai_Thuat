#include <bits/stdc++.h>
#define nmax 500007
#define vc 9999999999

using namespace std;
const double eps=1e-5;

struct point
{
    long long x,y;
};

long long n,a,b,c;
point diem[nmax],l,r;
double ll,rr;

void doc(long long &n)
{
    n=0;
    char ch;
    long ktAm=0;
    for (ch=getchar(); ch<'0' || ch>'9'; ch=getchar())
      if (ch=='-') ktAm=1-ktAm;
    n=ch-48;
    for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;
    if (ktAm) n=-n;
}

void ptdt(point p1, point p2, long long &a, long long &b, long long &c)
{
    a=p2.y-p1.y;
    b=p1.x-p2.x;
    c=-(a*p1.x+b*p1.y);
}

double kcach(double xa, double ya, double xb, double yb)
{
    return (double)sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
}

inline double tinh(const double xa)
{
    double res=-1,ya=(double)(-c-a*xa)/b;
    for (long i=1; i<=n; ++i)
       res=max(res,kcach(xa,ya,diem[i].x,diem[i].y));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("BTS.inp","r",stdin);
    freopen("BTS.out","w",stdout);
    doc(n);
    ll=-1e9-7; rr=1e9+7;
    for (long i=1; i<=n; ++i) {doc(diem[i].x); doc(diem[i].y);}
    doc(l.x); doc(l.y); doc(r.x); doc(r.y);

    if(l.x==r.x)
     {
        for (long i=1; i<=n; ++i) swap(diem[i].x,diem[i].y)  ;
        swap(l.x,l.y) ;
        swap(r.x,r.y) ;
     }

    ptdt(l,r,a,b,c);

    /*double ml=(long)(ll+ll+rr)/3, mr=(long)(ll+rr+rr)/3;
    while ((ll!=ml) && (ml!=mr) && (mr!=rr))
    {
         if (tinh(ml)-tinh(mr)>el) ll=ml;
         else rr=mr;
         ml=(long)(ll+ll+rr)/3, mr=(long)(ll+rr+rr)/3;
    }*/

    while (rr-ll>eps)
     {
        double c=ll+4*(rr-ll)/9;
        double d=ll+5*(rr-ll)/9;
        if (tinh(c)<=tinh(d)) rr=d;
        else ll=c;
     }

    /*double cc=vc,cur;
    for (double i=ll; i<=rr; i++)
       for (long j1=0; j1<=9; j1++)
         for (long j2=0; j2<=9; j2++)
           for (long j3=0; j3<=9; j3++)
             for (long j4=0; j4<=9; j4++)
               if (tinh(i+(double)j1/10+(double)j2/100+(double)j3/1000+(double)j4/10000)<cc)
                 {
                   cc=tinh(i+(double)j1/10+(double)j2/100+(double)j3/1000+(double)j4/10000);
                   cur=i+(double)j1/10+(double)j2/100+(double)j3/1000+(double)j4/10000;
                 }*/
    //cout << fixed << setprecision(4) /*<<cur << " " */<< tinh((ll+rr)/2);
    printf("%0.4f",tinh((ll+rr)/2));
}
