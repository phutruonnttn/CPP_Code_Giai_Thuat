#include <bits/stdc++.h>
#define nmax 2007

using namespace std;

long long a[nmax][nmax],m,n,k,x1[nmax],x2[nmax],y11[nmax],y2[nmax],rrx[2*nmax],rry[2*nmax];
vector <long long> v;
int dd[nmax][nmax],k1[7]={0,0,1,-1},k2[7]={1,-1,0,0};

void batbit(long k,long long &x)
{
    x=x|((long long)1<<k);
}

void danhdau(long p,long long x1, long long y11, long long x2, long long y2)
{
     for (long i=min(y11,y2); i<=max(y11,y2)-1; i++)
        for (long j=min(x1,x2); j<=max(x1,x2)-1; j++)
           batbit(p,a[i][j]);
}

void dfs(long i, long j)
{
    dd[i][j]=0;
    for (long k=0; k<=3; k++)
    {
        long u=i+k1[k],v=j+k2[k];
        if (dd[u][v]==-1 && a[u][v]==a[i][j]) dfs(u,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Cake.inp","r",stdin);
    freopen("Cake.out","w",stdout);
    while (1<2)
    {
        cin >> m >> n;
        if (m==0 && n==0) break;
        long dem=0;
        rrx[++dem]=n; rry[dem]=m;
        cin >> k;
        for (long i=1; i<=k; i++)
        {
            cin >> x1[i] >> y11[i] >> x2[i] >> y2[i];
            rrx[++dem]=x1[i]; rry[dem]=y11[i];
            rrx[++dem]=x2[i]; rry[dem]=y2[i];
        }

        rrx[++dem]=0; rry[dem]=0;

        v.clear();
        v.assign(rrx+1,rrx+dem+1);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());

        for (long i=1; i<=dem; i++)
           rrx[i]=lower_bound(v.begin(),v.end(),rrx[i])-v.begin()+1;

        v.clear();
        v.assign(rry+1,rry+dem+1);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());

        for (long i=1; i<=dem; i++)
           rry[i]=lower_bound(v.begin(),v.end(),rry[i])-v.begin()+1;

        dem=1;
        n=rrx[1]; m=rry[1];
        for (long i=1; i<=k; i++)
        {
            x1[i]=rrx[++dem]; y11[i]=rry[dem];
            x2[i]=rrx[++dem]; y2[i]=rry[dem];
        }

        /*cout << m << " " << n << endl;
        for (long i=1; i<=k; i++)
          cout << x1[i] << " " << y11[i] << " " << x2[i] << " " << y2[i] << endl;
        cout << endl;*/

        for (long i=1; i<=m-1; i++)
           for (long j=1; j<=n-1; j++)
             {a[i][j]=0; dd[i][j]=-1;}
        for (long i=1; i<=k; i++)
           danhdau(i,x1[i],y11[i],x2[i],y2[i]);

        /*for (long i=1; i<=m-1; i++)
        {
           for (long j=1; j<=n-1; j++)
             cout << a[i][j] << " ";
           cout << endl;
        }*/

        long long ans=0;
        for (long i=1; i<=m-1; i++)
           for (long j=1; j<=n-1; j++)
             if (dd[i][j]==-1) {ans++; dfs(i,j);}
        cout << ans << '\n';
    }
}
