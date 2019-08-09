#include <bits/stdc++.h>
#define mmax 1000007
#define nmax 1000007
#define maxn 1000007

using namespace std;

struct data
{
    long long l,r,id;
};

struct dt1
{
    long long gt,id;
};

long long m,n,rr[4*nmax],root[maxn],h[maxn],dad[maxn],ans,dem;
bool ok;
dt1 roirac[2*nmax];
data aa[nmax],a[nmax];
vector <long long> v;

bool comp(dt1 p, dt1 q)
{
    if (p.gt!=q.gt) return p.gt < q.gt;
}

long long get_root(long long u)
{
    return (root[u]) ? root[u] = get_root(root[u]) : u;
}

void danhdau(long long u, long long p)
{
    //if (get_root[p]!=p) {ans--; return;}
    //if (get_root[u]!=u) {ans--; return;}
    long long r = get_root(p),r1=get_root(u);
    if (r!=p) {if (ok) ans--;ok=false;/*cout <<dem << endl; return;*/}
    if (r1!=u) {if (ok) ans--;ok=false;/*cout <<dem << endl; return;*/}
    u = get_root(u);
    while (h[u] > h[r])
     {
        if (root[u]!=0)
        {
            if (ok) ans--;//cout <<dem << endl;
            /*for (long i=0; i<daxet[dem].size(); i++)
               root[i]=0;*/
            ok=false;
        }
        root[u] = r;
        u = get_root(dad[u]);
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("os.inp","r",stdin);
    freopen("os.out","w",stdout);
    cin >> m >> n;
    long long sl=0;
    for (long long i=1; i<=n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].id=i;
        roirac[++sl].gt=a[i].l; roirac[sl].id=i;
        roirac[++sl].gt=a[i].r; roirac[sl].id=i;
    }
    roirac[++sl].gt=m; roirac[sl].id=n+1;
    sort(roirac+1,roirac+sl+1,comp);

    for (long long i=1; i<=sl; i++)
        rr[i]=roirac[i].gt;

    v.assign(rr + 1, rr + sl + 1);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (long long i=1;i<=sl;i++)
         roirac[i].gt=lower_bound(v.begin(),v.end(),roirac[i].gt)-v.begin()+1;

    for (long long i=1; i<=sl; i++)
    {
        if (aa[roirac[i].id].l==0)
            aa[roirac[i].id].l=roirac[i].gt;
        else aa[roirac[i].id].r=roirac[i].gt;
    }
    ans=n;

    /*for (long long i=1; i<=n; i++)
        cout << aa[i].l << " " << aa[i].r << endl;
    cout << endl;*/

    long long demm=0;
    m=roirac[sl].gt;
    for (long long i=m-1; i>=1; i--)
        {
            h[i]=++demm;
            dad[i]=i+1;
        }
    dem=0;
    for (long long i=n; i>=1; i--)
    {
        ++dem;
        ok=true;
        long long u=aa[i].l, v=aa[i].r;
        long p=(u+v)/2;
        if (u>v) swap(u,v);
        if (ok && root[p]!=0)
        {
            ans--;
            ok=false;
        }
        if (ok && root[u]!=0)
        {
            ans--;
            ok=false;
        }
        if (ok && root[v]!=0)
        {
            ans--;
            ok=false;
        }
        danhdau(u,p);
        danhdau(p,v);
        //danhdau(u,v);
        if (root[u]==0) root[u]=-1;
        if (root[p]==0) root[p]=-1;
        if (root[v]==0) root[v]=-1;
        //for (long long j=1; j<=m; j++) cout << root[j] << " "; cout << endl;
    }
    cout << ans;
}
