#include <bits/stdc++.h>
#define nmax 100007

using namespace std;

long long n,k,a[nmax],a1[nmax],dd[nmax],ans=0,d[5*nmax];

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=a1[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=max(d[node*2],d[node*2+1]);

}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return -1;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return max(x1,x2);
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=a1[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=max(d[id*2],d[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("dolls.inp","r",stdin);
    freopen("dolls.out","w",stdout);
    //cin >> n >> k;
    scanf("%lld%lld",&n,&k);
    for (long i=1; i<=n; i++) {scanf("%lld",&a[i]); ans+=a[i];}
    sort(a+1,a+n+1);

    for (long i=1; i<=n; i++) a1[i]=i;
    build(1,1,n);

    //for (long i=1; i<=n; i++) cout << a[i] << " "; cout << endl;

    for (long i=n; i>=1; i--)
       if (dd[i]==0)
       {
           dd[i]=1;
           a1[i]=0;
           update(1,1,n,i);
           long j=lower_bound(a+1,a+n+1,a[i]-k)-a;
           if (a[j]>a[i]-k && j>0) j--;
           //cout << a[i] << " ";
           while (j>0)
             {
                 //while (dd[j]==1 && j>0) j--;
                 if (j==0) break;
                 j=get(1,1,n,1,j);
                 ans-=a[j];
                 dd[j]=1;
                 a1[j]=0;
                 update(1,1,n,j);
                 //cout << a[j] << " ";
                 long nho=j;
                 j=lower_bound(a+1,a+n+1,a[nho]-k)-a;
                 if (a[j]>a[nho]-k && j>0) j--;
                 if (j==0) break;
             }
           //cout << endl;
       }
    //cout << ans;
    printf("%lld",ans);
}
