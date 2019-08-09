#include <bits/stdc++.h>
#define nmax 100007
#define vc 9999999999

using namespace std;

long long n,q,aa[nmax],d[4*nmax],chainHead[nmax],chainInd[nmax],nChain,posInBase[nmax],nBase,parent[nmax],nChild[nmax],dd[nmax];
vector <long> a[nmax];

// nChain chuoi hien tai, sau khi ket thuc viec phan tach thi day se la tong so chuoi
// chainHead[c] dinh dau cua chuoi c
// chainInd[u] chuoi ma dinh u nam trong
// posInBase[u] la mang danh dau vi tri sau khi "trai" cac chuoi tren 1 duong thang

/*void dfs(long u)
{
    dd[u]=1;
    nChild[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i];
        if (dd[v]==0)
        {
            parent[v]=u;
            dfs(v);
            nChild[u]+=nChild[v];
        }
    }
}*/

void dfs(long u,long pivot)
{
    parent[u]=pivot;
    nChild[u]=1;
    for (long i=0; i<a[u].size(); i++)
    {
        long v = a[u][i];
        if(v!=pivot)
        {
            dfs(v,u);
            nChild[u]+=nChild[v];
        }
    }
}

void hld(long u)
{
	if (chainHead[nChain] == 0) chainHead[nChain] = u;
	chainInd[u] = nChain;
	posInBase[u] = ++nBase;
	long mxVtx = -1;

	for (long i = 0; i < a[u].size(); i++)
    {
		long v = a[u][i];
		if (v != parent[u])
           if (mxVtx == -1 || nChild[v] > nChild[mxVtx]) mxVtx = v;
	}
	if (mxVtx > -1) hld(mxVtx);

	for (int i = 0; i < a[u].size(); i++)
    {
		int v = a[u][i];
		if (v != parent[u] && v != mxVtx)
		  {
			nChain++;
			hld(v);
		  }
	}
}

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=aa[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=min(d[node*2],d[node*2+1]);

}

long long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return vc;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return min(x1,x2);
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=aa[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=min(d[id*2],d[id*2+1]);
}

long long gethld(long u)
{
    long uchain = chainInd[u], achain = chainInd[1];
    long long res=vc;
    while (true)
    {
        if (uchain == achain)
        {
            res=min(res,get(1,1,n,posInBase[1],posInBase[u]));
            return res;
        }
        res=min(res,get(1,1,n,posInBase[chainHead[uchain]],posInBase[u]));
        u = parent[chainHead[uchain]];
        uchain = chainInd[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("QTREE3.inp","r",stdin);
    freopen("QTREE3.out","w",stdout);
    cin >> n >> q;
    for (long i=1; i<n; i++)
      {
          long long u,v;
          cin >> u >> v;
          a[u].push_back(v);
          a[v].push_back(u);
      }
    nChain=1; nBase=0;
    dfs(1,0); hld(1);
    for (long i=1; i<=n; i++) aa[i]=vc;
    build(1,1,n);
    for (long i=1; i<=q; i++)
    {
        long tip,v;
        cin >> tip >> v;
        if (tip==0)
        {
            if (aa[posInBase[v]]==v) aa[posInBase[v]]=vc;
            else aa[posInBase[v]]=v;
            update(1,1,n,posInBase[v]);
        }
        else
        {
            long long ans=gethld(v);
            if (ans==vc) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
}
