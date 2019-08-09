
// SOLUION 70%
/*
#include<bits/stdc++.h>
#define nmax 100005
#define M 1000000007
#define M2 (long long)M*M
#define B 37
using namespace std;
int n;
long long h[nmax],a[nmax],b[nmax];
typedef pair<int,int> ii;
map <int,ii> mymap;
string s1,s2;
long long geta(int l,int r)
{
    if (l==0) return a[r];
    long long x=(a[r]-a[l-1]*h[r-l+1] + M2) % M;
    return x;
}
long long getb(int l,int r)
{
    if (l==0) return b[r];
    long long x=(b[r]-b[l-1]*h[r-l+1] + M2) % M;
    return x;
}

int main()
{
    freopen("adn.inp","r",stdin);
    freopen("adn.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>s1;
    cin>>s2;
    int n=s1.size()*2;
    int n1=n/2;
    h[0]=1;
    for (int i=1;i<=n;i++) h[i]=(h[i-1]*B) % M;
    //______________________________________________
    s1=s1+s1;
    a[0]=s1[0];
    for (int i=1;i<n;i++) a[i] = (a[i-1]*B + s1[i]) % M;
    s2=s2+s2;
    b[0]=s2[0];
    for (int i=1;i<n;i++) b[i] = ( b[i-1]*B + s2[i]) % M;
    //_____________________________________________
    for (int i=1;i<=n1;i++)
         for (int j=0;j<=n-i;j++)
    {
        long long x1=geta(j,j+i-1);
        mymap[x1]= make_pair(j,i+j-1);
    }
    //______________________________________________

    long long dem=0;
    pair <int,int> p,kq,kq2;
    p=mymap[0];
    for (int i=1;i<=n1;i++)
        for (int j=0;j<=n-i;j++)
    {
        if (i<dem) continue;
        long long x1=getb(j,j+i-1);
        p=mymap[x1];
        if (p.first==0 && p.second==0) continue;
        dem=i;
        kq=p;
        kq2=make_pair(j,j+i-1);
    }
    int answer=kq.second-kq.first+1;
    cout<<answer<<endl;
    int tmp1=n/2-answer;
    string res1=s1.substr(kq.first-tmp1,tmp1) + s1.substr(kq.first,answer);
    cout<<res1<<endl;
    string res2=s2.substr(kq2.first-tmp1,tmp1) + s2.substr(kq2.first,answer);
    cout<<res2<<endl;
}
*/
//_________90
/*
#include<bits/stdc++.h>
#define nmax 100005
#define M 1000000007
#define M2 (long long)M*M
#define B 137
using namespace std;
typedef pair<int,int> ii;
string s1,s2;
int n,n1;
long long h[nmax],a[nmax],b[nmax];
ii kq1,kq2;
int geta(int l,int r)
{
    if (l==0) return a[r];
    int x=(a[r] - a[l-1]*h[r-l+1] +M2) % M;
    return x;
}
int getb(int l,int r)
{
    if (l==0) return b[r];
    int x=(b[r]-b[l-1]*h[r-l+1] + M2) % M;
    return x;
}
bool kt(int m)
{
    map <int,ii> mymap;
    for (int i=0;i<n1;i++)
    {
        int x1=geta(i,i+m-1);
        mymap[x1]=make_pair(i,i+m-1);
    }
    ii p;
    for (int i=0;i<n1;i++)
    {
        int x1=getb(i,i+m-1);
        p=mymap[x1];
        if (p.first==0 && p.second==0) continue;
        if (s1.substr(p.first,m)==s2.substr(i,m))
        {
              kq1=p;
              kq2=make_pair(i,i+m-1);
              return true;
        }
    }
    return false;
}
int main()
{
    freopen("adn.inp","r",stdin);
    freopen("adn.out","w",stdout);
    ios_base::sync_with_stdio(0);

    cin >> s1;
    cin >> s2;
    n = s1.size()*2;
    n1 = n/2;
    h[0] = 1;
    long long tmp;
    for (int i=1; i<=n; i++) h[i]=(h[i-1]*B) % M;
    //__________________________________________
    s1=s1+s1;
    a[0]=s1[0];
    for (int i=1;i<n;i++)  a[i]= (a[i-1]*B + s1[i]) % M;

    s2=s2+s2;
    b[0]=s2[0];
    for (int i=1;i<n;i++) b[i] = ( b[i-1]*B + s2[i]) % M;
    //____________________________________________

    int l = 1, r = n1,ans;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (kt(m)) {l=m+1;ans=m;}
        else
            r=m-1;
    }
    s1=s1+s1;
    s2=s2+s2;
    if (kq1.first==0 && kq1.second==0) ans=0;
    cout << ans << endl;

    int tmp1 = n1-ans;
    string res1=s1.substr(kq1.first+n1-tmp1,tmp1) + s1.substr(kq1.first+n1,ans);
    cout << res1 << endl;

    string res2=s2.substr(kq2.first+n1-tmp1,tmp1) + s2.substr(kq2.first+n1,ans);
    cout<<res2<<endl;
}  */
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 50004
#define base 97

using namespace std;

const long long mm = 1ll * maxc * maxc;
long long h[2*maxn], sa[2*maxn], sb[2*maxn];
string a, b;
int n;
map <int, int> m;

int geta(int u, int v)
{
    return (sa[v] - sa[u-1] * h[v-u+1]);
}

int getb(int u, int v)
{
    return (sb[v] - sb[u-1] * h[v-u+1]);
}
bool check(int leng)
{
    for (int i=1 ; i<=n ; i++)
{
        int x = geta(i, i+leng-1);
        m[x] = i;
    }
    for (int i=1 ; i<=n ; i++)
    {
        int y = getb(i, i+leng-1);
        if (m[y] && a.substr(m[y], leng) == b.substr(i, leng)) return 1;
    }
    return 0;
}

void ghikq(int leng, int i, int j)
{
    cout << a.substr(i+leng, n-leng) << a.substr(i, leng) << '\n';
    cout << b.substr(j+leng, n-leng) << b.substr(j, leng) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("adn.inp","r",stdin);
    freopen("adn.out","w",stdout);
    cin >> a >> b;
    n = a.length();
    a = " " + a + a;
    b = " " + b + b;
    h[0] = 1;
    for (int i=1 ; i<=2*n ; i++){
        h[i] = h[i-1] * base;
        sa[i] = (sa[i-1] * base + a[i]);
        sb[i] = (sb[i-1] * base + b[i]);
    }
    int l = 0;
    int r = n + 1;
    while (r - l > 1)
    {
        m.clear();
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
            else r = mid;
    }
    cout << l << '\n';
    for (int i = 1; i <= n; i++)
    {
        int x = geta(i, i+l-1);
        m[x] = i;
    }
    for (int i=1 ; i<=n ; i++)
    {
        int y = getb(i, i+l-1);
        if (m[y] && a.substr(m[y], l) == b.substr(i, l)){
            ghikq(l, m[y], i);
            return 0;
        }
    }
    return 0;
}

