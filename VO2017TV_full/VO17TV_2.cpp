#include <bits/stdc++.h>
#define long long long
#define ull unsigned long long
#define up(i,a,b) for (int i=a; i<=b; i++)
#define down(i,a,b) for (int i=a; i>=b; i--)
#define endl '\n'
#define pb push_back
#define X first
#define Y second
#define II pair<int, int>
#define III pair<int, pair<int, int> >
#define V vector
#define debug(X) cerr<< #X << " = " <<X << endl
#define debug2(X,Y) cerr<< #X << " = " <<X << ","<<#Y<<" = "<<y<<endl
#define show(X,a,b) {cerr << #X << " = "; up(__,a,b) cerr << X[__] << ' '; cerr << endl;}
#define gc getchar
#define pc putchar
using namespace std;

inline void read(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeln(int x){

         char buffor[21];
         register int i=0;
         int neg=0; if (x<0) {neg=1; x= -x;}
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
           if (neg) pc('-');
           while(i>=0) pc(buffor[i--]);
           pc('\n');
       }
const int N= 55;
const int M= (int) 1e5+10;
const long base= (long) 1e9+ 7;
int n,k;
string s[N];
long H[N][M];
long Mu[M];
int lmax= 0;
II p[M];

void input()
{
    cin>>n>>k;
    up(i,1,n)
    {
        cin>>s[i]; s[i]= " "+ s[i]; lmax= max(lmax,(int)s[i].size()-1);
    }
}

long hash_range(int typ,int L,int R)
{
    return ((H[typ][R]- H[typ][L-1]* Mu[R-L+1])%base + base)%base;
}
void init()
{
    Mu[0]= 1;
    up(i,1,(int)1e5) Mu[i]= Mu[i-1]* 1333 % base;
    up(i,1,n)
    {
        up(j,1,(int)s[i].size()-1) H[i][j]= (H[i][j-1]* Mu[1] + s[i][j]- 'A'+1)% base;
    }
}
bool cmp(II a,II b)
{
    return a.X< b.X || (a.X== b.X and a.Y< b.Y);
}
bool query(int len)
{
    int cnt=0;
    up(i,1,n)
     up(j,1,(int)s[i].size()-len)
     {
         int id= hash_range(i,j,j+ len-1);
         p[++cnt]= II(id,i);
     }
    sort(p+1,p+1+cnt,cmp);
    p[0].X= -1; int q= 0;
    up(i,1,cnt)
    {
       if (p[i].X!= p[i-1].X) q= 1;
       else
       {
           if (p[i].Y!= p[i-1].Y) q++;
       }
       if (q>=k) return true;
    }
    return false;
}
void solve()
{
    init();
    int low,high,mid;
    low= 1; high= lmax;
    while (low<=high)
    {
        mid= (low+high)/2;
        if (query(mid)==true) low= mid+1; else high= mid-1;
    }
    cout<<low-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);// scanf phai bo
    #define TASK "vo17tv"
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);

    input();
    solve();

    return 0;
}
