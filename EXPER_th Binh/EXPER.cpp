#include <bits/stdc++.h>
#define nmax 100007
#define xmax 2000007
#define hs 1000000

using namespace std;

struct data
{
    long long x,y;
};

long long n,m,tren,duoi,trai,phai,ox[xmax],oy[xmax];
data p,dau;

long long kc(data p, data q)
{
    return abs(p.x-q.x)+abs(p.y-q.y);
}

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

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("EXPER.inp","r",stdin);
    freopen("EXPER.out","w",stdout);
    //doc(n); doc(m);
    scanf("%lld%lld",&n,&m);
    long long cx=0,cy=0,ans=0;
    dau.x=0; dau.y=0;
    for (long i=1; i<=n; i++)
    {
        scanf("%lld%lld",&p.x,&p.y);
        ans+=kc(p,dau);
        ox[p.x+hs]++;
        oy[p.y+hs]++;
        if (p.x>0) phai++;
        if (p.x<0) trai++;
        if (p.y>0) tren++;
        if (p.y<0) duoi++;
    }
    //cout << duoi << " " << tren << " " << trai << " " << phai << endl;
    char s[3*100007];
    //cin >> s;
    scanf("%s",&s);
    for (long i=0; i<m; i++)
    {
        if (s[i]=='N')
        {
            ans=ans+duoi-tren+oy[hs+cy];
            duoi+=oy[hs+cy];
            cy++;
            tren-=oy[hs+cy];
        }
        else
        if (s[i]=='S')
        {
            ans=ans-duoi+tren+oy[hs+cy];
            tren+=oy[hs+cy];
            cy--;
            duoi-=oy[hs+cy];
        }
        else
        if (s[i]=='E')
        {
            ans=ans-phai+trai+ox[hs+cx];
            trai+=ox[hs+cx];
            cx++;
            phai-=ox[hs+cx];
        }
        else
        if (s[i]=='W')
        {
            ans=ans+phai-trai+ox[hs+cx];
            phai+=ox[hs+cx];
            cx--;
            trai-=ox[hs+cx];
        }
        cout << ans << '\n';
    }
}
