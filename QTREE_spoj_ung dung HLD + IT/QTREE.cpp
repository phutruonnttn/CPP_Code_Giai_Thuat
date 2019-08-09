#include <bits/stdc++.h>
#define nmax 10007

using namespace std;
typedef pair <long,long> ii;

long long t,n,chainHead[nmax],chainInd[nmax],nChain,posInBase[nmax],nBase,parent[nmax],nChild[nmax],dd[nmax];
vector <ii> a[nmax];

// nChain chuoi hien tai, sau khi ket thuc viec phan tach thi day se la tong so chuoi
// chainHead[c] dinh dau cua chuoi c
// chainInd[u] chuoi ma dinh u nam trong
// posInBase[u] la mang danh dau vi tri sau khi "trai" cac chuoi tren 1 duong thang

void dfs(long u)
{
    dd[u]=1;
    nChild[u]=0;
    for (long i=0; i<a[u].size(); i++)
    {
        long v=a[u][i].first;
        if (dd[v]==0)
        {
            nChild[u]++;
            parent[v]=u;
            dfs(v);
        }
    }
}

void hld(long u)
{
	if (chainHead[nChain] == 0) chainHead[nChain] = u;
	chainInd[u] = nChain;
	posInBase[u] = ++nBase;
	long mxVtx = -1;

	for (int i = 0; i < a[u].size(); i++)
    {
		long v = a[u][i].first;
		if (v != parent[u])
           if (mxVtx == -1 || nChild[v] > nChild[mxVtx]) mxVtx = v;
	}
	if (mxVtx > -1) hld(mxVtx);

	for (int i = 0; i < a[u].size(); i++)
    {
		int v = a[u][i].first;
		if (v != parent[u] && v != mxVtx)
		  {
			nChain++;
			hld(v);
		  }
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("QTREE.inp","r",stdin);
    freopen("QTREE.out","w",stdout);
    cin >> t;
    while (t--)
    {
         cin >> n;
         for (long i=1; i<n; i++)
         {
             long long u,v,w;
             cin >> u >> v >> w;
             a[u].push_back(ii(v,w));
             a[v].push_back(ii(u,w));
         }
         nChain=1; nBase=0;
         memset(chainHead,0,sizeof(chainHead));
         memset(dd,0,sizeof(dd));
         dfs(1); hld(1);
         for (long i=1; i<=n; i++)
            cout << i << " " << posInBase[i] << endl;
    }
}
