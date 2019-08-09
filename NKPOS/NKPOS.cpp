#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

long long n,m;
long a[10007][10007];

void euler(long uu)
{
    long v,x,top,dCE;
    long stack[MAX],CE[MAX];
    top=uu;
    stack[top]=uu;
    dCE=0;
    do
    {
       v=stack[top];
       x=uu;
       while (x<=n && a[v][x]==0) x++;
       if (x>n)
       {
          dCE++;
          CE[dCE]=v;
          top--;
       }
       else
       {
          top++;
          stack[top]=x;
          a[v][x]=0;
          a[x][v]=0;
       }
    }
    while(top!=0);
    cout << dCE-1 << endl;
    for (long i=1; i<=dCE; i++)
        cout<<CE[i]<<" ";
}


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("NKPOS.inp","r",stdin);
    freopen("NKPOS.out","w",stdout);
    cin >> n >> m; long long ts;
    for (long i=1; i<=n; i++) cin>>ts;
    for (long i=1; i<=m; i++)
    {
        long u,v;
        cin >> u >>v;
        a[u][v]=1;
        a[v][u]=1;
    }
    euler(1);
}
