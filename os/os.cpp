#include <bits/stdc++.h>
#define mmax 1000007
#define nmax 1000007

using namespace std;

struct data
{
    long long l,r,id;
};

struct dt1
{
    long long gt,id;
};

long long m,n,mt[mmax],dmax[4*mmax],tmax[4*mmax],rr[4*nmax];
dt1 roirac[2*nmax];
data aa[nmax],a[nmax];
vector <long long> v;

long long getmax(long long id,long long L,long long R,long long u,long long v)
{
    //if ((L>v) || (R<u)) return -1;
    if ((L>=u) && (R<=v)) return dmax[id];
    if ((L>v) || (R<u)) return -1;
    long long mid=(L+R) /2 ;
    long long x1=getmax(id*2,L,mid,u,v);
    long long x2=getmax(id*2+1,mid+1,R,u,v);
    return max(x1,x2)+tmax[id];
}

void updatem(long long id, long long L, long long R, long long u, long long v,long long w)
{
    if ((L>v) || (R<u)) return;
    if (L>=u && R<=v)
    {
        tmax[id]+=w;
        dmax[id]+=w;
        return;
    };
    long long mid=(L+R) /2;
    updatem(id*2,L,mid,u,v,w);
    updatem(id*2+1,mid +1,R,u,v,w);
    dmax[id]=max(dmax[id*2],dmax[id*2+1]) +tmax[id];
}

bool comp(dt1 p, dt1 q)
{
    if (p.gt!=q.gt) return p.gt < q.gt;
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

    long long maxx=roirac[sl].gt;

    long long ans=0;
    for (long long i=n; i>=1; i--)
    {
        if (getmax(1,1,maxx,aa[i].l,aa[i].r)==0)
        {
            ans+=1;
            //updatem(1,1,maxx,aa[i].l,aa[i].r,1);
        }
        updatem(1,1,maxx,aa[i].l,aa[i].r,1);
    }
    cout << ans;
}
