#include <bits/stdc++.h>
#define nmax 10000007

using namespace std;

long long a[nmax],m,n,d[nmax],sau[nmax];
string s;

void build(long node,long L,long R)
{
    if (L==R)
    {
        d[node]=a[L];
        return;
    };
    long mid=(L+R) /2;
    build(node*2,L,mid);
    build(node*2+1,mid+1,R);
    d[node]=d[node*2]+d[node*2+1];
}

long get(long id,long L,long R,long u,long v)
{
    if ((L>=u) && (R<=v)) return d[id];
    if ((L>v) || (R<u)) return 0;
    long mid=(L+R) /2 ;
    long long x1=get(id*2,L,mid,u,v);
    long long x2=get(id*2+1,mid+1,R,u,v);
    return x1+x2;
}

void update(long id, long L, long R, long x)
{
    if ((L>x) || (R<x)) return;
    if (L==R)
    {
        d[id]=a[x];
        return;
    };
    long mid=(L+R) /2;
    update(id*2,L,mid,x);
    update(id*2+1,mid +1,R,x);
    d[id]=d[id*2]+d[id*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("PQUERY.inp","r",stdin);
    freopen("PQUERY.out","w",stdout);
    cin >> s;
    n=s.size();
    cin >> m;
    for (long i=0; i<n; i++)
      if (s[i]==')') a[i+1]=-1;
    else a[i+1]=1;
    a[n+1]=-1;
    build(1,1,n+1);

    for (long i=1; i<=m; i++)
    {
        char c; long k;
        cin >> c >> k;
        if (c=='C')
        {
            if (a[k]==-1)
            {
                a[k]=1;
                update(1,1,n+1,k);
            }
            else
            {
                a[k]=-1;
                update(1,1,n+1,k);
            }
        }
        else
        {
            if (a[k]==-1) cout << 0 << '\n';
            else
            {
                long vt=0;
                for (long j=k+1; j<=n+1; j++)
                   if (get(1,1,n+1,k,j)<0)
                     {
                           vt=j-1;
                           break;
                     }
                     //cout << get(1,1,n+1,3,9);
                 if (vt-k+1<0) cout << 0;
                 else cout << vt-k+1;
                 cout << '\n';
            }
        }
    }
}
