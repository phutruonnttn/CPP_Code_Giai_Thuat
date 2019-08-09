#include <bits/stdc++.h>

using namespace std;

struct data
{
    long x,y,sl,id;
};

long n,k,vtri[300007];
long long f[300007],maxx[300007],maxy[300007],tr[300007],vtmx,vtmy;
data tv[300007];

bool comp(data p, data q)
{
    if (p.x!=q.x) return p.x < q.x;
    if (p.y!=q.y) return p.y < q.y;
}

void update(long i)
{
    maxx[tv[i].x]=max(f[i],maxx[tv[i].x]);

    /*if (f[i]<maxx[tv[i].x])
    {
        maxx[tv[i].x]=
    }*/

    maxy[tv[i].y]=max(f[i],maxy[tv[i].y]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("Barica.inp","r",stdin);
    freopen("Barica.out","w",stdout);
    cin >>n >> k;
    for (long i=1; i<=n; i++)
        cin >> tv[i].x >> tv[i].y >> tv[i].sl;
    memset(f,0,sizeof(f));
    memset(maxx,0,sizeof(maxx));
    memset(maxy,0,sizeof(maxy));

    f[1]=tv[1].sl; update(1);

    for (long i=1; i<=n; i++) tv[i].id=i;

    sort(tv+1,tv+n+1,comp);

    for (long i=1; i<=n; i++) vtri[tv[i].id]=i;

    /*for (long i=1; i<=n; i++)
        cout << tv[i].x << " " << tv[i].y << " " << tv[i].sl << " " << tv[i].id << endl;*/

    for (long i=vtri[1]+1; i<=vtri[n]; i++ )
    {
         if (maxx[tv[i].x]>=k) f[i]=max(f[i],maxx[tv[i].x]+tv[i].sl-k);
         if (maxy[tv[i].y]>=k) f[i]=max(f[i],maxy[tv[i].y]+tv[i].sl-k);
         update(i);
    }
    cout << f[vtri[n]];
    //for (long i=vtri[1]; i<=vtri[n]; i++) cout << f[i] << " ";
}
