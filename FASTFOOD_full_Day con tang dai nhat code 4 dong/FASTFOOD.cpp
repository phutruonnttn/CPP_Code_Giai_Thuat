#include <bits/stdc++.h>
#define nmax 1507

using namespace std;
typedef pair <long,long> ii;

long long n,k[2*nmax-1],f[nmax*nmax],fd[nmax*nmax],c[nmax*nmax],dd[nmax*nmax],b[nmax*nmax],x1[nmax*nmax],a[nmax*nmax],ans1,ans2;
vector <ii> x[nmax*nmax];

/*long tinh1(long u, long v)
{
    ans1=0;
    for (long i=u; i<=v; i++)
    {
        if (a[i]>a[v]) continue;
        if (a[i]>=a[x1[ans1]])
        {
            ++ans1;
            x1[ans1]=i;
        }
        else
        {
            long l=0, r=ans1;
            while (r-l>1)
            {
                long g=(l+r)/2;
                if (a[x1[g]]<=a[i]) l=g;
                else r=g;
            }
            x1[r]=i;
        }
    }
    return ans1;
}

long tinh2(long u, long v)
{
    ans2=0;
    for (long i=u; i<=v; i++)
    {
        if (a[i]<a[u]) continue;
        if (a[i]>=a[x1[ans2]])
        {
            ++ans2;
            x1[ans2]=i;
        }
        else
        {
            long l=0, r=ans2;
            while (r-l>1)
            {
                long g=(l+r)/2;
                if (a[x1[g]]<=a[i]) l=g;
                else r=g;
            }
            x1[r]=i;
        }
    }
    return ans2;
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("FASTFOOD.inp","r",stdin);
    freopen("FASTFOOD.out","w",stdout);
    cin >> n;
    for (long i=1; i<=n; i++)
      for (long j=1; j<=n; j++)
       {long u; cin >> u; x[u].push_back(ii(i,j));dd[u]=1;}
    long dem=0;
    for (long i=1; i<=n*n; i++)
       if (dd[i]==1) b[++dem]=i;
    for (long i=1; i<=dem; i++)
       sort(x[b[i]].begin(),x[b[i]].end());
    /*for (long i=0; i<x[1].size(); i++)
      cout << x[1][i].first << " "; cout << endl;
    for (long i=0; i<x[1].size(); i++)
      cout << x[1][i].second << " ";*/
    for (long i=1; i<=dem; i++)
    {
       for (long j=0; j<x[b[i]].size(); j++)
         a[j+1]=x[b[i]][j].second;
       /*for (long j=1; j<=x[b[i]].size(); j++)
         k[tinh1(1,j)+tinh2(j,x[b[i]].size())-1]++;*/
//----------------------------------------
//DAY CON KHONG GIAM DAI NHAT KET THUC TAI J (PHAI LAY A[J])
       long long m=0;
       for(long j=1; j<=x[b[i]].size(); ++j) c[j]=0;
       for(long j=1; j<=x[b[i]].size(); ++j)
       {
           f[j]=upper_bound(c+1,c+m+1,a[j])-c;
           m=max(f[j],m);
           c[f[j]]=a[j];
       }
//----------------------------------------
       m=0;
       for(long j=1; j<=x[b[i]].size(); ++j) c[j]=0;
       for(long j=x[b[i]].size(); j>=1; --j)
       {
           fd[j]=upper_bound(c+1,c+m+1,-a[j])-c;
           m=max(fd[j],m);
           c[fd[j]]=-a[j];
       }

       for (long j=1; j<=x[b[i]].size(); ++j)
          k[f[j]+fd[j]-1]++;
    }
    for (long i=1; i<=2*n-1; i++) cout << k[i] << '\n';
}
